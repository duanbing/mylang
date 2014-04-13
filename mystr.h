#ifndef _MYSTR_H_
#define _MYSTR_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Str {
    char *s;
    int len;
}Str;

void Assign(Str* d,char *src) {
   char *dst = d->s;
   int ld = strlen(dst);
   int ls = strlen(src);
   if(ld >= ls) {
	strncpy(dst,src,ls); 
   }else {
	dst = realloc(dst,ls);
        strncpy(dst,src,ls);
        d->s = dst;
   }
   d->len = ls;
}

void Print(Str *s){
    s->s[s->len] = 0;
    printf("%d %s\n",s->len,s->s);
}

Str* newStr(char *s) {
   Str* sn = (Str*)malloc(sizeof(Str)) ;
   sn->len = strlen(s);
   sn->s = (char*)malloc(sn->len);
   strcpy(sn->s,s); 
   return sn;     
}

Str* newStr2() {
   Str* sn = (Str*)malloc(sizeof(Str)) ;
   sn->len = 1; 
   sn->s = (char*)malloc(sn->len);
   sn->s[0] = 0; 
   return sn;     
}

void freeStr(Str* s) {
   free(s->s); 
   free(s);
   s=NULL;
}

Str* Input () {
    char s[81];
    gets(s);
    return newStr(s);
}

Str* Concatenate (Str* dst,Str* src) {
    int l = dst->len + src->len;
    dst->s = realloc(dst->s,l);
    strcpy(dst->s + dst->len,src->s);
    dst->len = l;
    return dst;
}
#endif
