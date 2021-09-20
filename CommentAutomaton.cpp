//
// Created by Kit on 9/19/2021.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string &input) {
    if (input[index] != '#') {
        Serr();
        return;
    }
    else {
        index++;
        inputRead++;
        S1(input);
        return;
    }
}

void CommentAutomaton::S1(const std::string &input) {
    if (input[index] == '|') {
        index++;
        inputRead++;
        S2(input);
        return;
    } else {
        while (input[index] != '\n') {
            index++;
            inputRead++;
        }
        return;
    }
}

void CommentAutomaton::S2(const std::string &input) {
    std::string capture;
    while (input[index] != '|')  {
        if (index >= input.size()) {
            type = TokenType::UNDEFINED;
            return;
        }
        if (input[index] == '\n') {
            newLines++;
            inputRead++;
            index++;
            capture += input[index];
            continue;
        }
        index++;
        inputRead++;
    }
    capture += input[index];
    if (index > input.size()) {
        type = TokenType::UNDEFINED;
        return;
    }
    index++;
    inputRead++;
    if (S3(input)) {
        return;
    }
    else {
        S2(input);
    }
}

bool CommentAutomaton::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        return true;
    }
    else {
        return false;
    }

}
