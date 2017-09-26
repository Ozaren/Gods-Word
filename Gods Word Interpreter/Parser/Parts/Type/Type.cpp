#include "Type.h"

using namespace std;
using namespace GWI;

int Type::next_id = 0;

Type::Type(string _name)
    : id(next_id++), name(_name) {

}
