//
// Created by Mindaugas on 2020-09-27.
//
#include <string>

#ifndef UNTITLED1_IO_H
#define UNTITLED1_IO_H
#define TEST


class IO {
    private:
        std::string input;
        std::string output;

    public:
        IO();
        std::string ReadScreen();
        void ReadFile();
        void Output(std::string string);
        bool CheckResponse(char a, char b, char response);
        std::string getInput();
};


#endif //UNTITLED1_IO_H
