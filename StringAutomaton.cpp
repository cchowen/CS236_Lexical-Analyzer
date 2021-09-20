//
// Created by Kit on 9/15/2021.
//
#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    std::string capture;
    while (index < input.size()) {
        if (input[0] != '\'') {
            Serr();
            return;
        }
        else if (index == 0 && input[index] == '\'') {
            index++;
            inputRead++;
            S1(input);
        }
        return;
    }
}






void StringAutomaton::S1(const std::string& input) {
    std::string capture;
    do {
        if (index >= input.size()) {
            // end of file
            type = TokenType::UNDEFINED;
            return;
        }
        if (input[index] == '\n') {
            capture += input[index];
            newLines++;
            index++;
            inputRead++;
            continue;
        }
        if (input[index] == '\'') {
            if (!S2(input)) {
                inputRead++;
                return;
            }
            index++;
            inputRead++;
        }
        index++;
        inputRead++;
    } while (index <= input.size());
}


bool StringAutomaton::S2(const std::string &input) {
    if (index + 1 >= input.size()) {
        // end of file
        type = TokenType::UNDEFINED;
        return false;
    }
    else if (input[index + 1] == '\'') {
        return true;
    }
    else {
        return false;
    }
}
