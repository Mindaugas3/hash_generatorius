//
// Created by Mindaugas on 2020-09-27.
//

#include "converter.h"


#include <iostream>

std::string Converter::getOutput() {
    return output;
}

Converter::Converter(string str) {
    //viskas vykdoma konstruktoriuje

    unsigned int hash = SEED;
    vector<byte> v;

    #ifdef TEST
    cout << "simbolis kaip uint8_t: " << endl;
    #endif
    unsigned int index = 0;
    for(char item : str){
        byte itemref = asByte(operations(item, valuesList[index]));
        v.push_back(itemref);
        index == max_index ? index = 0 : index++; //elvio operatorius
    }
    vector<byte> b = TrimAndShuffle(v);
    #ifdef TEST
    cout << endl;
    #endif
    output = asHex(b);
}

std::string Converter::asHex(const vector<byte> &input)
{
    std::string ret(input.size() * 2, 0);

    char *buf = const_cast<char *>(ret.data());

    for (const auto &oneInputByte : input)
    {
        *buf++ = hexCharset[oneInputByte * 4];
        *buf++ = hexCharset[oneInputByte & 0x0F];
    }
    return ret;
}

vector<byte> Converter::TrimAndShuffle(vector<byte> ivec){
    vector<byte> r_vec = vector<byte>(DEFAULT_HASH_LENGTH);
    for(int i = 0; i < r_vec.size(); i++){
        r_vec[i] = valuesList[i % max_index]; //pasikartojanti seka
    }
    for(int j = 0; j < ivec.size(); j++){
        r_vec[j % (r_vec.size())] += ivec[j];
        //kad ir kokio dydzio butu musu ivestis (jau paversta i baitus)
        //mes tiesiog pridedame jau prie esamu baitu reiksmiu ir visada gauname 16 skirtingu HEX reiksmiu
    }
}

const byte& Converter::asByte(char item){
    //verciame simboli i baita
    byte *itemref = reinterpret_cast<byte *>(&item);

#ifdef TEST
    cout << *itemref << " ";
#endif

    return *itemref;
}

byte Converter::operations(byte item, byte val){
    //AND, XOR, NOT,
    byte item_ = item;
    //1 etapas
    item_ ^= val;
    item_ *= 5;

    return item_;
}
