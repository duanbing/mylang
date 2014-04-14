#include "mystr.h" 

void Assign(Str** dd,char *src) {
   Str *d = *dd;
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
   d->s[ls]  = 0;
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

void Input (Str** str) {
    char s[81];
    gets(s);
    *str = newStr(s);
}

Str* Concat (Str* dst,Str* src) {
    int l = dst->len + src->len;
    dst->s = realloc(dst->s,l);
    strcpy(dst->s + dst->len,src->s);
    dst->len = l;
    dst->s[l] = 0;
    return dst;
}
