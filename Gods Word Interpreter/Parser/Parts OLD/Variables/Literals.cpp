#include "Literals.h"

using namespace std;

LiteralInteger::LiteralInteger(int32_t val)
    : Literal(type::INT, val) {

}

LiteralUInteger::LiteralUInteger(uint32_t val)
    : Literal(type::UINT, val) {

}

LiteralFloat::LiteralFloat(double_t val)
    : Literal(type::FLOAT, val) {

}

LiteralBoolean::LiteralBoolean(bool val)
    : Literal(type::BOOL, val) {

}

LiteralChar::LiteralChar(char val)
    : Literal(type::CHAR, val) {

}

LiteralString::LiteralString(string val)
    : Literal(type::STRING, val) {

}
