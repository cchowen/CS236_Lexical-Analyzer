//
// Created by Kit on 9/15/2021.
//

#ifndef PROJECT1_STARTER_CODE_IDAUTOMATION_H
#define PROJECT1_STARTER_CODE_IDAUTOMATION_H
#include "Automaton.h"

class IDAutomaton : public Automaton {
    public:
        IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor
        void S0(const std::string& input);
        bool validKeyword(const std::string& keyword);

};


#endif //PROJECT1_STARTER_CODE_IDAUTOMATION_H
