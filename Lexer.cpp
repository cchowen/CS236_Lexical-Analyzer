#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "qAutomaton.h"
#include "LeftPAutomaton.h"
#include "RightPAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomation.h"
#include "IDAutomation.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include <cctype>
#include <iostream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (auto machine : automata) {
        delete machine;
    }
    automata.clear();
    for (auto token : tokens) {
        delete token;
    }
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new AddAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new LeftPAutomaton());
    automata.push_back(new RightPAutomaton());
    automata.push_back(new qAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomation());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];
        // TODO: you need to handle whitespace inbetween tokens
        while (std::isspace(input[0])) {
            if (input[0] == '\n') {
                ++lineNumber;
            }
            input = input.substr(1);
            if (input == "") {
                Token* endToken = new Token(TokenType::END_OF_FILE, "", lineNumber);
                tokens.push_back(endToken);
                return;
            }
        }
        bool string_err = false;
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for (Automaton* x : automata) {
            int inputRead = x->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = x;
            }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            //   add newToken to collection of all tokens
            tokens.push_back(newToken);
        }
        // No automaton accepted input
        // Create single character undefined token
        else if (maxRead == 0) {
            maxRead = 1;
                Token* newToken = new Token(TokenType::UNDEFINED,input.substr(0,maxRead),lineNumber);
                //(with first character of input)
                tokens.push_back(newToken);
        }
        else {
            Token* newToken = new Token(TokenType::UNDEFINED,input.substr(0,maxRead),lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            //   add newToken to collection of all tokens
            tokens.push_back(newToken);
        }
        // Update `input` by removing characters read to create Token
       // remove maxRead characters from input */
       input = input.substr(maxRead);
    }
    return;
}

void Lexer::toString() {
    for (Token* token : tokens) {
        int line = token->getLineNum();
        std::string ttype = token->stringTokenType(token->getType());
        std::string content = token->getContent();
        std::cout << "(" << ttype << ",\"" << content << "\"," << line << ")" << '\n';
    }
    std::cout << "Total Tokens = " << tokens.size();
    return;
}
