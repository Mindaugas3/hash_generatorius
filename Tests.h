//
// Created by Mindaugas on 2020-10-08.
//

#ifndef HASH_GENERATORIUS_TESTS_H
#define HASH_GENERATORIUS_TESTS_H


#include "Converter.h"
#include <vector>



class Tests { //klase skirta failu dvejetainio ir sesioliktainio skirtumu palyginimui ir taip pat simboliu generavimui
private:

public:
    static void compareTwo(Converter conv1, Converter conv2);
    static float BinaryDifference(Converter conv1, Converter conv2);
    static float HexDifference(Converter conv1, Converter conv2);
    static void generateSymbols1000();
    static void generatePairs(ofstream& basicOfstream, int length);
    static void checkCollission(vector<string> allHashes);
    static void makePairsFiles();
    static void MeasureSha256(string value);
    static void generatePairsDiff();
    static void makePairsSimiliar(ofstream& file, int length);
    static void checkDiff(vector<pair<Converter, Converter>> allPairs);
};


#endif //HASH_GENERATORIUS_TESTS_H
