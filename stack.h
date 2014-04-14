#ifndef _STATCK_H_
#define _STATCK_H_
#include <stdlib.h>
#include <stdio.h>

typedef int T;

typedef struct ll_link {
    T data;
    struct ll_link *next;   
}ll_link;


typedef struct Stack {
    ll_link* llstart;
    int n;
}Stack;

Stack* newStack();

void Push(Stack** stack,T node) ; 

T GetNo(Stack* stack,int e);

T Pop(Stack** stack) ;

void DoForAllArg (Stack *stack, void (*process)(T,void*),void *arg) ;

void DoForAll(Stack* stack,void(*process)(T)) ;

void Empty(Stack** stack) ;
void ShowStack(Stack*stack);

#endif
