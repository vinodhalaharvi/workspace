all: clean
	bison -d test.y -o bison.c
	flex -o lex.c test.l 
	clang -o test bison.c lex.c -lfl -ggdb
	./test
tags:
	ctags -R --c++-kinds=+p --fields=+iaS --extra=+q  
clean: 
	rm -f bison.c lex.c *.o
	#clang -o test bison.c lex.c functions.o -lfl -ggdb
	#clang -c functions.c -ggdb 

