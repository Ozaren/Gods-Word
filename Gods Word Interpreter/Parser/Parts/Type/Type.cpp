#include "Type.h"
#include "TypeFunction.h"
#include "../Variable/Variable.h"

using namespace std;
using namespace GWI;

int Type::next_id = 0;

Type::Type(string _name, size_t _known_size)
    : id(next_id++), name(_name), known_size(_known_size){

}

bool Type::addFunction(shared_ptr<Function> func, int mod) {
    if (std::find(functions.begin(), functions.end(), func) != functions.end())
        return false;

    TypeFunction::pointer t_func(TypeFunction::pointer(new TypeFunction(*func, mod)));

    functions.push_back(t_func);

    return true;
}

void Type::call(int function, VarCol &vars) {
    call_help(functions[function], vars);
}

void Type::call(std::string function, VarCol &vars) {
    for (TypeFunction::pointer func : functions) {
        if (func->signature->name == function) {
            call_help(func, vars);
            return;
        }
    }
}

void Type::call_help(shared_ptr<TypeFunction> function, VarCol &vars) {
    function->body->execute(vars);
}

size_t Type::object_size() {
    return known_size;
}

/*
size_t Type::object_size() {
    if (known_size == -1) {
        size_t object_size = sizeof(Type);

        for (Type::pointer &type : object_properties)
            object_size += type->object_size();

        return object_size;
    }
    else {
        return known_size;
    }
}
*/