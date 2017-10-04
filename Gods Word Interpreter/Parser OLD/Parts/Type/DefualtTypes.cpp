#include "DefualtTypes.h"

using namespace std;
using namespace GWI;

const Type def_type::BOOLEAN("boolean", sizeof(bool));
const Type def_type::INT("integer", sizeof(int));
const Type def_type::UINT("uinteger", sizeof(unsigned int));
const Type def_type::FLOAT("float", sizeof(double));
const Type def_type::CHAR("character", sizeof(char));
const Type def_type::STRING("string", sizeof(string));