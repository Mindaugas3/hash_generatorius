//
// Created by Mindaugas on 2020-09-27.
//

#include "converter.h"


#include <iostream>
#include <stdexcept>

vector<byte> Converter::getOutput() {
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
    vector<byte> bytevec = TrimAndFill(v);
    #ifdef TEST
    cout << endl;
    #endif
    output = bytevec;
//    for(byte B : bytevec){
//        output.push_back(B);
//        cout << "Symbol" << endl;
//    }
}


vector<byte> Converter::TrimAndFill(vector<byte> ivec){
    vector<byte> r_vec(DEFAULT_HASH_LENGTH);
    bool direction = true; //false -> i prieki, true -> atgal
    //1 etapas
    for(int i = 0; i < r_vec.size(); i++){
        r_vec[i] = valuesList[i % max_index]; //pasikartojanti seka
        //uzpildo tuscia vektoriu su reiksmemis
    }
    //2 etapas - "sluoksniuotas pyragas"
    auto forwardIterator = r_vec.begin();
    auto reverseIterator = r_vec.rbegin();
    for(auto X = ivec.begin(); X < ivec.end(); X++){
        if(direction){
            if(forwardIterator < r_vec.end()){
                *forwardIterator += *X;
                ++forwardIterator;
            } else {
                direction = false;
                reverseIterator = r_vec.rbegin();
            }
        } else {
            if(reverseIterator < r_vec.rend()){
                *reverseIterator += *X;
                ++reverseIterator;
            } else {
                direction = true;
                forwardIterator = r_vec.begin();
            }
        }

    }
    return r_vec;
}

byte Converter::operations(byte item, byte val){
    //AND, XOR, NOT,
    byte item_ = item;
    //1 etapas
    item_ ^= val;
    item_ *= 5;

    return item_;
}
