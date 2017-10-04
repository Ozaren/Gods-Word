#ifndef __GWI_PARSER_PARTS_TYPE__TYPE_FUNCTION_H__
#define __GWI_PARSER_PARTS_TYPE__TYPE_FUNCTION_H__

// #include <memory>

#include "../Function/FunctionSignature.h"
#include "../Function/FunctionBody.h"
#include "../Function/Function.h"

#define GWI_TF_PUB 1
#define GWI_TF_PROT 2
#define GWI_TF_INST 4
#define GWI_TF_INHER 8
#define GWI_TF_ABSTR 16

namespace GWI {
    class TypeFunction : public Function {
    public:
        // typedef std::shared_ptr<TypeFunction> pointer;

        TypeFunction(const FunctionSignature &signature, const FunctionBody &body, int mod);
        TypeFunction(const Function &func, int mod);

        const int mod;

        const bool IS_PUBLIC;
        const bool IS_PROTECTED;
        const bool IS_INSTANCE;
        const bool IS_INHERITABLE;
        const bool IS_ABSTRACT;
    private:
        bool chkMod(int cmod) const;
    };

}

#endif