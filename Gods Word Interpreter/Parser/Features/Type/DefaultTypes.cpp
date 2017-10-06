#include "DefaultTypes.h"
#include "Type.h"

using namespace std;
using namespace GWI;

const PtrType def_type::BOOL(new Type("boolean", "std", ColType(), ColValue(), sizeof(bool)));
const PtrType def_type::SINT(new Type("integer", "std", ColType(), ColValue(), sizeof(bool)));
const PtrType def_type::UINT(new Type("uinteger", "std", ColType(), ColValue(), sizeof(bool)));
const PtrType def_type::FLOT(new Type("float", "std", ColType(), ColValue(), sizeof(bool)));
const PtrType def_type::CHAR(new Type("character", "std", ColType(), ColValue(), sizeof(bool)));
const PtrType def_type::STRN(new Type("boolean", "std", ColType(), ColValue(), sizeof(bool)));