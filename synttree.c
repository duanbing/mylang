#include <stdio.h>
#include "synttree.h"
#include "symtab.h"


char *name[]={
   "statement list",
   "empty statement",
   "expression statement",
   "print statement",
   "input statement",
   "if..then statement",
   "if..then..else statement",
   "error statement",

   "equals",
   "assign",
   "concatenate",
   "identifier",
   "string constant"
};

int child[] = {
    2,0,1,1,0, 2, 3, 0, 2, 1, 2, 0, 0
};


void SyntShow(struct TreeNode* tree , int level) {
    int i,n1;
    if (tree->type != STMT_LIST) {
	for (i=0;i<level;i++) printf("    ");
        printf("%s",name[tree->type]);
	switch (tree->type) {
	case INPUT_STMT:
	case ASSIGN_EXPR : 
	case IDENT_EXPR : 
  	    printf(" (%s)",tree->symbol->name); break;
	case STR_EXPR: printf(" (\"%s\")",tree->symbol->cont); break; 
	}
	n1 = level + 1;  puts("");
    } else n1 = level;
    for(i=0;i<child[tree->type];i++) SyntShow(tree->child[i], n1);
}

struct TreeNode* newNode(NodeType type,
        struct TreeNode *c1,
        struct TreeNode *c2,
        struct TreeNode *c3) {
    struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode)) ;
    node->type = type;
    node->child[0] = c1;
    node->child[1] = c2;
    node->child[2] = c3;
    return node;
}
