%{
#include <string.h>
#define _LEX_CPP_
#include "lex.h"
#include "lexsymb.h"

extern int yywrap();

void Identifier();
void StringConstant();
void EatComment();
%}


LETTER [a-zA-Z]
DIGIT [0-9]
INDNT {LETTER}({LETTER}|{DIGIT})*
STR \"[^\"]*\"
WSPACE [ \t]+

%%
"if" {return IF;}
"else" {return ELSE;}
"print"  {return PRINT;}
"input"  {return INPUT;}
"="      {return ASSIGN;}
"=="     {return EQUAL;}
"+"      {return CONCAT;}
";"      {return END_STMT;}
"("      {return OPEN_PAR;}
")"      {return CLOSE_PAR;}
"{"      {return BEGIN_CS;}
"}"      {return END_CS; }

{INDNT} {Identifier(); return ID;}

{STR} {StringConstant(); return STRING;}

"//" {EatComment();}

\n   {lineno++;}

{WSPACE} {}

.	{return ERROR_TOKEN;}

%%


void EatComment() {
    char c;
    while((c=input())!='\n' && c!=0) ;
    lineno++;
}

void Identifier() {
    strcpy(yylval.str,yytext);
    yylval.str[strlen(yytext)] = 0;
}

void StringConstant() {
    int l = strlen(yytext) - 2;
    strncpy(yylval.str,&yytext[1],l);
    yylval.str[l] = 0;
}
