#include "Block.h"

using namespace std;
using namespace GWI;

Block::Block() {

}

Block::Block(vector<Statement::pointer> &statements)
    : contents(statements) {

}

void Block::addStatement(const Statement::pointer statement) {
    contents.push_back(statement);
}

void Block::execute(std::vector<Variable::pointer> &variables) {
    for (Statement::pointer s: contents) {
        s->execute(variables);
    }
}
