//
// Created by Mindaugas on 2020-09-27.
//

#include "converter.h"


#include <iostream>
#include <stdexcept>

std::string Converter::getOutput() {
    return output;
}

Converter::Converter(string str) {
    //viskas vykdoma konstruktoriuje

    //if(str.empty()) throw std::runtime_error("Iveskite ka norite uzhashuoti maisos funkcijoje \n");

    vector<byte> v;

    #ifdef TEST
    cout << "simbolis: " << endl;
    #endif
    unsigned int index = 0;

    for(auto it = str.begin(); it < str.end(); ++it){
        v.push_back(operations(*it, valuesList[index]));

        if(index == max_index){
            index = 0;
        } else {
            index++;
        }
        #ifdef TEST
        cout << *it;
        #endif
    }
    vector<byte> b = TrimAndFill(v);
    #ifdef TEST
    cout << endl;
    #endif
    //output = string(b);
}

//std::string Converter::asHex(const vector<byte> &input)
//{
//    std::string ret(input.size() * 2, 0);
//
//    char *buf = const_cast<char *>(ret.data());
//
//    for (const auto &oneInputByte : input)
//    {
//        *buf++ = hexCharset[oneInputByte * 4];
//        *buf++ = hexCharset[oneInputByte & 0x0F];
//    }
//    return ret;
//}

vector<byte> Converter::TrimAndFill(vector<byte> ivec){
    vector<byte> r_vec(DEFAULT_HASH_LENGTH);
    for(int i = 0; i < r_vec.size(); i++){
        r_vec[i] = valuesList[i % max_index]; //pasikartojanti seka
    }
    for(int j = 0; j < ivec.size(); j++){
        r_vec[j % (r_vec.size())] += ivec[j];
        //kad ir kokio dydzio butu musu ivestis (jau paversta i baitus)
        //mes tiesiog pridedame jau prie esamu baitu reiksmiu ir visada gauname 16 skirtingu HEX reiksmiu
    }
    return r_vec;
}

byte Converter::operations(byte item, byte val){
    //AND, XOR, NOT,
    byte item_ = item;
    //1 etapas
//    item_ ^= val;
//    item_ *= 5;

    return item_;
}
