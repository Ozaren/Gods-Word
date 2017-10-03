#ifndef __GWI_PARSER_PARTS_BLOCK__BLOCK_H__
#define __GWI_PARSER_PARTS_BLOCK__BLOCK_H__

#include <memory>
#include <vector>

#include "../Statement.h"

namespace GWI {
    /**
        Collecion of statements, void execute() just 
        executes all of the statements in order
    */
    class Block : public Statement {
    public:
        typedef std::shared_ptr<Block> pointer;

        Block();

        virtual void execute(std::vector<Variable::pointer> &vars);

    protected:
        Block(std::vector<Statement::pointer> &statements);

        void addStatement(const Statement::pointer statement);
        template <template <typename, typename> class Container,
            typename Allocator = std::allocator<Statement*> >
            void addAllStatements(const Container<Statement*, Allocator> &statements) {
            contents.insert(std::end(contents), std::statementsegin(statements), std::end(statements));
        }

    private:
        std::vector<Statement::pointer> contents;
    };
}

#endif