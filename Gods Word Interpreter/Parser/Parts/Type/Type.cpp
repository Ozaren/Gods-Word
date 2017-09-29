#include "Type.h"
#include "TypeFunction.h"
#include "../Variable/Variable.h"

using namespace std;
using namespace GWI;

int Type::next_id = 0;

Type::Type(string _name)
    : id(next_id++), name(_name) {

}

bool Type::addFunction(std::shared_ptr<Function> func, int mod) {
    if (std::find(functions.begin(), functions.end(), func) != functions.end())
        return false;

    TypeFunctionP t_func(TypeFunctionP(new TypeFunction(*func, mod)));

    functions.push_back(t_func);

    return true;
}

void Type::call(int function, VarCol vars) {
    call(functions[function], vars);
}

void Type::call(std::string function, VarCol vars) {
    for (TypeFunctionP func : functions) {
        if (func->signature->name == function) {
            call(func, vars);
            return;
        }
    }
}

void Type::call(std::shared_ptr<TypeFunction> function, VarCol vars) {
    function->body->execute(vars);
}
