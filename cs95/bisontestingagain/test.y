%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"

int yylex();
extern int yylineno;
void yyerror(char *s);
#define YYSTYPE struct node *
#define YYERROR_VERBOSE
void print_node(struct node * node);
void print_tree(struct node * node);
extern struct node *root_node;

%}

%token IDENTIFIER STRING
%token BREAK CHAR CONTINUE DO ELSE FOR GOTO IF
%token INT LONG RETURN SHORT SIGNED UNSIGNED VOID WHILE
%token LEFT_PAREN RIGHT_PAREN LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY
%token AMPERSAND ASTERISK CARET COLON COMMA EQUAL EXCLAMATION GREATER
%token LESS MINUS PERCENT PLUS SEMICOLON SLASH QUESTION TILDE VBAR
%token AMPERSAND_AMPERSAND AMPERSAND_EQUAL ASTERISK_EQUAL CARET_EQUAL
%token EQUAL_EQUAL EXCLAMATION_EQUAL GREATER_EQUAL GREATER_GREATER
%token GREATER_GREATER_EQUAL LESS_EQUAL LESS_LESS LESS_LESS_EQUAL
%token MINUS_EQUAL MINUS_MINUS PERCENT_EQUAL PLUS_EQUAL PLUS_PLUS
%token SLASH_EQUAL VBAR_EQUAL VBAR_VBAR

%start programstart
%token NUMBER
%left PLUS MINUS
%left SLASH ASTERISK

%%
programstart:  
	| programstart LEFT_CURLY expr RIGHT_CURLY 
		{ print_tree($3); printf(">> "); }
	;

expr: 
	| expr PLUS NUMBER
		{ $$ = node_binary_operation($2, $1, $3);}
	| NUMBER
	;
%%
void print_node(struct node *node){
	assert(node != NULL); 
	if (node->kind == NODE_BINARY_OPERATION) { 
		printf("Node at 0x%p left_operand: 0x%p, right_operand:0x%p\n", 
			node, node->data.binary_operation.left_operand, 
				node->data.binary_operation.right_operand); 
	} else {
		printf("Node at 0x%p has value %lu\n" , node, node->data.number.value); 
	}
}

void print_tree(struct node * node){
	if (node == NULL)
		return; 
	if (node->kind == NODE_BINARY_OPERATION)
	{ 
		print_node(node); 
		print_node(node->data.binary_operation.left_operand); 
		print_node(node->data.binary_operation.right_operand); 
	} else { 
		print_node(node); 
	}
	return; 
}

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(int argc, const char *argv[])
{
	printf(">> "); 
	yyparse(); 
	return 0;
}

