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


    std::cout << "Kad nuskaityti is failo, iveskite [" + fileKey + "]. Kad nuskaityti ranka iveskite [" + readKey + "]. \n";

    char response = std::cin.get();

    while (!CheckResponse(readKey[0], fileKey[0], response)){
        //std::fflush(stdin);
        response = std::cin.get();
    }
};

IO::IO(std::string filename) {
    std::cout << "Hasuojamas failas: " << filename << std::endl;
    ReadFile(filename);
}

bool IO::CheckResponse(char a, char b, char response){
    if(response == a){
        ReadScreen();
        return true;
    } else if(response == b){
        RequestFile();
        return true;
    } else {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Iveskite is naujo! [F]ailas arba ivesti [R]anka \n";
        return false;
    }
};

void IO::ReadFile(std::string fileName){

    std::ifstream fd;
    fd.open(fileName);
    do{
        try
        {
            if(fd.fail())
            {
                throw std::runtime_error("Nepavyko atidaryti failo! [Enter]\n");
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
    } while(fd.fail());

    this->input.assign( (std::istreambuf_iterator<char>(fd) ),
                        (std::istreambuf_iterator<char>()   ));

    fd.close();

}

void IO::RequestFile(){

    std::string fileName;

    std::cout << "Iveskite failo pavadinima: ";

    std::cin >> fileName;

    ReadFile(fileName);
}

std::string IO::ReadScreen(){
    std::cout << "Iveskite teksta kuri norite paversti i hasha \n";
    std::string input_;
    std::cin.clear();
    std::cin >> input_;
    this->input = input_;
    return input_;
}

void IO::Output(std::vector<uint8_t> bytes) {
    std::cout << "Sugeneruotas hash kodas: " << std::endl;
    for(uint8_t a : bytes){
        std::cout << std::hex << static_cast<int>(a);
    }
    std::cout << std::endl;
}

std::string IO::getInput() {
    if(input.length() > 0) return input;
    else return "";
}

std::vector<std::string> IO::ReadFileWithLines(std::string filename) {
    std::ifstream i(filename);

    do {
        try {
            if(i.fail())
            {
                throw std::runtime_error("Nepavyko atidaryti failo! [Enter]\n");
            }
        } catch (const std::runtime_error& error) {
            std::cout << error.what();
            filename = "";
            std::cin.ignore(256,'\n');
            std::cout<<"Iveskite dar karta failo pavadinima: ";
            std::cin >> filename;
            i.open(filename);
        }
    } while (i.fail());

    //skaitome
    std::vector<std::string> lines;

    std::string line;
    while(std::getline(i, line)){

        lines.push_back(line);
    }

    return lines;
}




