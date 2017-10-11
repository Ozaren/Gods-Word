#ifndef __GWI_PARSER_FEATURES__POINTERS_H_
#define __GWI_PARSER_FEATURES__POINTERS_H_

#include <memory>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

#define __NAMESPACE__ gwi
#define __START_NAMESPACE__ namespace __NAMESPACE__ {
#define __END_NAMESPACE__ }
#define __USE_NAMESPACE__ using namespace __NAMESPACE__;

__START_NAMESPACE__
/*
Lots of typedefs here for convenience and sidestepping circular references
Put all types here
*/

template<typename T>
using ptr = std::shared_ptr<T>;
template<typename T>
using vec = std::vector<T>;

// Error

// Function
class FunctionBody;
class FunctionSignature;
class Function;

using PtrFunctionBody = ptr<FunctionBody>;
using ConstFunctionBody = ptr<const FunctionBody>;

using PtrFunctionSignature = ptr<FunctionSignature>;
using ConstFunctionSignature = ptr<const FunctionSignature>;

using PtrFunction = ptr<Function>;
using ConstFunction = ptr<const Function>;

// Memory

// Statement
class Statement;
class Block;

using PtrStatement = ptr<Statement>;
using ConstStatement = ptr<const Statement>;

using PtrBlock = ptr<Block>;
using ConstBlock = ptr<const Block>;

// Type
class Type;
class TypeBody;
class TypeSignature;

using PtrType = ptr<Type>;
using ConstType = ptr<const Type>;

using PtrTypeBody = ptr<TypeBody>;
using ConstTypeBody = ptr<const TypeBody>;

using PtrTypeSignature = ptr<TypeSignature>;
using ConstTypeSignature = ptr<const TypeSignature>;
using ColPtrTypeSignature = vec<PtrTypeSignature>;
using ColConstTypeSignature = vec<ConstTypeSignature>;

// Value
class Variable;

using PtrVariable = ptr<Variable>;
using ConstVariable = ptr<const Variable>;
using ColPtrVariable = vec<PtrVariable>;
using ColConstVariable = vec<ConstVariable>;

__END_NAMESPACE__

#endif