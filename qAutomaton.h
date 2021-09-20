//
// Created by Kit on 9/15/2021.
//

#ifndef PROJECT1_STARTER_CODE_QAUTOMATON_H
#define PROJECT1_STARTER_CODE_QAUTOMATON_H


#include <string>
#include "Automaton.h"

class qAutomaton : public Automaton
{
public:
    qAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_QAUTOMATON_H
