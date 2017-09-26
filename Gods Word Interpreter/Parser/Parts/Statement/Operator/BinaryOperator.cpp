#include "BinaryOperator.h"

using namespace std;
using namespace GWI;

void BinaryOperator::execute(vector<VariableP> &variables) {
    execute(variables[0], variables[1], variables[2]);
}
