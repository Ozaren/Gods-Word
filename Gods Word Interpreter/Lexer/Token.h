#ifndef __GWI_LEXER__TOKEN_H_
#define __GWI_LEXER__TOKEN_H_

#include <string>

enum TokenType {
    // Special
    UNKNOWN = -1,
    EMPTY,
    PUNCTUATION,
    COMPILER_NOTE,
    CN_ARG,
    OPERATOR,

    // Literals
    LITERAL_BOOLEAN,
    LITERAL_INT,
    LITERAL_FLOAT,
    LITERAL_CHAR,
    LITERAL_STRING,

    // Types of things
    KEYWORD,
    IDENTIFIER,
};

class Token {
public:
    Token();
    Token(TokenType type, std::string value);

    TokenType getType() const;
    std::string getValue() const;

    Token& operator=(const Token &other) {
        type = other.type;
        value = other.value;
        return *this;
    }

    bool operator==(const Token &other) const { return type == other.type&&value == other.value; }
    bool operator!=(const Token &other) const { return !operator==(other); }

private:
    TokenType type;
    std::string value;
};

#endif // !__GWI_LEXER__TOKEN_H_
