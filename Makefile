target=lang
CC=gcc
obj=main.o lex.yy.o string.tab.o  synttree.o symtab.o
$(target) : $(obj) 
	$(CC) -o $(target) $(obj) 

lex.yy.o : lex.yy.c lex.h lexsymb.h  
	$(CC) -c lex.yy.c
symtab.o : symtab.c symtab.h
	$(CC) -c symtab.c
synttree.o : synttree.c synttree.h
	$(CC) -c synttree.c
main.o : main.c lex.h string.tab.h lexsymb.h 
	$(CC) -c  main.c
lex.yy.c : string.l
	flex string.l
string.tab.c string.tab.h : string.y
	bison -d string.y
clean :
	rm -f $(target) *.o  lex.yy.c
