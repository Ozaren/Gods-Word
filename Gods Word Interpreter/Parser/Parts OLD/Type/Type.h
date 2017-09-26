#ifndef __GWI_PARSER_PARTS_TYPE__TYPE_H__
#define __GWI_PARSER_PARTS_TYPE__TYPE_H__

#include <string>
#include <functional>
#include <ostream>

class Type {
public:
    Type(std::string _name)
        : name(_name), id(next_id++) {}

    bool operator==(const Type &type) const { return id == type.id; }
    bool operator!=(const Type &type) const { return !operator==(type); }
    const std::string name;
    const int id;
private:
    static int next_id;
};

#endif