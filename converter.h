//
// Created by Mindaugas on 2020-09-27.
//


#ifndef DEFAULT_HASH_LENGTH
#define DEFAULT_HASH_LENGTH 16
#define SEED 5381
#define TEST
#define ALGORITHM_TEST

#include <string>
#include <bitset>
#include <vector>
#include <exception>

using namespace std;

typedef uint8_t byte; //uint8_t turi 256 reiksmes, taigi 2^8 (realiai tas pats kas 1 baitas)
//minetos reiksmes gali prasideti tik nuo 0
static vector<uint8_t> valuesList = { 34, 123, 252, 0, 11, 52, 114, 25, 87, 0, 11, 16, 45, 77, 13, 7, 49, 54 };

//
static const char hexCharset[] =
        "0123456789ABCDEF"; //16-taines sistemos

static const size_t max_index = (sizeof(valuesList) - 1);

//



class Converter {
private:
    string input;
    string output;

public:
    Converter(string in);
    string getOutput();

//    static string asHex(const std::vector<uint8_t> &input);
    static byte operations(byte item, byte val);
    static vector<byte> TrimAndFill(vector<byte> ivec);
};


#endif