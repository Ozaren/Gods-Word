#ifndef __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__
#define __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__

#include <memory>
#include <vector>
#include <string>

#include "FunctionSignature.h"
#include "FunctionBody.h"

namespace GWI {
    class Function {
    public:
        typedef std::shared_ptr<Function> pointer;

        const FunctionSignature::pointer signature;
        const FunctionBody::pointer body;

        Function(const FunctionSignature::pointer &signature, const FunctionBody::pointer &body);

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
}

#endif