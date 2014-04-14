#include <string.h>
#include "vm.h"
#include "symtab.h"

Instr newInstr(Opcode opcode,int operand) {
    Instr n;
    n.opcode=opcode;
    n.operand=operand;
    return n;
}

VMachine* newVMachine() {
    VMachine* s = (VMachine*) malloc(sizeof(VMachine));
    s->instr = NULL;
    s->ninstr = 0;
    s->stack = NULL;
    return s;
}

void Reset(VMachine* vm) {
    int i=0;
    for (; i<MAX_STR;i++) {
	if(vm->str[i]!=NULL) {
            if(vm->str[i]) {
		free(vm->str[i]);  vm->str[i] = NULL;    
	    } 
  	}
	if(vm->instr) { 
      	    free(vm->instr); vm->instr = NULL; vm->ninstr = 0;
	}
        Empty(vm->stack);
    }
}

extern SymDesc* start;
extern IntInstr* intcode;

void Read(VMachine** pvm) {
    VMachine*vm = *pvm;
    int i=0;
    SymDesc* s= start;
    while(s) {
	if (s->cont) vm->str[i] = newStr(s->cont);
        else vm->str[i] = newStr2();
        s->idx = i ++;
        s = s->next; 
    }
    vm->ninstr = Len(intcode);
    vm->instr = (Instr*)malloc(vm->ninstr * sizeof(Instr));
    IntInstr *cinstr = intcode;

    for (i=0;i<vm->ninstr;i++) {
	switch (cinstr->opcode) {
	case OP_NOP : vm->instr[i] = newInstr(OP_NOP,0); break;
	case OP_PUSH : vm->instr[i] = newInstr(OP_PUSH,cinstr->str->idx);break;
	case OP_GETTOP : vm->instr[i] = newInstr(OP_GETTOP,cinstr->str->idx); break;
	case OP_DISCARD : vm->instr[i] = newInstr(OP_DISCARD,0);break;
	case OP_PRINT : vm->instr[i] = newInstr(OP_PRINT,0); break;
	case OP_INPUT : vm->instr[i] = newInstr(OP_INPUT,cinstr->str->idx); break;
	case OP_JMP : vm->instr[i] = newInstr(OP_JMP,cinstr->target->n - i); break;
	case OP_JMPF : vm->instr[i] = newInstr(OP_JMPF,cinstr->target->n - i);  break;
	case OP_STR_EQUAL : vm->instr[i] = newInstr(OP_STR_EQUAL,0);break;
	case OP_BOOL_EQUAL : vm->instr[i] = newInstr(OP_BOOL_EQUAL,0);break;
	case OP_CONCAT :  vm->instr[i] = newInstr(OP_CONCAT,0); break;
	case OP_BOOL2STR : vm->instr[i] = newInstr(OP_BOOL2STR,0);break;
	case JUMPTARGET : vm->instr[i] = newInstr(OP_NOP,0);break;
  	}
        cinstr = cinstr->next;
    }
}
int getFreeStr(VMachine* vm) {
    int i=0;
    for(i=0;i<MAX_STR;++i) {
	if (vm->str[i] == NULL) {
	    vm->str[i] = newStr2();
 	    break;
  	}
    }
    return i == MAX_STR ? -1 : i;
}
int newTmpCopyI(VMachine* vm , int j) {
    int i = getFreeStr(vm);
    if (i >= 0) Assign(vm->str[i],vm->str[j]->s); 
    return i;
}

int newTmpCopyS(VMachine*vm,char *s) {
    int i = getFreeStr(vm);
    if(i>=0) Assign(vm->str[i],s);
    return i;
}

void delTmp(VMachine*vm, int i) {
    if (vm->str[i]) {
	free(vm->str[i]); vm->str[i] = NULL;
    }
}

void Execute(VMachine *vm) {
    int ip;
    VM_Stack* stack = newStack();
    int ipc;
    int i,j,k;

    ip=0;
    while(ip < vm->ninstr) {
	ipc = 1;
     	switch (vm->instr[ip].opcode) {
	    case OP_NOP:	break;
	    case OP_PUSH :  Push(stack,newTmpCopyI(vm,vm->instr[ip].operand)); break;
	    case OP_GETTOP : Assign(vm->str[vm->instr[ip].operand],vm->str[stack->llstart->data]->s); break;
	    case OP_DISCARD : delTmp(vm,Pop(stack)); break;
	    case OP_PRINT : i = Pop(stack); Print(vm->str[i]); delTmp(vm,i); break;
	    case OP_INPUT : Input(vm->str[vm->instr[ip].operand]); break;
	    case OP_JMP : ipc = vm->instr[ip].operand; break;
	    case OP_JMPF : i = Pop(stack); if (i == ST_FALSE) ipc = vm->instr[ip].operand; break;
	    case OP_STR_EQUAL : i = Pop(stack); j = Pop(stack);
		 if(strcmp(vm->str[i]->s,vm->str[j]->s) == 0) 
			k = ST_TRUE;  
		 else k = ST_FALSE ;
		 delTmp(vm,i);delTmp(vm,j); Push(stack,k); break;
	    case OP_BOOL_EQUAL : i = Pop(stack); j = Pop(stack);
		if (i == j) k = ST_TRUE ;  else k = ST_FALSE;
	        Push(stack,k); break;
 	    case OP_BOOL2STR : i = Pop(stack);
		if (i == ST_FALSE) i = newTmpCopyS(vm,"false");
		else i = newTmpCopyS(vm,"true");
		Push(stack,i);
		break;
	    case OP_CONCAT : i = Pop(stack); j = Pop(stack);	
		k = newTmpCopyI(vm,j); Concat(vm->str[k],vm->str[i]);
		delTmp(vm,i);delTmp(vm,j); Push(stack,k); break;
   	}
        ip += ipc;
    }
}




