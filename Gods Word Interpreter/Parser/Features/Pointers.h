#ifndef __GWI_PARSER_FEATURES__POINTERS_H_
#define __GWI_PARSER_FEATURES__POINTERS_H_

#include <memory>
#include <vector>

namespace GWI {
    /*
    Lots of typedefs here for convenience and sidestepping circular references
    Put all types here
    */

    template<typename T>
    using collection = std::vector<T>;
    template<typename T>
    using ptr = std::shared_ptr<T>;

    // Error

    // Function
    class FunctionBody;
    class FunctionSignature;

    using PtrFunctionBody = ptr<FunctionBody>;
    using PtrFunctionSignature = ptr<FunctionSignature>;

    // Memory

    // Statement
    class Statement;
    class Block;

    using PtrStatement = ptr<Statement>;
    using PtrBlock = ptr<Block>;

    using ColStatement = collection<PtrStatement>;

    // Type
    class Type;

    using PtrType = ptr<Type>;

    using ColType = collection<PtrType>;

    // Value
    class Value;

    using PtrValue = ptr<Value>;

    using ColValue = collection<PtrValue>;
}

#endif