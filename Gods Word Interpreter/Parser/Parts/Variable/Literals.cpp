#include "Literals.h"

using namespace std;
using namespace GWI;
using namespace literal_value;

Boolean::Boolean(bool value)
    : Literal(def_type::BOOLEAN, value) {

}

Integer::Integer(int value)
    : Literal(def_type::INT, value) {

}

U_Integer::U_Integer(unsigned int value)
    : Literal(def_type::UINT, value) {

}

Float::Float(double value)
    : Literal(def_type::FLOAT, value) {

}

Character::Character(char value)
    : Literal(def_type::CHAR, value) {

}

String::String(string value)
    : Literal(def_type::STRING, value) {

}
