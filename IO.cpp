//
// Created by Mindaugas on 2020-09-27.
//

#include "IO.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

IO::IO(){
    std::string fileKey = "F";
    std::string readKey = "R";


    std::cout << "Kad nuskaityti is failo, iveskite " + fileKey + ". Kad nuskaityti ranka iveskite " + readKey + ". \n";

    char response = std::cin.get();

    while (!CheckResponse(readKey[0], fileKey[0], response)){
        //std::fflush(stdin);
        response = std::cin.get();
    }
};


bool IO::CheckResponse(char a, char b, char response){
    if(response == a){
        ReadScreen();
        return true;
    } else if(response == b){
        ReadFile();
        return true;
    } else {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Iveskite is naujo! [F]ailas arba ivesti [R]anka \n";
        return false;
    }
};

void IO::ReadFile(){

    std::string fileName;

    std::cout << "Iveskite failo pavadinima: ";

    std::cin >> fileName;

    std::ifstream fd;
    fd.open(fileName);
    do
    {
        try
        {
            if(fd.fail())
            {
                throw std::runtime_error("Nepavyko atidaryti failo!\n");
            }
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what();
            fileName = "";
            std::cin.ignore(256,'\n');
            std::cout<<"Iveskite dar karta failo pavadinima: ";
            std::cin >> fileName;
            fd.open(fileName);
        }
    }
    while(fd.fail());

    this->input.assign( (std::istreambuf_iterator<char>(fd) ),
                        (std::istreambuf_iterator<char>()   ));

    fd.close();

}

std::string IO::ReadScreen(){
    std::cout << "Iveskite teksta kuri norite paversti i hasha \n";
    std::string x;
    std::cin >> x;
    this->input = x;
    return x;
}

void IO::Output(std::string string) {
    std::cout << "Sugeneruotas hash kodas: " << string << std::endl;
}

std::string IO::getInput() {
    if(input.length() > 0) return input;
    else return "";
}


