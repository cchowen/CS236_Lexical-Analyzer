#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->line = line;
    this->description = description;
    this->type = type;
}

std::string Token::stringTokenType(TokenType type) {
    switch (type) {
        case TokenType::STRING: return "STRING"; break;
        case TokenType::UNDEFINED: return "UNDEFINED"; break;
        case TokenType::COLON: return "COLON"; break;
        case TokenType::COLON_DASH: return "COLON_DASH"; break;
        case TokenType::COMMA: return "COMMA"; break;
        case TokenType::PERIOD: return "PERIOD"; break;
        case TokenType::Q_MARK: return "Q_MARK"; break;
        case TokenType::LEFT_PAREN: return "LEFT_PAREN"; break;
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN"; break;
        case TokenType::MULTIPLY: return "MULTIPLY"; break;
        case TokenType::ADD: return "ADD"; break;
        case TokenType::SCHEMES: return "SCHEMES"; break;
        case TokenType::FACTS: return "FACTS"; break;
        case TokenType::RULES: return "RULES"; break;
        case TokenType::QUERIES: return "QUERIES"; break;
        case TokenType::ID: return "ID"; break;
        case TokenType::COMMENT: return "COMMENT"; break;
        case TokenType::END_OF_FILE: return "EOF"; break;
    }
}

TokenType Token::getType() {
    return this->type;
}

std::string Token::getContent() {
    return this->description;
}

int Token::getLineNum() {
    return this->line;
}
