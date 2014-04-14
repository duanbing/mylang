#include <string.h>
#include <stdlib.h>
#include "symtab.h"



struct SymDesc* newSymDesc(char *name,SymType type,char *cont,int line) {
    struct SymDesc *ret = (struct SymDesc*) malloc(sizeof(struct SymDesc)) ;
/*
    strcpy(ret->name,name);  ret->type = type;
    if (cont)  strcpy(ret->cont,cont);  
*/
    ret->name = name;  ret->cont = cont;
    ret->line= line;  ret->type = type;
    ret->next=NULL;
    return ret;
}


void show(struct SymDesc *s) {
    if (s->type == STR_CONST) {
	 printf ("| %-20s | %4d | (= \"%s\")\n", s->name, s->line, s->cont);
    } else {
	 printf ("| %-20s | %4d | \n", s->name, s->line);
    }
}

int Add(struct SymDesc** start,struct SymDesc *symb) {
    
    if(Find(*start,symb->name)!=NULL) {
	return -1;
    }

    if (*start == NULL) {
	*start = symb;
    }
    else {
	struct SymDesc *s = *start;
        while(s->next) {
           s=s->next; 
	}
	s->next = symb;
    }
    return 0;
}

struct SymDesc* Find(struct SymDesc* s,char *name) {
    while(s && strcmp(name,s->name)) {
    	s=s->next;
    }
    return s;
}

void SymbShow(struct SymDesc *start)  {
   struct SymDesc *search = start;
   puts ("+----------------------+------+");
   puts ("| Name                 | Line |");
   puts ("+----------------------+------+");
   while (search != NULL)  {
      show (search);
      search = search->next;
   }
   puts ("+----------------------+------+");
}

