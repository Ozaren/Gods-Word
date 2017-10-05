#include "Block.h"

using namespace std;
using namespace GWI;

void Block::execute(ColValue &vars) {
    for (PtrStatement &stm: statements) {
        stm->execute(vars);
    }
}
