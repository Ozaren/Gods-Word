#include "Variable.h"

#include "../Type/Type.h"
#include "../Type/DefualtType.h"

using namespace std;
using boost::any;
__USE_NAMESPACE__

Variable::Variable(PtrType _type)
    : type(_type) {
    if (type == def_type::BOOL) {
        types.push_back(BOOLEAN);
    }
    else if (type == def_type::SINT) {
        types.push_back(SIGNED_INTEGER);
    }
    else if (type == def_type::UINT) {
        types.push_back(UNSIGNED_INTEGER);
    }
    else if (type == def_type::FLOT) {
        types.push_back(FLOAT);
    }
    else if (type == def_type::CHAR) {
        types.push_back(CHARACTER);
    }
    else if (type == def_type::STRN) {
        types.push_back(STRING);
    }
    else {
        types.push_back(VARIABLE);
    }
}

any Variable::get_any(size_t pos) {
    return memory[pos];
}

template<typename type>
type Variable::get(size_t pos) {
    return boost::any_cast<type>(get(pos));
}

bool Variable::validate(VarTypes t2) {
    if (type == def_type::BOOL) {
        return t2 == VarTypes::BOOLEAN;
    }
    else if (type == def_type::SINT) {
        return t2 == VarTypes::SIGNED_INTEGER;
    }
    else if (type == def_type::UINT) {
        return t2 == VarTypes::UNSIGNED_INTEGER;
    }
    else if (type == def_type::FLOT) {
        return t2 == VarTypes::FLOAT;
    }
    else if (type == def_type::CHAR) {
        return t2 == VarTypes::CHARACTER;
    }
    else if (type == def_type::STRN) {
        return t2 == VarTypes::STRING;
    }
    else {
        return t2 == VarTypes::VARIABLE;
    }
}

void Variable::set(int pos, bool val) {
    if (validate(BOOLEAN)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, int val) {
    if (validate(SIGNED_INTEGER)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, size_t val) {
    if (validate(UNSIGNED_INTEGER)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, double val) {
    if (validate(FLOAT)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, char val) {
    if (validate(CHARACTER)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, std::string val) {
    if (validate(STRING)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, const PtrVariable &val) {
    if (validate(VARIABLE)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, const PtrType &val) {
    if (validate(VARIABLE)) {
        memory[pos] = val;
    }
}

void Variable::set(int pos, const PtrFunction &val) {
    if (validate(VARIABLE)) {
        memory[pos] = val;
    }
}
