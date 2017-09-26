#ifndef __GWI_PARSER_PARTS_TYPE__TYPE_H__
#define __GWI_PARSER_PARTS_TYPE__TYPE_H__

#include <memory>
#include <string>

namespace GWI {
    class Type {
    public:
        Type(std::string name);

        const int id;
        const std::string name;

        bool operator==(const Type &t) const { return t.id == id; }
        bool operator!=(const Type &t) const { return !operator==(t); }
    private:
        static int next_id;
    };

    typedef std::shared_ptr<Type> TypeP;
}

#endif