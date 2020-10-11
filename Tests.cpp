//
// Created by Mindaugas on 2020-10-08.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ctime>
#include "Tests.h"

using namespace std;

void Tests::BinaryDifference(Converter conv1, Converter conv2) {
    int BitDiffPercent = 0;
    vector<byte> firstVector = conv1.getOutput();
    vector<byte> secondVector = conv2.getOutput();
    vector<byte> diff;
    set_difference(firstVector.begin(), firstVector.end(), secondVector.begin(), secondVector.end(),
                        inserter(diff, diff.begin()));
    cout << "Baitu vektoriai skiriasi per: " << diff.size() << " elementu. Is viso elementu vektoriuose: " << firstVector.size() << endl;
}

void Tests::HexDifference(Converter conv1, Converter conv2) {
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
    cout << "Hexas skiriasi per: " << diff.size() << " elementu." << endl;

}

Tests::Tests()= default;

void Tests::generateSymbols1000() {
    ofstream testFile("1000simboliu.txt");
    srand(time(NULL));
    for(int i = 0; i < 1000; i++){
        char randomChar = (rand() % 26) + 'a';
        testFile <<  randomChar;
    }
    testFile.close();
}

void Tests::checkCollission() {
    //TODO
}

void Tests::compareTwo(Converter conv1, Converter conv2) {
    BinaryDifference(conv1, conv2);
    HexDifference(conv1, conv2);
}

void Tests::generatePairs10() {

}

void Tests::generatePairs100() {

}

void Tests::generatePairs500() {

}

void Tests::generatePairs1000() {

}



