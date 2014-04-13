#ifndef _INTCODE_H_
#define _INTCODE_H_
typedef enum {
    OP_NOP,
    OP_PUSH,
    OP_GETTOP,
    OP_DISCARD,
    OP_PRINT,
    OP_INPUT,
    OP_JMP,
    OP_JMPF,
    OP_STR_EQUAL,
    OP_BOOL_EQUAL,
    OP_CONCAT,
    OP_BOOL2STR,
    JUMPTARGET
}Opcode;

typedef struct IntInstr {
    int n;
    Opcode opcode ;
    SymDesc *str;
    struct IntInstr *target ;
    struct IntInstr *next;
}IntInstr;

struct IntInstr* newIntInstr(Opcode opcode,SymDesc *str,struct IntInstr* target);

struct IntInstr *GenIntCode(struct TreeNode* tree);
int Len(IntInstr*);

void Number(struct IntInstr *num,int);
void IntShow(struct IntInstr *);

void freeIntCode(struct IntInstr*);
#endif 
