#include "UnaryOperator.h"

using namespace std;
using namespace GWI;

void UnaryOperator::execute(vector<Variable::pointer> &variables) {
    execute(variables[0], variables[1]);
}
