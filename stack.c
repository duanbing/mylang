#include "stack.h"

Stack* newStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->llstart = NULL;
    s->n = 0;
    return s;
}

void Push(Stack** st,T node) {
    Stack* stack = *st;
    ll_link *t = (ll_link*)malloc(sizeof(ll_link));
    t->data = node;
    t->next = stack->llstart ;
    stack->llstart = t;
    stack->n ++;
} 

T GetNo(Stack* stack,int e) {
    int i;
    ll_link *link;
    link = stack->llstart;
    for ( i = stack->n - e - 1;
    	  i-- > 0; 
          link=link->next
    );
    return link->data;
}

T Pop(Stack** st) {
    Stack* stack = *st;
    T rv;
    ll_link *link;
    link = stack->llstart;
    stack->llstart = stack->llstart->next;
    stack->n --;
    rv = link->data;
    free(link);
    return rv;
}

void DoForAllArg (Stack *stack, void (*process)(T,void*),void *arg) {
    ll_link *s;
    s = stack->llstart;
    while(s) {
	process(s->data,arg); s=s->next;
    }
}

void DoForAll(Stack* stack,void(*process)(T)) {
    ll_link *s;
    s = stack->llstart;
    while(s) {
	process(s->data); s = s->next;
    }
}

void Empty(Stack** st) {
    Stack* stack = *st;
    ll_link* s = stack->llstart,*del;
    while(s) {
	del = s;
    	s = s->next;
        free(del);
    }
    stack->llstart=NULL;
    stack->n = 0;
}

void ShowStack(Stack *stack){
    ll_link* s = stack->llstart;
    printf("|| ");
    while(s) {
	printf("%d ",s->data);
        s = s -> next;
    }

    puts("||");
}
