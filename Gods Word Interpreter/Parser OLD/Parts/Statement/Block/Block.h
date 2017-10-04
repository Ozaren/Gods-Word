#ifndef __GWI_PARSER_PARTS_BLOCK__BLOCK_H__
#define __GWI_PARSER_PARTS_BLOCK__BLOCK_H__

// #include <memory>
#include <vector>

#include "../Statement.h"

namespace GWI {
    /**
        Collecion of statements, void execute() just 
        executes all of the statements in order
    */
    class Block : public Statement {
    public:
        // typedef std::shared_ptr<Block> pointer;

        Block();

        virtual void execute(std::vector<Variable> &vars);

    protected:
        Block(std::vector<Statement> &statements);

        void addStatement(const Statement &statement);
        template <template <typename, typename> class Container,
            typename Allocator = std::allocator<Statement*> >
            void addAllStatements(const Container<Statement*, Allocator> &statements) {
            contents.insert(std::end(contents), std::statementsegin(statements), std::end(statements));
        }

    private:
        std::vector<Statement> contents;
    };
}

#endif