all: clean
	bison -d test.y -o bison.c
	flex -o lex.c test.l 
	clang -c node.c
	clang -c lex.c
	clang -c bison.c
	clang -o test node.o bison.o lex.o -ll -ggdb
	./test
tags:
	ctags *.[ch]
clean: 
	rm -f bison.c lex.c *.o

