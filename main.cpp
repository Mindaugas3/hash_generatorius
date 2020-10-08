#include <iostream>
#include "IO.h"
#include "converter.h"
#include "Tests.h"

int main(int argc, char **argv) {


    if(argc == 2){ //nurodytas vienas failas
        IO io = IO((string) argv[1]);
        Converter converter = Converter(io.getInput());
        IO::Output(converter.getOutput());
    } else if(argc > 2){ //nurodyti keli failai
        IO io = IO(argv[1]);
        IO io2 = IO(argv[2]);
        Converter converter1 = Converter(io.getInput());
        Converter converter2 = Converter(io2.getInput());
        cout << "=============================================================================" << endl;
        //testai
        Tests tests(converter1, converter2);
        cout << "=============================================================================" << endl;
        cout << argv[1] << endl;
        IO::Output(converter1.getOutput());
        cout << "=============================================================================" << endl;
        cout << argv[2] << endl;
        IO::Output(converter2.getOutput());
    } else {
        IO io = IO();
        Converter converter = Converter(io.getInput());
        IO::Output(converter.getOutput());
    }

    system("PAUSE");
    return 0;
}
