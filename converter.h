//
// Created by Mindaugas on 2020-09-27.
//


#ifndef DEFAULT_HASH_LENGTH
#define DEFAULT_HASH_LENGTH 12
#define SEED 127
#define TEST

#include <string>
#include <bitset>

using namespace std;

typedef bitset<8> byte;

class Converter {
private:
    string input;
    string output;

public:
    Converter(string in);
    string getOutput();

};


#endif