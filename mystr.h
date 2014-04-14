#ifndef _MYSTR_H_
#define _MYSTR_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Str {
    char *s;
    int len;
}Str;

void Assign(Str** d,char *src) ;


Str* newStr(char *s) ;

Str* newStr2() ;

void freeStr(Str* s) ;

void Input (Str**s) ;

Str* Concat (Str* dst,Str* src) ;

#endif
