# 一个简单的脚本引擎

## 词法分析器
`symtab.c`

## 语法分线器
`synntree.c`

## 中间代码生成
`intcode.c`
<pre>
./lang test.txt2 
begin to parse
name : [a] []
name : [b] []
name : [a] []
name : [b] []
0 error(s) found
 1: OP_NOP 
 2: OP_PUSH a 
 3: OP_PUSH b 
 4: OP_STR_EQUAL 
 5: OP_JMPF 9
 6: OP_PUSH a 
 7: OP_DISCARD 
 8: OP_JMP 12
 9: JUMPTARGET 5
10: OP_PUSH b 
11: OP_DISCARD 
12: JUMPTARGET 8
<pre>

## 虚拟机

## 可执行代码



