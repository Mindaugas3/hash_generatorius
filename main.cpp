#include <iostream>
#include "IO.h"
#include "converter.h"

int main() {

//    std::setlocale(LC_ALL, "lt_LT.UTF-8");


    IO io = IO();
    Converter converter = Converter(io.getInput());
    io.Output(converter.getOutput());


    system("PAUSE");
    return 0;
}
