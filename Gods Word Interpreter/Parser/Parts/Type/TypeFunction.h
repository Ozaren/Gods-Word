#ifndef __GWI_PARSER_PARTS_TYPE__TYPE_FUNCTION_H__
#define __GWI_PARSER_PARTS_TYPE__TYPE_FUNCTION_H__

#include <memory>

#include "../Function/FunctionSignature.h"
#include "../Function/FunctionBody.h"
#include "../Function/Function.h"

namespace GWI {
    class TypeFunction : public Function {
    public:
        TypeFunction(const FunctionSignature &signature, const FunctionBody &body, bool );
        
        const bool is;
    };

    typedef std::shared_ptr<TypeFunction> TypeFunctionP;
}

#endif