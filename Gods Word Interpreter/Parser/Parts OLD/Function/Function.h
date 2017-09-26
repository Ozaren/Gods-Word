#ifndef __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__
#define __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__

#include <stack>
#include <vector>
#include <string>

#include "FunctionBlock.h"

#include "../Type/Type.h"
#include "../Variables/Variable.h"

class Function {
public:
    const std::string name;
    const std::vector<Type> arg_types;
    FunctionBlock &body;

    Function(std::string name, FunctionBlock &body, std::vector<Type> args = std::vector<Type>());

    void call(std::vector<Variable> args);

    static std::stack<std::vector<Variable>> callStack;
};

#endif