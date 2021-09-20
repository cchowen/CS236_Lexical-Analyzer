//
// Created by Kit on 9/15/2021.
//

#include "qAutomaton.h"

void qAutomaton::S0(const std::string &input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}