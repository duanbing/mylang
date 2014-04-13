#include <stdio.h>
#include "lex.h"
#include "symtab.h"
#include "synttree.h"
#include "intcode.h"


int errors = 0;
void yyerror(char *s) {
    errors ++;
    fprintf(stderr,"error : %s\n",s);
}

int yywrap() {
    return 1;
}

extern struct TreeNode* tree;
extern struct SymDesc *start;

struct IntInstr *intcode;

main(int argc,char*argv[]){
    yyin = NULL;
    if(argc == 2) {
	yyin = fopen(argv[1],"rt");
    }
    if (yyin == NULL)  yyin = stdin;

    printf("begin to parse\n");
    yyparse();
    printf("%d error(s) found\n",errors);

	
   // SymbShow(start);
   // SyntShow(tree,0);
    intcode = GenIntCode(tree);
    Number(intcode,1);
    IntShow(intcode);
    return errors? 1:0;
}
