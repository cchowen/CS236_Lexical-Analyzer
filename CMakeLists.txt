cmake_minimum_required(VERSION 3.16)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        qAutomaton.cpp
        qAutomaton.h
        LeftPAutomaton.cpp
        LeftPAutomaton.h
        RightPAutomaton.cpp
        RightPAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        QueriesAutomation.cpp
        QueriesAutomation.h
        IDAutomation.cpp
        IDAutomation.h
        StringAutomaton.cpp
        StringAutomaton.h CommentAutomaton.cpp CommentAutomaton.h)
