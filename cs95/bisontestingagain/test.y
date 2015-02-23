%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"

int yylex();
extern int yylineno;
void yyerror(char const *s);
#define YYSTYPE struct node *
#define YYERROR_VERBOSE
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
%union {
	 union { 
		 int kind;
		  int line_number;
		  struct ir_section *ir;
		  union {
		    struct {
		      unsigned long value;
		      bool overflow;
		      struct result result;
		    } number;
		    struct {
		      char name[MAX_IDENTIFIER_LENGTH + 1];
		      struct symbol *symbol;
		    } identifier;
		    struct {
		      int operation;
		      struct node *left_operand;
		      struct node *right_operand;
		      struct result result;
		    } binary_operation;
		    struct {
		      struct node *expression;
		    } expression_statement;
		    struct {
		      struct node *init;
		      struct node *statement;
		    } statement_list;
		  } data;
		} node; 
	}

%type <node> programstart expr
%token <node> NUMBER 
%start programstart
%%
programstart:  
	| programstart LEFT_CURLY expr RIGHT_CURLY 
		{ $$ = $3; }
		/*print_node($3); printf(">> "); } */
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
