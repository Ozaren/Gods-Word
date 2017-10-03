#include "LogicOperator.h"

using namespace std;
using namespace GWI;

bool Logic::checkBoolean(const Variable::pointer &var) {
    return *var->type == *def_type::BOOLEAN;
}

bool Logic::checkBoolean(std::initializer_list<const Variable::pointer*> vars) {
    for (const Variable::pointer *v : vars) {
        if (!checkBoolean(*v))
            return false;
    }
    return true;
}

void OperatorAnd::execute(Variable::pointer &left, Variable::pointer &right, Variable::pointer &result) {
    if (checkBoolean({ &left, &right, &result }))
        return;

    result->setValue((void*)(((bool)left->getValue()) && ((bool)(right->getValue()))));
}

void OperatorOr::execute(Variable::pointer &left, Variable::pointer &right, Variable::pointer &result) {
    if (checkBoolean({ &left, &right, &result }))
        return;

    result->setValue((void*)(((bool)left->getValue()) || ((bool)(right->getValue()))));
}

void OperatorNot::execute(Variable::pointer &val, Variable::pointer &result) {
    if (checkBoolean({ &val, &result }))
        return;

    result->setValue((void*)(!((bool)val->getValue())));
}
