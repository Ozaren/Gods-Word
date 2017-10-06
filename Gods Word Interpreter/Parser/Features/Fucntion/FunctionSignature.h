#ifndef __GWI_PARSER_FEATURES_FUNCTION__FUNCTION_SIGNATURE_H_
#define __GWI_PARSER_FEATURES_FUNCTION__FUNCTION_SIGNATURE_H_

#include <string>

#include "../Pointers.h"

__START_NAMESPACE__

class FunctionSignature {
public:
    const std::string name;
    const ColPtrTypeSignature args;

    FunctionSignature(std::string name, ColPtrTypeSignature &args);
};

__END_NAMESPACE__

#endif