//
// Created by Mindaugas on 2020-09-27.
//


#ifndef DEFAULT_HASH_LENGTH
#define DEFAULT_HASH_LENGTH 16

#include <string>
#include <bitset>
#include <vector>
#include <exception>

using namespace std;

typedef uint8_t byte;
static vector<uint8_t> valuesList = { 34, 123, 252, 0, 11, 52, 114, 25, 87, 0, 11, 16, 45, 77, 13, 7, 49, 54 };


static const char hexCharset[] = "0123456789ABCDEF"; //16-taines sistemos

static const size_t max_index = valuesList.size() - 1;


class Converter {
private:
    vector<byte> output;

public:
    explicit Converter(string input);
    Converter(const Converter& conv); //kopijavimo konstruktorius
    Converter& operator=(const Converter& conv); //prilyginimo kopijavimo konstruktorius

    vector<byte> getOutput();

    static byte operations(byte item, byte val);
    static vector<byte> TrimAndFill(vector<byte> ivec);
    static unsigned long long int addAll(vector<byte> items);

    ~Converter(); //destruktorius

};


#endif