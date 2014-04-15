# 一个简单的脚本引擎

## 使用

### build
<pre>
   git clone https://github.com/duanbing/mylang.git
   cd mylang
   make
</pre>

###run
<pre>
./lang test.txt
</pre>

##源码说明

### 词法分析器
`symtab.c`

### 语法分析器
`synntree.c`

### 中间代码生成
`intcode.c`
<pre>
./lang test.txt2 
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

</pre>

### 虚拟机
vm.c
mystr和stack是一个简单的辅助类



