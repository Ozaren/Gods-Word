#ifndef __GWI_PARSER_PARTS_VARIABLES__LITERALS_H__
#define __GWI_PARSER_PARTS_VARIABLES__LITERALS_H__

#include <string>

#include "../Type/Type.h"
#include "../Type/DefualtTypes.h"

template<typename ValueType>
class Literal {
public:
    const ValueType value;
    const Type &type;

    Literal(const Type &_type, ValueType _value) : type(_type), value(_value) {}
    virtual ValueType getValue() const { return value; }
};

class LiteralInteger : public Literal<int32_t> {
public:
    LiteralInteger(int32_t val);
};

class LiteralUInteger : public Literal<uint32_t> {
public:
    LiteralUInteger(uint32_t val);
};

class LiteralFloat : public Literal<double_t> {
public:
    LiteralFloat(double_t val);
};

class LiteralBoolean : public Literal<bool> {
public:
    LiteralBoolean(bool val);
};

class LiteralChar : public Literal<char> {
public:
    LiteralChar(char val);
};

class LiteralString : public Literal<std::string> {
public:
    LiteralString(std::string val);
};

#endif