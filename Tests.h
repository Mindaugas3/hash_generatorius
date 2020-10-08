//
// Created by Mindaugas on 2020-10-08.
//

#ifndef HASH_GENERATORIUS_TESTS_H
#define HASH_GENERATORIUS_TESTS_H


#include "Converter.h"
#include <vector>

class Tests {
private:
    Converter conv1, conv2;
public:
    Tests(Converter conv1, Converter conv2);
    void BinaryDifference();
    void HexDifference();
};


#endif //HASH_GENERATORIUS_TESTS_H
