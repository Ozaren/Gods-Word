#include "UnaryOperator.h"

using namespace std;
using namespace GWI;

void UnaryOperator::execute(vector<VariableP> &variables) {
    execute(variables[0], variables[1]);
}
