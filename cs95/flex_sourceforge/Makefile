all:
	flex -o lexer.intermediate.c lexer.c
	gcc -o lexer lexer.intermediate.c -lfl

run:
	./lexer < $(filename)
