//
// Created by Mindaugas on 2020-09-27.
//

#include "converter.h"

#include <vector>
#include <iostream>

std::string Converter::getOutput() {
    return output;
}

Converter::Converter(string str) {
    //viskas vykdoma konstruktoriuje

    unsigned int hash = SEED;
    string out = "";
    vector<byte> v;

    #ifdef TEST
    cout << "item as bytes: " << endl;
    #endif
    for(char item : str){
        byte *itemref = reinterpret_cast<byte *>(&item);

        #ifdef TEST
        cout << *itemref << " ";
        #endif
    }
    #ifdef TEST
    cout << endl;
    #endif
    output = out;
}
