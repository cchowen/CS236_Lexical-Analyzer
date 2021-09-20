#include <fstream>
#include <iostream>
#include <sstream>
#include "Lexer.h"

int main(int argc, char** argv) {
    std::string filename = argv[1];
    std::ifstream input(filename);
    std::stringstream ss;
    if (input) {
        ss << input.rdbuf();
        input.close();
    }
    std::string output = ss.str();
    Lexer* lexer = new Lexer();

    // TODO
    lexer->Run(output);
    lexer->toString();
    delete lexer;
    return 0;
}