%{
#include <string.h>
#include "lex.h"
#include "symtab.h"
#include "synttree.h"

struct TreeNode* tree = NULL;
struct SymDesc *start = NULL;


void yyerror(char *s);
char *MakeName();


%}

%union {
    char str[256];
    SymDesc *symbol;
    struct TreeNode *tnode;
};

%token ERROR_TOKEN IF ELSE PRINT INPUT ASSIGN  EQUAL
%token CONCAT END_STMT OPEN_PAR CLOSE_PAR
%token BEGIN_CS END_CS
%token <str> ID STRING

%type <symbol> identifier string
%type <tnode>  program statement_list statement
%type <tnode>  if_statement optional_else_statement compound_statement
%type <tnode>  expression equal_expression assign_expression
%type <tnode>  concat_expression simple_expression


%expect 1

%%

program : 
	statement_list  { tree=$1; }
	;

statement_list : 
	statement_list statement { $$ = newNode(STMT_LIST,$1,$2,NULL); }
	|     { $$ = newNode(EMPTY_STMT,NULL,NULL,NULL); }
	;
statement : 
	END_STMT	{ $$=newNode(EMPTY_STMT,NULL,NULL,NULL); }
	| expression END_STMT  { $$=newNode(EXPR_STMT,$1,NULL,NULL);}
	| PRINT expression END_STMT {  $$=newNode(PRINT_STMT,$2,NULL,NULL);} 
	| INPUT identifier END_STMT {  $$=newNode(INPUT_STMT,NULL,NULL,NULL);$$->symbol=$2;}
	| if_statement { $$=$1;}
	| compound_statement  { $$ = $1; }
	| error END_STMT { $$=newNode(ERROR_STMT,NULL,NULL,NULL);}
    ;

if_statement :
	IF OPEN_PAR expression CLOSE_PAR statement optional_else_statement 
	{
	    if ($6 !=  NULL) $$ = newNode (IFTHENELSE_STMT,$3,$5,$6);
	    else $$ = newNode(IFTHEN_STMT,$3,$5,NULL);
	}
	;

optional_else_statement :
	ELSE statement {$$=$2;}
	|   {$$=NULL;}
	;

expression :
	 equal_expression { $$=$1;}
	;

compound_statement : 
	BEGIN_CS statement END_CS {$$=$2;}
	;

equal_expression : 
	expression EQUAL assign_expression { $$ = newNode(EQUAL_EXPR,$1,$3,NULL);}
	|assign_expression {$$=$1;}
	;

assign_expression :
	identifier ASSIGN assign_expression {$$ = newNode(ASSIGN_EXPR,$3,NULL,NULL); $$->symbol = $1;}
	| concat_expression {$$=$1;}
	;

concat_expression :
	 concat_expression CONCAT simple_expression { $$=newNode(CONCAT_EXPR,$1,$3,NULL); }
	| simple_expression   { $$=$1; }
	;

simple_expression : 
	identifier {$$=newNode(IDENT_EXPR,NULL,NULL,NULL); $$->symbol=$1;}
	| string  {$$=newNode(STR_EXPR,NULL,NULL,NULL); $$->symbol=$1;}
	| OPEN_PAR expression CLOSE_PAR {$$=$2;}
	;
identifier :
	ID 
	{
	    $$ = Find(start,$1);
	    if ($$ ==NULL) {
	    	$$=newSymDesc($1,STR_VAR,NULL,lineno);
		Add(start,$$);
	    }
	}
	;

string :
	STRING 
	{
	    $$ = newSymDesc(MakeName(),STR_CONST,$1,lineno);	
	    Add(start,$$);
	}

%%

char *MakeName() {
    char *name = (char*)malloc(10);
    static n = 0; 
    char num[4];
    sprintf(num,"%d",++n); 
    strcpy(name,"strconst"); strcat(name,num);
    return name;
}
