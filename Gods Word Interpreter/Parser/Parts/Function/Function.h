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
        const FunctionSignatureP signature;
        const FunctionBodyP body;

        Function(const FunctionSignatureP &signature, const FunctionBodyP &body);

        /*
        To check if two functions are identical,
        one only must check if their signatures are the same
        */
        virtual bool operator==(const Function &func) const final { return func.signature == signature; }

        /*
        To check if two functions are identical,
        one only must check if their signatures are the same
        */
        virtual bool operator!=(const Function &func) const final { return !operator==(func); }

        /*
        To check if two functions are identical,
        one only must check if their signatures are the same
        */
        virtual bool operator==(const Function *func) const final { return operator==(*func); }

        /*
        To check if two functions are identical,
        one only must check if their signatures are the same
        */
        virtual bool operator!=(const Function *func) const final { return !operator==(func); }
    };

    typedef std::shared_ptr<Function> FunctionP;
}

#endif