#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "mystr.h"
//#include "stack.h"

char *s = NULL;
char *news () {

   char*a = (char*)malloc(10);
   strcpy(a,"111");
   return a;
}

void ass(char **s,char *s2) {
    *s = s2;
}

int main() {
   char *s = news();
   char *s2 = NULL;  ass(&s2,s);
   printf("%s\n",s2);
/*
   Str *i = Input();
   Str *o = newStr("xxxxxxxxxxxxxxx");
   Concatenate(i,o);
   Print(i);
   freeStr(i);
   Stack *s = newStack(); 
   T a = 10;
   Push(s,a) ;
   a= 100;
   
   Push(s,a) ;
printf("%d\n",s->n);
   printf("%d\n",Pop(s));
   T b = GetNo(s,1);
   printf("%d\n",b); 
*/
   
   return 0;
}
