//
// Created by Mindaugas on 2020-09-27.
//
#include <string>
#include <vector>

#ifndef UNTITLED1_IO_H
#define UNTITLED1_IO_H
#define TEST


class IO {
    private:
        std::string input;

    public:
        IO();
        explicit IO(std::string filename);
        static std::vector<std::string> ReadFileWithLines(std::string filename);
        std::string ReadScreen();
        void ReadFile(std::string filename);
        static void Output(std::vector<uint8_t> bytes);
        bool CheckResponse(char a, char b, char response);
        std::string getInput();

    void RequestFile();
};


#endif //UNTITLED1_IO_H
