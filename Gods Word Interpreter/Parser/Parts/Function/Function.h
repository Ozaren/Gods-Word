#ifndef __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__
#define __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__

#include <vector>
#include <string>

#include "../Statement/Statement.h"
#include "../Statement/Block/Block.h"

namespace GWI {
    class FunctionSignature {
    public:
        FunctionSignature(std::string name, std::vector<TypeP> arg_types);

        const std::string name;
        const std::vector<TypeP> arg_types;

        bool validateArguments(std::vector<VariableP> variables);
    };

    class FunctionBody : public Block {
    public:
        FunctionBody(std::vector<StatementP> &statements);
    };

    class Function {
    public:
        Function(const FunctionSignature &signature, const FunctionBody &body);

        const FunctionSignature &signature;
        const FunctionBody &body;
    };
}

#endif