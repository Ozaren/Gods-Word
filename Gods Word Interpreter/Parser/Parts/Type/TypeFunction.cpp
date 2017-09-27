#include "TypeFunction.h"

using namespace std;
using namespace GWI;

bool TypeFunction::chkMod(int cmod) const {
    return (mod & cmod) != 0;
}

TypeFunction::TypeFunction(const FunctionSignatureP &sig, const FunctionBodyP &body, int _mod) 
    : Function(sig, body)
    , mod(_mod)
    , IS_PUBLIC(chkMod(GWI_TF_PUB)) 
    , IS_PROTECTED(chkMod(GWI_TF_PROT))
    , IS_INSTANCE(chkMod(GWI_TF_INST))
    , IS_INHERITABLE(chkMod(GWI_TF_INHER))
    , IS_ABSTRACT(chkMod(GWI_TF_ABSTR)) {

}