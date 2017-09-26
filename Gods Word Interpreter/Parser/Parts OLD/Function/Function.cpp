#include "Function.h"

using namespace std;

stack<vector<Variable>> Function::callStack;

Function::Function(string _name, FunctionBlock &_body, vector<Type> args)
    : name(_name), arg_types(args), body(_body) {

}

void Function::call(vector<Variable> args) {
    const int len = arg_types.size();

    if (len != args.size())
        return;

    for (int i = 0; i < len; i++) {
        const Variable &v = args[i];
        const Type &t = arg_types[i];
        if (v.type != t) {
            return;
        }
    }

    body.execute(args);
}
