#include <iostream>
#include "IO.h"
#include "converter.h"

int main(int argc, char **argv) {


    if(argc > 0){
        IO io = IO((string) *argv);
        Converter converter = Converter(io.getInput());
        io.Output(converter.getOutput());
    } else {
        IO io = IO();
        Converter converter = Converter(io.getInput());
        io.Output(converter.getOutput());
    }

    system("PAUSE");
    return 0;
}
