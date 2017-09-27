#include "Type.h"
#include "TypeFunction.h"
#include "../Variable/Variable.h"

using namespace std;
using namespace GWI;

int Type::next_id = 0;

Type::Type(string _name)
    : id(next_id++), name(_name) {

}

void Type::call(int function, VarCol vars) {
    call(functions[function], vars);
}

void Type::call(std::string function, VarCol vars) {
    for (TypeFunctionP func : functions) {
        if (func->signature.name == function) {
            call(func, vars);
            return;
        }
    }
}

void Type::call(std::shared_ptr<TypeFunction> function, VarCol vars) {
    function->body.execute(vars);
}
