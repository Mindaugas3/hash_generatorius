#include <iostream>
#include <chrono>
#include "IO.h"
#include "converter.h"
#include "Tests.h"

int main(int argc, char **argv) {


    if(argc == 3){ //komanda -file, -timer, -line

        if((string) argv[1] == "-file" || (string) argv[1] == "-f"){ //tiesiog suhasuoja faila

            IO io = IO((string) argv[2]);
            Converter converter = Converter(io.getInput());
            IO::Output(converter.getOutput());

        } else if((string) argv[1] == "-timer"|| (string) argv[1] == "-t"){ //suhasuoja ir ismatuoja kiek uztruko

            IO io = IO((string) argv[2]);
            auto start = std::chrono::system_clock::now();
            Converter converter = Converter(io.getInput());
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = end-start;
            std::cout << "Laikas per kuri buvo suhasuotas failas: "<< argv[2] << " : " << diff.count() << " s\n";

        } else if((string) argv[1] == "-line" || (string) argv[1] == "-l"){ //suhasuoja eilute po eilutes

        } else if((string) argv[1] == "-collision" || (string) argv[1] == "-col"){ //koliziju testas

        }


    } else if(argc > 3){ //komanda -files
        if((string) argv[1] == "-compare" || (string) argv[1] == "-c"){ //palygina skirtumus
            IO io = IO(argv[2]);
            IO io2 = IO(argv[3]);
            Converter converter1 = Converter(io.getInput());
            Converter converter2 = Converter(io2.getInput());
            cout << "=============================================================================" << endl;
            //testai
            Tests tests(converter1, converter2);
            cout << "=============================================================================" << endl;
            cout << argv[2] << endl;
            IO::Output(converter1.getOutput());
            cout << "=============================================================================" << endl;
            cout << argv[3] << endl;
            IO::Output(converter2.getOutput());
        }

    } else {
        IO io = IO();
        Converter converter = Converter(io.getInput());
        IO::Output(converter.getOutput());
    }

    system("PAUSE");
    return 0;
}
