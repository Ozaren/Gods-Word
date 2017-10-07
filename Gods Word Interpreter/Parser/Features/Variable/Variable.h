#ifndef __GWI_PARSER_FEATURES_VALUE__VARIABLE_H_
#define __GWI_PARSER_FEATURES_VALUE__VARIABLE_H_

#include <string>

#include "../Pointers.h"

#include "../Memory/linear_memory_buffer.h"

__START_NAMESPACE__
enum VarTypes { BOOLEAN, SIGNED_INTEGER, UNSIGNED_INTEGER, FLOAT, CHARACTER, STRING, VARIABLE };

union VariableValue {
    bool b_val;
    int si_val;
    size_t ui_val;
    double f_val;
    char c_val;
    std::string s_val;
    PtrVariable v_val;
};

struct Value {
    const VariableValue val;
    const VarTypes type;
};

class Variable {
public:
    const PtrType type;

    Value get(int pos);
    void set(int pos, Value val);

private:
    linear_memory_buffer memory;
};
__END_NAMESPACE__

#endif