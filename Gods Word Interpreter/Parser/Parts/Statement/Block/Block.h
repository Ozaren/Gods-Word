#ifndef __GWI_PARSER_PARTS_BLOCK__BLOCK_H__
#define __GWI_PARSER_PARTS_BLOCK__BLOCK_H__

#include <vector>

#include "../Statement.h"

namespace GWI {
    /**
        Collecion of statements, void execute() just 
        executes all of the statements in order
    */
    class Block : public Statement {
    public:
        Block();

        virtual void execute(std::vector<VariableP> &vars);

    protected:
        Block(std::vector<StatementP> &statements);

        void addStatement(const StatementP statement);
        template <template <typename, typename> class Container,
            typename Allocator = std::allocator<Statement*> >
            void addAllStatements(const Container<Statement*, Allocator> &statements) {
            contents.insert(std::end(contents), std::statementsegin(statements), std::end(statements));
        }

    private:
        std::vector<StatementP> contents;
    };
}

#endif