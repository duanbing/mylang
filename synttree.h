
#ifndef _SYNTTREE_
#define _SYNTTREE_

#include "symtab.h"

typedef enum {
    STMT_LIST ,
    EMPTY_STMT,
    EXPR_STMT,
    PRINT_STMT,
    INPUT_STMT,
    IFTHEN_STMT,
    IFTHENELSE_STMT,
    ERROR_STMT,

    EQUAL_EXPR,
    ASSIGN_EXPR,
    CONCAT_EXPR,
    IDENT_EXPR,
    STR_EXPR
}NodeType;


typedef struct TreeNode {
    NodeType type;
    struct SymDesc *symbol;
    struct TreeNode *child[3];
}TreeNode;

struct TreeNode* newNode(NodeType type,struct TreeNode *,
	struct TreeNode *,
	struct TreeNode *);

void SyntShow(struct TreeNode*, int );



#endif

