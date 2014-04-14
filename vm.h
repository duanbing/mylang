#ifndef _VM_H_
#define _VM_H_

#include "stack.h"
#include "mystr.h"
#include "synttree.h"
#include "intcode.h"


typedef struct Instr {
    Opcode opcode;
    int operand;
}Instr;

Instr newInstr(Opcode opcode,int operand);

typedef Stack VM_Stack;

#define ST_TRUE  (-1)
#define	  ST_FALSE  (-2)
#define	  MAX_STR  100

typedef struct VMachine {
    Instr *instr;
    int ninstr;
    Str *str[MAX_STR];
    VM_Stack* stack;
}VMachine;

VMachine* newVMachine();

void Reset(VMachine*);
void Read(VMachine**);
void Execute(VMachine*);

#endif
