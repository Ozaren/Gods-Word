#ifndef __GWI_PARSER_PARTS_TYPE__FUNCTION_SIGNATURE_H__
#define __GWI_PARSER_PARTS_TYPE__FUNCTION_SIGNATURE_H__

// #include <memory>
#include <string>
#include <vector>

#include "../Type/Type.h"
#include "../Variable/Variable.h"

namespace GWI {
    class FunctionSignature {
    public:
        // typedef std::shared_ptr<FunctionSignature> pointer;

        FunctionSignature(std::string name, std::vector<Type> arg_types);

        const std::string name;
        const std::vector<Type> arg_types;

        bool validateArguments(std::vector<Variable> variables);

        bool operator==(const FunctionSignature &sig) const;
        bool operator!=(const FunctionSignature &sig) const { return !operator==(sig); }
        bool operator==(const FunctionSignature *sig) const { return operator==(*sig); }
        bool operator!=(const FunctionSignature *sig) const { return !operator==(sig); }
    };
}

#endif