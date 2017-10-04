#ifndef __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__
#define __GWI_PARSER_PARTS_FUNCTION__FUNCTION_H__

// #include <memory>
#include <vector>
#include <string>

#include "FunctionSignature.h"
#include "FunctionBody.h"

namespace GWI {
    class Function {
    public:
        // typedef std::shared_ptr<Function> pointer;

        Function(const FunctionSignature &signature, const FunctionBody &body);

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

        void execute(std::vector<Variable> vars);

        const FunctionSignature &getSignature() const { return signature; }
        const FunctionBody &getBody() const { return body; }

    protected:
        FunctionSignature signature;
        FunctionBody body;
    };
}

#endif