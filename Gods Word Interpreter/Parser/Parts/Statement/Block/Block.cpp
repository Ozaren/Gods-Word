#include "Block.h"

using namespace std;
using namespace GWI;

Block::Block() {

}

Block::Block(vector<StatementP> &statements) 
    : contents(statements) {

}

void Block::addStatement(const StatementP statement) {
    contents.push_back(statement);
}

void Block::execute(std::vector<VariableP> &variables) {
    for (StatementP s: contents) {
        s->execute(variables);
    }
}
