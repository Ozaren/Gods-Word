#include "Variable.h"

Variable::Variable(std::string _name, const Type &_type, void *_value, uint8_t _mod)
    : name(_name), type(_type), value(_value), mod(_mod) {

}

bool Variable::hasMod(uint8_t m) const {
    return (mod & m) != 0;
}
