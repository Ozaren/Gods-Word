#include "Block.h"

using namespace std;
using namespace GWI;

Block::Block() {

}

Block::Block(vector<Statement> &statements)
    : contents(statements) {

}

void Block::addStatement(const Statement &statement) {
    contents.push_back(statement);
}

void Block::execute(std::vector<Variable> &variables) {
    for (Statement &s: contents) {
        s.execute(variables);
    }
}
