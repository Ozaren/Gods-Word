#include "DefualtType.h"

#include "TypeSignature.h"
#include "Type.h"

using namespace std;
__USE_NAMESPACE__

const PtrType def_type::BOOL(new Type(new TypeSignature("boolean", "standard"), ColPtrVariable(), ColConstTypeSignature(), sizeof(bool)));
const PtrType def_type::SINT(new Type(new TypeSignature("integer", "standard"), ColPtrVariable(), ColConstTypeSignature(), sizeof(int)));
const PtrType def_type::UINT(new Type(new TypeSignature("unsigned integer", "standard"), ColPtrVariable(), ColConstTypeSignature(), sizeof(size_t)));
const PtrType def_type::FLOT(new Type(new TypeSignature("float", "standard"), ColPtrVariable(), ColConstTypeSignature(), sizeof(double)));
const PtrType def_type::CHAR(new Type(new TypeSignature("character", "standard"), ColPtrVariable(), ColConstTypeSignature(), sizeof(char)));
const PtrType def_type::STRN(new Type(new TypeSignature("string", "standard"), ColPtrVariable(), ColConstTypeSignature(), sizeof(string)));
