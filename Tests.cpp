//
// Created by Mindaugas on 2020-10-08.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include "Tests.h"

using namespace std;

void Tests::BinaryDifference() {
    int BitDiffPercent = 0;
    vector<byte> firstVector = conv1.getOutput();
    vector<byte> secondVector = conv2.getOutput();
    vector<byte> diff;
    //not need to sort since it already sorted
    set_difference(firstVector.begin(), firstVector.end(), secondVector.begin(), secondVector.end(),
                        inserter(diff, diff.begin()));
    cout << "Bitu vektoriai skiriasi per: " << diff.size() << " elementu. Is viso elementu vektoriuose: " << firstVector.size() << endl;
}

void Tests::HexDifference() {
    vector<byte> firstVector = conv1.getOutput();
    vector<byte> secondVector = conv2.getOutput();
    stringstream first, second;
    for(byte b : firstVector){
        first << std::hex << static_cast<int>(b);
    }
    for(byte b : secondVector){
        second << std::hex << static_cast<int>(b);
    }
    string diff = "";
    string string_F = first.str();
    string string_S = second.str();
    set_difference(string_F.begin(), string_F.end(), string_S.begin(), string_S.end(),
                   inserter(diff, diff.begin()));
    cout << "Hexas skiriasi per: " << diff.size() << " elementu." << endl;

}

Tests::Tests(Converter conv1, Converter conv2) : conv1(conv1), conv2(conv2) {
    BinaryDifference();
    HexDifference();
}



