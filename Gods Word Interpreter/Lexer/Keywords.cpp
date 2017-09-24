#include "Keywords.h"

using namespace std;

vector<Token> key::keys;
vector<Token> key::punctuation;
vector<Token> key::operators;

const Token key::EMPTY(key::make(TokenType::EMPTY, "$EMPTY$"));
const Token key::END(make(TokenType::EMPTY, "$END OF FILE$"));

const Token key::BLOCK_OPEN(make(TokenType::PUNCTUATION, "{"));
const Token key::BLOCK_CLOSE(make(TokenType::PUNCTUATION, "}"));
const Token key::PAREN_OPEN(make(TokenType::PUNCTUATION, "("));
const Token key::PAREN_CLOSE(make(TokenType::PUNCTUATION, ")"));
const Token key::BRACK_OPEN(make(TokenType::PUNCTUATION, "["));
const Token key::BRACK_CLOSE(make(TokenType::PUNCTUATION, "]"));
const Token key::DOT(make(TokenType::PUNCTUATION, "."));
const Token key::NEW_LINE(make(TokenType::PUNCTUATION, "\n"));

const Token key::BOOL_TRUE(make(TokenType::LITERAL_BOOLEAN, "true"));
const Token key::BOOL_FALSE(make(TokenType::LITERAL_BOOLEAN, "false"));

const Token key::OP_PLUS(make(TokenType::OPERATOR, "+"));
const Token key::OP_MINUS(make(TokenType::OPERATOR, "-"));
const Token key::OP_MULT(make(TokenType::OPERATOR, "*"));
const Token key::OP_DIV(make(TokenType::OPERATOR, "/"));
const Token key::OP_MOD(make(TokenType::OPERATOR, "%"));

const Token key::CONST(make(TokenType::KEYWORD, "const"));
const Token key::FUNCTION(make(TokenType::KEYWORD, "func"));
const Token key::TYPE(make(TokenType::KEYWORD, "type"));

const Token key::STAT_IF(make(TokenType::KEYWORD, "if"));
const Token key::STAT_ELSEIF(make(TokenType::KEYWORD, "elseif"));
const Token key::STAT_ELSE(make(TokenType::KEYWORD, "else"));
const Token key::STAT_SWTICH(make(TokenType::KEYWORD, "switch"));
const Token key::STAT_CASE(make(TokenType::KEYWORD, "case"));

const Token key::LOOP_FOR(make(TokenType::KEYWORD, "for"));
const Token key::LOOP_FOR_EACH(make(TokenType::KEYWORD, "foreach"));
const Token key::LOOP_WHILE(make(TokenType::KEYWORD, "while"));
const Token key::BREAK(make(TokenType::KEYWORD, "break"));

const Token key::MOD_PUBLIC(make(TokenType::KEYWORD, "public"));
const Token key::MOD_PROTECTED(make(TokenType::KEYWORD, "protected"));
const Token key::MOD_GROUP(make(TokenType::KEYWORD, "group"));
const Token key::MOD_PRIVATE(make(TokenType::KEYWORD, "private"));

Token key::make(TokenType type, string value) {
    Token tok(type, value);
    keys.push_back(tok);
    if (type == TokenType::PUNCTUATION)
        punctuation.push_back(tok);
    if (type == TokenType::OPERATOR)
        operators.push_back(tok);
    return tok;
}

bool key::isKeyword(string c) {
    for (const Token &t : punctuation) {
        if (t.getValue() == c) {
            return true;
        }
    }
    return false;
}

bool key::isPunctuation(char c) {
    for (const Token &t : punctuation) {
        if (t.getValue()[0] == c) {
            return true;
        }
    }
    return false;
}

bool key::isOperator(string c) {
    for (const Token &t : operators) {
        if (t.getValue() == c) {
            return true;
        }
    }
    return false;
}
