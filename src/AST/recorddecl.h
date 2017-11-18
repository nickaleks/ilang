#ifndef ILANG_RECORDDECL_H
#define ILANG_RECORDDECL_H

#include <vector>

#include "node.h"

using std::vector;

class RecordDecl : public ASTNode {
    vector<ASTNode*> refs;

public:
    RecordDecl(const vector<ASTNode*> &refs);
};

#endif //ILANG_RECORDDECL_H