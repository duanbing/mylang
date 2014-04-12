#ifndef _LEX_H_
#define _LEX_H_

#include <stdio.h>
#ifdef _LEX_CPP_
    int lineno=1;
#else
    extern int lineno;
    extern FILE *yyin;
    int yylex();
#endif

#endif
