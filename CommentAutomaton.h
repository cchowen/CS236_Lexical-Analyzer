//
// Created by Kit on 9/19/2021.
//

#ifndef PROJECT1_STARTER_CODE_COMMENTAUTOMATON_H
#define PROJECT1_STARTER_CODE_COMMENTAUTOMATON_H
#include "Automaton.h"

class CommentAutomaton : public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    bool S3(const std::string& input);
    public:
        CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor
        void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_COMMENTAUTOMATON_H
