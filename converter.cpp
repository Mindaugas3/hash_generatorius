//
// Created by Mindaugas on 2020-09-27.
//

#include "converter.h"


std::string Converter::getOutput() {
    return output;
}

Converter::Converter(string str) {
    //viskas vykdoma konstruktoriuje

    unsigned int hash = SEED;
    string out = "";

    for(char item : str){

        hash += SEED;
        hash += hash >> 2;
        hash += item;
        hash += (hash << 7) + SEED + (hash + item);
        hash ^= ((SEED - item) >> 11);
        hash *= (SEED - hash);
        out += hash;

        hash %= SEED;
        hash ^= ((hash >> 5) + (item << 3));
        hash -= (hash >> 2) - SEED;
        hash += (hash >> 4) ^ 7;
        hash += (((SEED + hash ) % 5) >> 2);
        hash += (item >> 5) + (SEED ^ hash);
        out += hash;

        hash ^= (hash >> 4) + item;
        hash += (hash << 5);
        hash -= SEED;
        hash += (hash << 3) + (item >> 4);
        hash *= (hash >> 5) + SEED;
        hash ^= ((hash >> 3) ^ SEED);
        out += hash;

        //fiksuotas skaicius

    }
    output = out;
}