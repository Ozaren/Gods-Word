#include "DefualtTypes.h"

using namespace std;
using namespace GWI;

const Type::pointer def_type::BOOLEAN(new Type("boolean"), sizeof(bool));
const Type::pointer def_type::INT(new Type("integer"), sizeof(int));
const Type::pointer def_type::UINT(new Type("uinteger"), sizeof(unsigned int));
const Type::pointer def_type::FLOAT(new Type("float"), sizeof(double));
const Type::pointer def_type::CHAR(new Type("character"), sizeof(char));
const Type::pointer def_type::STRING(new Type("string"), sizeof(string));