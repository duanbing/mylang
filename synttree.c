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

int CoerceToString (struct TreeNode *tree,int childno) {
    if(tree->child[childno]->rettype == T_STRING) return 1;
    if(tree->child[childno]->rettype != T_BOOL) return 0;
    tree->child[childno] = newNode(COERCE_TO_STR,tree->child[childno],NULL,NULL); 
    return 1;
}

void Check(struct TreeNode* tree) {
    switch (tree->type) {
    case STMT_LIST: case EMPTY_STMT: case EXPR_STMT:
    case PRINT_STMT: case INPUT_STMT: case IFTHEN_STMT:
    case IFTHENELSE_STMT: case ERROR_STMT:
        tree->rettype = T_VOID;  // statements have no value
        break;
    case EQUAL_EXPR:
        tree->rettype = T_BOOL;
        break;
    case CONCAT_EXPR:
    case ASSIGN_EXPR:
        tree->rettype = T_STRING;
        break;
    case IDENT_EXPR:
    case STR_EXPR:
        tree->rettype = T_STRING;
        break;
    case COERCE_TO_STR:
        tree->rettype = T_STRING;
    }

    switch (tree->type)  {
    case IFTHEN_STMT :
    case IFTHENELSE_STMT:
	if (tree->child[0]->rettype != T_BOOL) {
    	     yyerror("if: condition should be boolean");
        } 
        break;
    case EQUAL_EXPR : 
	if (tree->child[0]->rettype != tree->child[1]->rettype) {
	    yyerror("==: different types"); 
	}
        break;
    case CONCAT_EXPR : 
	// Note: these error messages should never appear
      if (!CoerceToString (tree,0))   
         yyerror ("+: Can't coerce first argument to string");
      if (!CoerceToString (tree,1))   
         yyerror ("+: Can't coerce second argument to string");
      break;
   case ASSIGN_EXPR: // coerce expression to string
      if (!CoerceToString (tree,0))   
         yyerror ("=: Can't coerce to string");
      break;
    }
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
    Check(node);
    return node;
}
