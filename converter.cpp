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

    unsigned int index = 0;

    for(auto it = str.begin(); it < str.end(); ++it){
        //maisymas vyksta tiesiogiai su input stringu

        v.push_back(operations(*it, valuesList[index]));

        if(index == max_index){
            index = 0;
        } else {
            index++;
        }
    }
    //input stringas isdeliojamas kaip sluoksniuotas pyragas
    vector<byte> bytevec = TrimAndFill(v);
    //shuffle(bytevec);
    output = bytevec;
}


vector<byte> Converter::TrimAndFill(vector<byte> ivec){
    vector<byte> r_vec(DEFAULT_HASH_LENGTH); //tuscias

    size_t inputSize = ivec.size();

    for(int i = 0; i < r_vec.size(); i++){
        r_vec[i] = valuesList[i % max_index]; //pasikartojanti seka
        //uzpildo tuscia vektoriu su reiksmemis
    }
    auto forwardIterator = r_vec.begin();
    int valIndex = 0;

    if(inputSize > DEFAULT_HASH_LENGTH){ //musu inputas ilgesnis uz hasho ilgi
        for(auto X = ivec.begin(); X < ivec.end(); X++) {
            size_t sizeAt = X - ivec.begin();
            if (forwardIterator < r_vec.end()) {
                //pildome
                //sniego lavinos ciklas
                for (auto iter = ivec.begin(); iter < ivec.end(); ++iter) {
                    *X ^= *iter;
                }
                *forwardIterator ^= (*X >> 3u);
                *forwardIterator += operations(*X, operations(*X, valuesList[valIndex]));
                ++forwardIterator;
            } else {
                //nukreipiame pointeri i pati pirma iteratoriu
                valIndex = 0;
                forwardIterator = r_vec.begin();
            }
            ++valIndex;
        }
    } else { //musu inputas ir hashas yra vienodo ilgio arba inputas trumpesnis
        auto inputIterator = ivec.begin();
        for(auto B = r_vec.begin(); B < r_vec.end(); ++B){
            if(inputIterator < ivec.end()){
                //sniego lavinos ciklas
                for (auto iter = ivec.begin(); iter < ivec.end(); ++iter) {
                    *iter += *B;
                }
                *B += operations(*inputIterator, 3);
                *B <<= 3u;
                *B ^= *inputIterator;
                ++inputIterator;
            } else {
                //nukreipiame pointeri i pati pirma inputo iteratoriu
                inputIterator = ivec.begin();
            }
            ++valIndex;
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
    item_ >>= 7u;
    item_ += val;

    return item_;
}

