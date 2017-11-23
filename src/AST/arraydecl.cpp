#include <vector>

#include "node.h"
#include "arraydecl.h"

ArrayDecl::ArrayDecl(ASTNode *expression, ASTNode *type): expression(expression), array_type(array_type){
    type = types::Array;
}