#include "BinaryOperator.h"

using namespace std;
using namespace GWI;

void BinaryOperator::execute(vector<Variable::pointer> &variables) {
    execute(variables[0], variables[1], variables[2]);
}
