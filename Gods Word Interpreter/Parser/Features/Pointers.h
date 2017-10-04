#ifndef __GWI_PARSER_FEATURES__POINTERS_H_
#define __GWI_PARSER_FEATURES__POINTERS_H_

#include <memory>
#include <vector>

namespace GWI {
    /*
    Lots of typedefs here for convenience and sidestepping circular references
    Put all types here
    */
    // Error

    // Function
    class FunctionBody;
    class FunctionSignature;

    typedef std::shared_ptr<FunctionBody> PtrFunctionBody;
    typedef std::shared_ptr<FunctionSignature> PtrFunctionSignature;

    // Memory
    
    // Statement
    class Statement;
    class Block;

    typedef std::shared_ptr<Statement> PtrStatement;
    typedef std::shared_ptr<Block> PtrBlock;

    // Type
    class Type;
    class TypeBody;
    class TypeSignature;

    typedef std::shared_ptr<Type> PtrType;
    typedef std::shared_ptr<TypeBody> PtrTypeBody;
    typedef std::shared_ptr<TypeSignature> PtrTypeSignature;

    typedef std::vector<TypeSignature>& ColTypeSignature;

    // Value
    class Value;

    typedef std::shared_ptr<Value> PtrValue;

    typedef std::vector<Value>& ColValue;
}

#endif