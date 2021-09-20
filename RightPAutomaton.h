//
// Created by Kit on 9/15/2021.
//

#ifndef PROJECT1_STARTER_CODE_RIGHTPAUTOMATON_H
#define PROJECT1_STARTER_CODE_RIGHTPAUTOMATON_H


#include "Automaton.h"

class RightPAutomaton : public Automaton {
public:
    RightPAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor
    void S0(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_RIGHTPAUTOMATON_H
