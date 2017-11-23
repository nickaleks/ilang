#ifndef ILANG_ARRAY_H
#define ILANG_ARRAY_H

#include "node.h"
#include "type.h"

class ArrayDecl : public Type {

public:
    ASTNode *expression;
    Type *array_type;
    ArrayDecl(ASTNode *expression, Type *array_type);
};

#endif //ILANG_ARRAY_H
