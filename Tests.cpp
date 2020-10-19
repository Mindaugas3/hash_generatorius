//
// Created by Mindaugas on 2020-10-08.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ctime>
#include <functional>
#include "Tests.h"
#include "sha256.h"

using namespace std;

float Tests::BinaryDifference(Converter conv1, Converter conv2) {
    int BitDiffPercent = 0;
    vector<byte> firstVector = conv1.getOutput();
    vector<byte> secondVector = conv2.getOutput();
    vector<byte> diff;
    set_difference(firstVector.begin(), firstVector.end(), secondVector.begin(), secondVector.end(),
                        inserter(diff, diff.begin()));
    float percent = (float) diff.size() / firstVector.size();
    cout << "Baitu vektoriai skiriasi per: " << diff.size() << " elementu. Is viso elementu vektoriuose: " << firstVector.size() <<
    ". Procentinis skirtumas: " << percent << endl;
    return percent;
}

float Tests::HexDifference(Converter conv1, Converter conv2) {
    vector<byte> firstVector = conv1.getOutput();
    vector<byte> secondVector = conv2.getOutput();
    stringstream first, second;
    for(byte b : firstVector){
        first << std::hex << static_cast<int>(b);
    }
    for(byte b : secondVector){
        second << std::hex << static_cast<int>(b);
    }
    string diff;
    string string_F = first.str();
    string string_S = second.str();
    set_difference(string_F.begin(), string_F.end(), string_S.begin(), string_S.end(),
                   inserter(diff, diff.begin()));
    float percent = (float) diff.size() / string_F.size();
    cout << "Hexas skiriasi per: " << diff.size() << " elementu. Procentinis skirtumas" << percent << "% " << endl;
    return percent;
}

void Tests::generateSymbols1000() {
    ofstream testFile("1000simboliu.txt");
    srand(time(NULL));
    for(int i = 0; i < 1000; i++){
        char randomChar = (rand() % 26) + 'a';
        testFile <<  randomChar;
    }
    testFile.close();
}

void Tests::checkCollission(vector<string> allHashes) {
    int collission = 0;
    for(string hashCode : allHashes){
        int num = std::count(allHashes.begin(), allHashes.end(), hashCode);
        if(num > 1){
            cout << "Kolizija surasta: " << hashCode << ", kartojasi: "<< num
            << " kartu "<<endl;
            collission++;
        }
    }
    cout << "Is viso koliziju: " << collission << " is 100000\n";
}

void Tests::compareTwo(Converter conv1, Converter conv2) {
    BinaryDifference(conv1, conv2);
    HexDifference(conv1, conv2);
}

void Tests::generatePairs(ofstream& basicOfstream, int length) {
    auto gen = std::bind(std::uniform_int_distribution<>(0,26),std::default_random_engine(time(NULL)));
    for(int j = 0; j < 25000; j++){
        for(int i = 0; i < length; i++){
            char randomChar = gen() + 'a';
            if(i == length/2){
                basicOfstream << ' ';
            } else {
                basicOfstream << randomChar;
            }
        }
        basicOfstream << "\n";
    }
}

void Tests::makePairsFiles() {
    ofstream pairsFile("poros.txt");
    generatePairs(pairsFile, 10);
    generatePairs(pairsFile, 100);
    generatePairs(pairsFile, 500);
    generatePairs(pairsFile, 1000);
    pairsFile.close();
}

void Tests::MeasureSha256(string value) {
    sha256(value);
}

void Tests::generatePairsDiff() {
    ofstream similiarPairsFile("panasios_poros.txt");
    makePairsSimiliar(similiarPairsFile, 10);
    makePairsSimiliar(similiarPairsFile, 100);
    makePairsSimiliar(similiarPairsFile, 500);
    makePairsSimiliar(similiarPairsFile, 1000);
    similiarPairsFile.close();
}



void Tests::makePairsSimiliar(ofstream &file, int length) {
    auto gen = std::bind(std::uniform_int_distribution<>(0,26),std::default_random_engine(time(NULL)));

    for(int j = 0; j < 25000; j++){

        stringstream first;
        string second;

        for(int i = 0; i < length/2; i++){
            char randomChar = gen() + 'a';
            first << randomChar;
        }

        file << first.str();
        file << " ";
        second = first.str();
        do {
            auto pickRandom = std::bind(std::uniform_int_distribution<>(0, second.length() - 1),
                                        std::default_random_engine(time(NULL)));
            second[rand() % second.length()] = gen() + 'a';
        } while (second == first.str());
        file << second;
        file << "\n";
    }
}

void Tests::checkDiff(vector<pair<Converter, Converter>> allPairs) {
    vector<float> totalHexDiff;
    vector<float> totalBinaryDiff;
    for(pair<Converter, Converter> comparable : allPairs){
        totalHexDiff.push_back(HexDifference(comparable.first, comparable.second));
        totalBinaryDiff.push_back(BinaryDifference(comparable.first, comparable.second));
    }

    float binaryDiff = 0.0f;
    binaryDiff = accumulate(totalBinaryDiff.begin(), totalBinaryDiff.end(), 0.0) / totalBinaryDiff.size();

    float hexDiff = 0.0f;
    hexDiff = accumulate(totalHexDiff.begin(), totalHexDiff.end(), 0.0) / totalHexDiff.size();

    cout << "Galutinis procentinis skirtingumas bitu lygmenyje: " << binaryDiff*100 << "% " << endl
    << "Galutinis procentinis skirtingumas hexu lygmenyje: " << hexDiff*100 << "% " << endl;
}



