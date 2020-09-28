//
// Created by Mindaugas on 2020-09-27.
//


#ifndef DEFAULT_HASH_LENGTH
#define DEFAULT_HASH_LENGTH 12
#define SEED 127

#include <string>

using namespace std;

class Converter {
private:
    string input;
    string output;

public:
    Converter(string in);
    string getOutput();

};


#endif