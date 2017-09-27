#ifndef __GWI_PARSER_PARTS_TYPE__TYPE_H__
#define __GWI_PARSER_PARTS_TYPE__TYPE_H__

#include <memory>
#include <string>
#include <vector>

namespace GWI {
    class Variable;
    class TypeFunction;

    typedef std::vector<std::shared_ptr<Variable>> VarCol;

    class Type {
    public:
        const int id;
        const std::string name;

        Type(std::string name);

        bool operator==(const Type &t) const { return t.id == id; }
        bool operator!=(const Type &t) const { return !operator==(t); }

        void call(int function, VarCol vars);
        void call(std::string function, VarCol vars);
    private:
        void call(std::shared_ptr<TypeFunction> function, VarCol vars);

        static int next_id;

        VarCol properties;
        std::vector<std::shared_ptr<TypeFunction>> functions;
    };

    typedef std::shared_ptr<Type> TypeP;
}

#endif