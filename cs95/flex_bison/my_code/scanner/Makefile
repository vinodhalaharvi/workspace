all: scanner.l
	flex -o scanner.lex.c scanner.l
	gcc -std=gnu99 -o scanner scanner.lex.c -lfl

run:
	./scanner

clean : cleanobj cleandiff
	    rm program

cleanobj :
	rm *.o

tags :
	ctags -R --c++-kinds=+p --fields=+iaS \
	--extra=+q /usr/include /usr/local/include .

.PHONY: clean cleanobj cleandiff tags
