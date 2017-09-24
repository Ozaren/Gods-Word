#include "Token.h"

using namespace std;

Token::Token() 
    : Token(TokenType::EMPTY, "") {

}

Token::Token(TokenType _type, string _value)
    : type(_type), value(_value) {
    
}

TokenType Token::getType() const {
    return type;
}

string Token::getValue() const {
    return value;
}