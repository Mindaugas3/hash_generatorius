#include <iostream>
#include <chrono>
#include "IO.h"
#include "Tests.h"

void readFile(string filename);
void readFileAndMeasureTime(string filename);
void readFileByLine(string filename);
void testForCollision(string filename);

void readConsole();

void compareTwo(string first, string second);
void compareSha256(string filename);

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

        } else if((string) argv[1] == "-generate" || (string) argv[1] == "-g"){ //generuojami failai
            if((string) argv[2] == "1000"){
                cout << "generuojamas failas su 1000 simboliu: \n";
                Tests::generateSymbols1000();
            } else if((string) argv[2] == "pairs"){
                cout << "generuojamos 100 000 poru\n";
                Tests::makePairsFiles();
            } else if((string) argv[2] == "diff"){
                cout << "generuojama 100 000 panasiu poru, kurios skiriasi tik vienu simboliu.\n";
                //Tests::
            }
        } else if((string) argv[1] == "-sha256"){
            cout << "Palyginama hasavimo sparta su SHA256 algoritmu\n";
            compareSha256(argv[2]);
        }


    } else if(argc > 3){ //komanda -files
        if((string) argv[1] == "-compare" || (string) argv[1] == "-c"){ //palygina skirtumus
            compareTwo(argv[2], argv[3]);
        }

    } else if(argc == 2){
        if((string) argv[1] == "-write" || (string) argv[1] == "-w"){ //irasome ranka(tinka ir be argumentu
            readConsole();
        }  else if((string) argv[1] == "-help" || (string) argv[1] == "-h" || (string) argv[1] == "?"){
            cout << "-help, -h, ?: pagalbos komanda\n";
            cout << "-file, -f [Failo vardas] : \t\t Nuskaito faila ir parodo hasha\n";
            cout << "-timer, -t [Failo vardas] : \t\t Parodo per kiek laiko suhasuoja faila\n";
            cout << "-line, -l [Failo vardas] : \t\t Nuskaito faila ir suhasuoja kiekviena eilute\n";
            cout << "-collision, -col [Failo vardas] : \t Nuskaito faila ir aptinka kolizijas kiekvienoje eiluteje\n";
            cout << "-write, -w: \t\t\t\t Ivesti galima ranka\n";
            cout << "-generate, -g [Argumentas] : \t\t Generuoja reiksmes testavimui\n";
            cout << "\t Argumentas: 1000 : \t\t\t Generuoja faila su 1000 atsitiktiniu simboliu\n";
            cout << "\t Argumentas: pairs : \t\t\t Generuoja faila su 100000 atsitiktiniu simboliu poru\n";
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

    vector<string> lines = IO::ReadFileWithLines(filename);
    for(const string& line : lines){
        Converter converter = Converter(line);
        IO::Output(converter.getOutput());
        cout << "\n";
    }
}

void testForCollision(string filename){
    vector<string> lines = IO::ReadFileWithLines(filename);
    vector<string> hashes;
    for(string line : lines){
        Converter conv = Converter(line);
        hashes.push_back(IO::Output(conv.getOutput()));
    }
    Tests::checkCollission(hashes);
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
    Tests::compareTwo(converter1, converter2);
    cout << "=============================================================================" << endl;
    cout << first << endl;
    IO::Output(converter1.getOutput());
    cout << "=============================================================================" << endl;
    cout << second << endl;
    IO::Output(converter2.getOutput());
}

void compareSha256(string filename){
    IO io = IO(filename);
    // sha256
    auto start = chrono::system_clock::now();
    Tests::MeasureSha256(io.getInput());
    auto end = chrono::system_clock::now();
    // mano algoritmas
    auto start2 = chrono::system_clock::now();
    Converter converter = Converter(io.getInput());
    auto end2 = chrono::system_clock::now();

    
}