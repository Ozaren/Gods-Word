#ifndef __GWI_PARSER_PARTS_TYPE__FUNCTION_SIGNATURE_H__
#define __GWI_PARSER_PARTS_TYPE__FUNCTION_SIGNATURE_H__

#include <memory>
#include <string>
#include <vector>

#include "../Type/Type.h"
#include "../Variable/Variable.h"

namespace GWI {
    class FunctionSignature {
    public:
        FunctionSignature(std::string name, std::vector<TypeP> arg_types);

        const std::string name;
        const std::vector<TypeP> arg_types;

        bool validateArguments(std::vector<VariableP> variables);
    };
    typedef std::shared_ptr<FunctionSignature> FunctionSignatureP;
}

#endif