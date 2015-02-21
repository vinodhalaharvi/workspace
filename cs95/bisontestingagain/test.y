%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
void yyerror(char *s) ; 
int yylex(); 
struct node * node_create(long  value);
struct node * node_binary_operation(int type, long a, long b); 
void print_node(struct node * node);
struct node {
	long value; 
}; 
%}
%union {
	struct node* node;
	long int d; 
}

%token LEFT_CURLY RIGHT_CURLY PLUS 
%token MINUS SLASH ASTERISK
%type <node> programstart expr 
%token <d> NUMBER 
%start programstart

%%
programstart:  
	| programstart LEFT_CURLY expr RIGHT_CURLY 
		{ $$ = $3; printf("%ld\n", $3->value); printf(">> "); }
	;
expr: 
    | NUMBER PLUS NUMBER
		{ $$ = node_binary_operation(PLUS, $1, $3);}
    | NUMBER MINUS NUMBER
		{ $$ = node_binary_operation(MINUS, $1, $3);}
    | NUMBER SLASH NUMBER
		{ $$ = node_binary_operation(SLASH, $1, $3);}
    | NUMBER ASTERISK NUMBER
		{ $$ = node_binary_operation(ASTERISK, $1, $3);}
	;
%%
int main(int argc, const char *argv[])
{
	printf(">> "); 
	yyparse(); 
	return 0;
}

void yyerror(char * s){
	fprintf(stderr, "Error %s\n", s); 
}


struct node * node_create(long  value){
	struct node *temp = (struct node *) malloc(sizeof(struct node)); 
	temp->value = value; 
	return temp; 
}


void print_node(struct node * node){
	printf("%ld", node->value);
}


struct node * node_binary_operation(int type, long a, long b)
{
	switch (type) {
		case PLUS: return node_create(a + b); 
		case MINUS: return node_create(a - b); 
		case ASTERISK: return node_create(a * b); 
		case SLASH: return node_create(a / b); 
	}
	assert(0 == 1); 
	return NULL;
}
