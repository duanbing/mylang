#ifndef _SYMTAB_H_
#define _SYMTAB_H_ 
#include <stdio.h>
#include <string.h>

typedef enum {
    STR_VAR,
    STR_CONST
}SymType;

typedef struct SymDesc{
    char* name;
    char* cont;
    SymType type;
    int line;
    struct SymDesc *next;
   
    int idx;
}SymDesc;


struct SymDesc* newSymDesc(char *name,SymType type,char *cont,int line);
void show(struct SymDesc *s) ;
void SymbShow(struct SymDesc *start);



int Add (struct SymDesc** st,struct SymDesc *s);
struct SymDesc *Find(struct SymDesc* st,char*name);

#endif
