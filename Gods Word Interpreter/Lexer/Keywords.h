#ifndef __GWI_LEXER__KEYWORDS_H_
#define __GWI_LEXER__KEYWORDS_H_

#include <vector>

#include "Token.h"

struct key {
    // Special
    static const Token EMPTY;
    static const Token END;

    // Punctuation
    static const Token BLOCK_OPEN;
    static const Token BLOCK_CLOSE;
    static const Token PAREN_OPEN;
    static const Token PAREN_CLOSE;
    static const Token BRACK_OPEN;
    static const Token BRACK_CLOSE;
    static const Token DOT;
    static const Token NEW_LINE;

    // Literals
    static const Token BOOL_TRUE;
    static const Token BOOL_FALSE;

    // Default Operators
    static const Token OP_PLUS;
    static const Token OP_MINUS;
    static const Token OP_MULT;
    static const Token OP_DIV;
    static const Token OP_MOD;

    // Variables
    static const Token CONST;
    static const Token FUNCTION;
    static const Token TYPE;

    // Control Statements
    static const Token STAT_IF;
    static const Token STAT_ELSEIF;
    static const Token STAT_ELSE;
    static const Token STAT_SWTICH;
    static const Token STAT_CASE;

    // Loops
    static const Token LOOP_FOR;
    static const Token LOOP_FOR_EACH;
    static const Token LOOP_WHILE;
    static const Token BREAK;

    // access modifiers
    static const Token MOD_PUBLIC;
    static const Token MOD_PROTECTED;
    static const Token MOD_GROUP;
    static const Token MOD_PRIVATE;

    static Token make(TokenType type, std::string value);
    static bool isKeyword(std::string tok);
    static bool isPunctuation(char tok);
    static bool isOperator(std::string tok);

    static const std::vector<Token> getKeys() { return keys; }
    static const std::vector<Token> getPunctuation() { return punctuation; }
    static const std::vector<Token> getOperators() { return operators; }
private:
    static std::vector<Token> keys;
    static std::vector<Token> punctuation;
    static std::vector<Token> operators;
};

#endif