//
// Created by Kit on 9/15/2021.
//

#ifndef PROJECT1_STARTER_CODE_LEFTPAUTOMATON_H
#define PROJECT1_STARTER_CODE_LEFTPAUTOMATON_H
#include "Automaton.h"

class LeftPAutomaton : public Automaton {
    public:
        LeftPAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor
        void S0(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_LEFTPAUTOMATON_H
