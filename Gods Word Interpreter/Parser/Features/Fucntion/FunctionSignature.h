#ifndef __GWI_PARSER_FEATURES_FUNCTION__FUNCTION_SIGNATURE_H_
#define __GWI_PARSER_FEATURES_FUNCTION__FUNCTION_SIGNATURE_H_

#include <string>

#include "../Pointers.h"

namespace GWI {
    class FunctionSignature {
    public:
        const std::string name;
        const ColType args;
    };
}

#endif