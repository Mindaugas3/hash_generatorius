#include <iostream>
#include <chrono>
#include "IO.h"
#include "converter.h"
#include "Tests.h"

void readFile(string filename);
void readFileAndMeasureTime(string filename);
void readFileByLine(string filename);
void testForCollision(string filename);

void readConsole();

void compareTwo(string first, string second);

int main(int argc, char **argv) {


    if(argc == 3){ //komanda -file, -timer, -line

        if((string) argv[1] == "-file" || (string) argv[1] == "-f"){ //tiesiog suhasuoja faila

            readFile(argv[2]);

        } else if((string) argv[1] == "-timer"|| (string) argv[1] == "-t"){ //suhasuoja ir ismatuoja kiek uztruko

            readFileAndMeasureTime(argv[2]);

        } else if((string) argv[1] == "-line" || (string) argv[1] == "-l"){ //suhasuoja eilute po eilutes

            readFileByLine(argv[2]);

        } else if((string) argv[1] == "-collision" || (string) argv[1] == "-col"){ //koliziju testas

            testForCollision(argv[2]);

        } else if((string) argv[1] == "-write" || (string) argv[1] == "-w"){ //irasome ranka(tinka ir be argumentu

            readConsole();
        }


    } else if(argc > 3){ //komanda -files
        if((string) argv[1] == "-compare" || (string) argv[1] == "-c"){ //palygina skirtumus
            compareTwo(argv[2], argv[3]);
        }

    } else {
        readConsole();
    }

    system("PAUSE");
    return 0;
}

void readFile(string filename){
    IO io = IO((string) filename);
    Converter converter = Converter(io.getInput());
    IO::Output(converter.getOutput());
}

void readFileAndMeasureTime(string filename){

    IO io = IO((string) filename);
    auto start = std::chrono::system_clock::now();
    Converter converter = Converter(io.getInput());
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Laikas per kuri buvo suhasuotas failas: "<< filename << " : " << diff.count() << " s\n";
}

void readFileByLine(string filename){
    //TODO
}

void testForCollision(string filename){
    //TODO
}

void readConsole(){
    IO io = IO();
    Converter converter = Converter(io.getInput());
    IO::Output(converter.getOutput());
}

void compareTwo(string first, string second){
    IO io = IO(first);
    IO io2 = IO(second);
    Converter converter1 = Converter(io.getInput());
    Converter converter2 = Converter(io2.getInput());
    cout << "=============================================================================" << endl;
    //testai
    Tests tests(converter1, converter2);
    cout << "=============================================================================" << endl;
    cout << first << endl;
    IO::Output(converter1.getOutput());
    cout << "=============================================================================" << endl;
    cout << second << endl;
    IO::Output(converter2.getOutput());
}