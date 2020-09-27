//
// Created by Mindaugas on 2020-09-27.
//
#include <string>

#ifndef UNTITLED1_IO_H
#define UNTITLED1_IO_H


class IO {
    private:
        std::string input;
        std::string output;

    public:
        IO();
        std::string ReadScreen();
        void ReadFile();
        std::string Output();
        bool CheckResponse(char a, char b, char response);

    void ReadFile(std::string filename);
};


#endif //UNTITLED1_IO_H
