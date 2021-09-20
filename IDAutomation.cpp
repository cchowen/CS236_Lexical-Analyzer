//
// Created by Kit on 9/15/2021.
//
#include "IDAutomation.h"
#include "iostream"
#include <cctype>

void IDAutomaton::S0(const std::string& input) {
    std::string keyword = "";
    bool key = false;
    while (index < input.size() && input[index] != '\n') {
        if (index == 0) {
            if (std::isdigit(input[index]) || input[index] == '\'' || input[index] == '#') {
                Serr();
                return;
            }
        }
        if (std::isspace(input[index])) {
            return;
        }
        if (!std::isalnum(input[index])) {
            return;
        }
        keyword += input[index];
        inputRead++;
        index++;
        if (input[index] == '\n' || index == input.size()) {
          key = validKeyword(keyword);
          if (key) {
              Serr();
          }
          else {
              return;
          }
        }
    }
}

bool IDAutomaton::validKeyword(const std::string& keyword) {
    std::string rules = "Rules";
    std::string queries = "Queries";
    std::string facts = "Facts";
    std::string schemes = "Schemes";
    if (keyword == rules || keyword == queries || keyword == facts || keyword == schemes) {
        return true;
    } else {
        return false;
    }
}