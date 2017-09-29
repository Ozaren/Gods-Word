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

        bool operator==(const FunctionSignature &sig) const;
        bool operator!=(const FunctionSignature &sig) const { return !operator==(sig); }
        bool operator==(const FunctionSignature *sig) const { return operator==(*sig); }
        bool operator!=(const FunctionSignature *sig) const { return !operator==(sig); }
    };
    typedef std::shared_ptr<FunctionSignature> FunctionSignatureP;
}

#endif