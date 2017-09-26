#include "FunctionBlock.h"

using namespace std;

FunctionBlock::FunctionBlock() {

}

void FunctionBlock::execute(vector<Variable> args) {
    for (Block *b : statements) {
        b->execute(args);
    }
}
