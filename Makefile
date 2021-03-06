target=lang
CC=gcc
obj=main.o lex.yy.o string.tab.o  synttree.o symtab.o intcode.o vm.o  stack.o mystr.o
$(target) : $(obj) 
	$(CC) -o $(target) $(obj) 

lex.yy.o : lex.yy.c lex.h lexsymb.h  
	$(CC) -c lex.yy.c
stack.o : stack.c stack.h
	$(CC) -c stack.c
mystr.o : mystr.c mystr.h
	$(CC) -c mystr.c
symtab.o : symtab.c symtab.h
	$(CC) -c symtab.c
synttree.o : synttree.c synttree.h
	$(CC) -c synttree.c
intcode.o : intcode.c intcode.h synttree.h symtab.h
	$(CC) -c intcode.c
vm.o : vm.c vm.h mystr.c mystr.h stack.h stack.c
	$(CC) -c vm.c 
main.o : main.c lex.h string.tab.h lexsymb.h vm.h
	$(CC) -c  main.c
lex.yy.c : string.l
	flex string.l
string.tab.c string.tab.h : string.y
	bison -d string.y
clean :
	rm -f $(target) *.o  lex.yy.c string.tab.*
