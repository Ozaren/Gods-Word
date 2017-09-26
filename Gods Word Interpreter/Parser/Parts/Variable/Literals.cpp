#include "Literals.h"

using namespace std;
using namespace GWI;
using namespace literal_value;

Literal::Literal(const TypeP &_type, void* _value)
    : type(_type), value(_value) {

}

Boolean::Boolean(void* value)
    : Literal(def_type::BOOLEAN, value) {

}

Integer::Integer(void* value)
    : Literal(def_type::INT, value) {

}

U_Integer::U_Integer(void* value)
    : Literal(def_type::UINT, value) {

}

Float::Float(void* value)
    : Literal(def_type::FLOAT, value) {

}

Character::Character(void* value)
    : Literal(def_type::CHAR, value) {

}

String::String(void* value)
    : Literal(def_type::STRING, value) {

}
