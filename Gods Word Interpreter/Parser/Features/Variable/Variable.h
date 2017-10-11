#ifndef __GWI_PARSER_FEATURES_VALUE__VARIABLE_H_
#define __GWI_PARSER_FEATURES_VALUE__VARIABLE_H_

#include <string>
#include <vector>

#include <boost/any.hpp>

#include "../Pointers.h"

__START_NAMESPACE__
enum VarTypes { BOOLEAN, SIGNED_INTEGER, UNSIGNED_INTEGER, FLOAT, CHARACTER, STRING, VARIABLE };

class Variable {
public:
    const PtrType type;

    Variable(PtrType type);

    boost::any get_any(size_t pos);
    template<typename type>
    type get(size_t pos);

    void set(int pos, bool val);
    void set(int pos, int val);
    void set(int pos, size_t val);
    void set(int pos, double val);
    void set(int pos, char val);
    void set(int pos, std::string val);
    void set(int pos, const PtrVariable &val);
    void set(int pos, const PtrType &val);
    void set(int pos, const PtrFunction &val);

private:
    std::vector<VarTypes> types;
    std::vector<boost::any> memory;

    bool validate(VarTypes type);
};
__END_NAMESPACE__

#endif