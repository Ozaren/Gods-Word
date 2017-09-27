#ifndef __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__
#define __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__

#include <vector>
#include <string>

#include "../Statement/Statement.h"
#include "../Statement/Block/Block.h"

#include "FunctionSignature.h"
#include "FunctionBody.h"

namespace GWI {
    class Function {
    public:
        Function(const FunctionSignature &signature, const FunctionBody &body);

        const FunctionSignature &signature;
        const FunctionBody &body;
    };

    typedef std::shared_ptr<Function> FunctionP;
}

#endif