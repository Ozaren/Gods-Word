#include "Variable.h"

using namespace GWI;

Variable::Variable(const TypeP &_type, void *_value)
    : type(_type), value(_value) {
    
}
