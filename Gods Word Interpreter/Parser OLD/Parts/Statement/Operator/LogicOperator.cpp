#include "LogicOperator.h"

using namespace std;
using namespace GWI;

bool Logic::checkBoolean(const Variable &var) {
    return var.type == def_type::BOOLEAN;
}

bool Logic::checkBoolean(std::initializer_list<const Variable*> vars) {
    for (const Variable *v : vars) {
        if (!checkBoolean(*v))
            return false;
    }
    return true;
}

void OperatorAnd::execute(Variable &left, Variable &right, Variable &result) {
    if (checkBoolean({ &left, &right, &result }))
        return;

    result.setValue((void*)(((bool)left.getValue()) && ((bool)(right.getValue()))));
}

void OperatorOr::execute(Variable &left, Variable &right, Variable &result) {
    if (checkBoolean({ &left, &right, &result }))
        return;

    result.setValue((void*)(((bool)left.getValue()) || ((bool)(right.getValue()))));
}

void OperatorNot::execute(Variable &val, Variable &result) {
    if (checkBoolean({ &val, &result }))
        return;

    result.setValue((void*)(!((bool)val.getValue())));
}
