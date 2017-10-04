#include "FunctionSignature.h"
#include "FunctionBody.h"
#include "Function.h"

using namespace std;
using namespace GWI;

FunctionSignature::FunctionSignature(string _name, vector<Type> _arg_types)
    : name(_name), arg_types(_arg_types) {

}

bool FunctionSignature::validateArguments(std::vector<Variable> variables) {
    const int len = arg_types.size();

    if (variables.size() != len) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (arg_types[i] != variables[i].type) {
            return false;
        }
    }

    return true;
}

bool FunctionSignature::operator==(const FunctionSignature &sig) const {
    return sig.name == name && sig.arg_types == arg_types;
}

FunctionBody::FunctionBody(vector<Statement> &statements)
    : Block(statements) {

}

Function::Function(const FunctionSignature &sig, const FunctionBody &_body)
    : signature(sig), body(_body) {

}

void Function::execute(vector<Variable> vars) {
    body.execute(vars);
}