#ifndef ILANG_VAR_H
#define ILANG_VAR_H

#include <string>
#include <vector>

#include "node.h"

using std::string;
using std::pair;

class Var : public ASTNode {
    pair<string, ASTNode*> var_decl;
    ASTNode *body;

public:
    Var(const pair<string, ASTNode*> &var_decl, ASTNode *body);
};

#endif //ILANG_VAR_H