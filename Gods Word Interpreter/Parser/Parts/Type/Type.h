#ifndef __GWI_PARSER_PARTS_TYPE__TYPE_H__
#define __GWI_PARSER_PARTS_TYPE__TYPE_H__

#include <memory>
#include <string>
#include <vector>

namespace GWI {
    class Variable;
    class Function;
    class TypeFunction;

    typedef std::vector<std::shared_ptr<Variable>> VarCol;

    class Type {
    public:
        typedef std::shared_ptr<Type> pointer;

        const int id;
        const std::string name;

        Type(std::string name, size_t known_size = -1);

        bool operator==(const Type &t) const { return t.id == id; }
        bool operator!=(const Type &t) const { return !operator==(t); }
        bool operator==(const Type *t) const { return operator==(*t); }
        bool operator!=(const Type *t) const { return !operator==(t); }

        bool addFunction(std::shared_ptr<Function> function, int mod);

        void call(int function, VarCol &vars);
        void call(std::string function, VarCol &vars);

        size_t object_size();
    private:
        static int next_id;
        size_t known_size;

        VarCol static_properties;
        std::vector<Type::pointer> object_properties;
        std::vector<std::shared_ptr<TypeFunction>> functions;

        void call_help(std::shared_ptr<TypeFunction> function, VarCol &vars);
    };
}

#endif