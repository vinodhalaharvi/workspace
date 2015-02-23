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

%start translation_unit
%token NUMBER
%left PLUS MINUS
%left SLASH ASTERISK

%%
abstract_declarator 
	: pointer 
	| pointer_opt direct_abstract_declarator  
	;

additive_expr 
	: multiplicative_expr 
	| additive_expr add_op multiplicative_expr  
	;

add_op 
	: PLUS 
	| MINUS  
	;

address_expr 
	: AMPERSAND cast_expr  
	;

array_declarator 
	: direct_declarator LEFT_SQUARE constant_expr_opt RIGHT_SQUARE  
	;

assignment_expr 
	: conditional_expr 
	| unary_expr assignment_op assignment_expr  
	;

assignment_op 
	: EQUAL 
	| PLUS_EQUAL 
	| MINUS_EQUAL 
	| ASTERISK_EQUAL 
	| SLASH_EQUAL 
	| PERCENT_EQUAL 
        | LESS_EQUAL 
	| GREATER_EQUAL 
	| AMPERSAND_EQUAL 
	| CARET_EQUAL 
	| VBAR_EQUAL
	;

bitwise_and_expr 
	: equality_expr 
	| bitwise_and_expr AMPERSAND equality_expr  
	;

bitwise_negation_expr 
	: TILDE cast_expr  
	;

bitwise_or_expr 
	: bitwise_xor_expr 
	| bitwise_or_expr VBAR bitwise_xor_expr  
	;

bitwise_xor_expr 
	: bitwise_and_expr 
	| bitwise_xor_expr CARET bitwise_and_expr  
	;

break_statement 
	: BREAK SEMICOLON  
	;

cast_expr 
	: unary_expr 
	| LEFT_PAREN type_name RIGHT_PAREN cast_expr  
	;

character_type_specifier 
	: CHAR 
	| SIGNED CHAR 
	| UNSIGNED CHAR  
	;

comma_expr 
	: assignment_expr 
	| comma_expr COMMA assignment_expr  
	;

compound_statement 
	: LEFT_CURLY declaration_or_statement_list_opt RIGHT_CURLY  
	;

conditional_expr 
	: logical_or_expr 
	| logical_or_expr QUESTION expr COLON conditional_expr  
	;

conditional_statement 
	: if_statement 
	| if_else_statement  
	;

constant 
	: integer_constant 
	| character_constant 
	| string_constant  
	;

constant_expr 
	: conditional_expr  
	;

continue_statement 
	: CONTINUE SEMICOLON  
	;



decl 
	: declaration_specifiers initialized_declarator_list SEMICOLON  
	;


declaration_or_statement 
	: decl 
	| statement  
	;

declaration_or_statement_list 
	: declaration_or_statement 
	| declaration_or_statement_list declaration_or_statement  
	;

declaration_specifiers 
	:  type_specifier  
	;

declarator 
	: pointer_declarator 
	| direct_declarator  
	;


direct_abstract_declarator 
	: LEFT_PAREN abstract_declarator RIGHT_PAREN 
	| direct_abstract_declarator_opt LEFT_SQUARE constant_expr_opt RIGHT_SQUARE  
	;


direct_declarator 
	: simple_declarator 
	| LEFT_PAREN declarator RIGHT_PAREN 
	| function_declarator 
	| array_declarator  
	;

do_statement 
	: DO statement WHILE LEFT_PAREN expr RIGHT_PAREN SEMICOLON  
	;



equality_expr 
	: relational_expr 
	| equality_expr equality_op relational_expr  
	;

equality_op 
	: EQUAL_EQUAL 
	| EXCLAMATION_EQUAL
	;

expr 
	: comma_expr  
	;

expression_list 
	: assignment_expr 
	| expression_list COMMA assignment_expr 
	;

expression_statement 
	: expr SEMICOLON 
	;

for_expr 
	: LEFT_PAREN initial_clause_opt SEMICOLON expr_opt SEMICOLON expr_opt RIGHT_PAREN 
	;

for_statement 
	: FOR for_expr statement 
	;

function_call 
	: postfix_expr LEFT_PAREN expression_list_opt RIGHT_PAREN 
	;

function_declarator 
	: direct_declarator LEFT_PAREN parameter_type_list RIGHT_PAREN 
	;

function_definition 
	: function_def_specifier compound_statement 
	;

function_def_specifier 
	: declaration_specifiers_opt declarator 
	;

goto_statement 
	: GOTO named_label SEMICOLON 
	;

if_else_statement 
	: IF LEFT_PAREN expr RIGHT_PAREN statement ELSE statement 
	;

if_statement 
	: IF LEFT_PAREN expr RIGHT_PAREN statement 
	;


indirection_expr 
	: ASTERISK cast_expr 
	;

initial_clause 
	: expr 
	;

initialized_declarator 
	: declarator 
	;

initialized_declarator_list 
	: initialized_declarator 
	| initialized_declarator_list COMMA initialized_declarator 
	;


integer_type_specifier 
	: signed_type_specifier 
	| unsigned_type_specifier 
	| character_type_specifier 
	;

iterative_statement 
	: while_statement 
	| do_statement 
	| for_statement 
	;

label 
	: named_label 
	;

labeled_statement 
	: label COLON statement 
	;

logical_and_expr 
	: bitwise_or_expr 
	| logical_and_expr AMPERSAND_AMPERSAND bitwise_or_expr 
	;

logical_negation_expr 
	: EXCLAMATION cast_expr 
	;

logical_or_expr 
	: logical_and_expr 
	| logical_or_expr VBAR_VBAR logical_and_expr 
	;

multiplicative_expr 
	: cast_expr 
	| multiplicative_expr mult_op cast_expr 
mult_op 
	: ASTERISK 
	| SLASH 
	| PERCENT 
	;

named_label 
	: IDENTIFIER 
	;

null_statement 
	: SEMICOLON 
	;

parameter_decl 
	: declaration_specifiers declarator 
	| declaration_specifiers abstract_declarator_opt 
	;


 /* not sure if this is right */
CONSTANT:
	;
abstract_declarator_opt:
	| abstract_declarator
	;
character_constant:
	| character_constant
	;
constant_expr_opt:
	| conditional_expr
	;
declaration_or_statement_list_opt:
	| declaration_or_statement_list	
	;
declaration_specifiers_opt:
	| declaration_specifiers
	;
direct_abstract_declarator_opt:
	| direct_abstract_declarator
	;
expr_opt:
	| expr
	;
expression_list_opt:
	| expression_list
	;
initial_clause_opt:
	| initial_clause
	;
int_t_opt:
	;
integer_constant:
	| NUMBER
	;
pointer_opt:
	| pointer
	;
string_constant:
	;
 /* not sure if this is right */




parameter_list 
	: parameter_decl 
	| parameter_list COMMA parameter_decl 
	;

parameter_type_list 
	: parameter_list 
	;

parenthesized_expr 
	: LEFT_PAREN expr RIGHT_PAREN 
	;

pointer 
	: ASTERISK 
	| ASTERISK pointer 
	;

pointer_declarator 
	: pointer direct_declarator 
	;

postdecrement_expr 
	: postfix_expr MINUS_MINUS 
	;

postfix_expr 
	: primary_expr 
	| subscript_expr 
	| function_call 
	| postincrement_expr 
	| postdecrement_expr 
	;

postincrement_expr 
	: postfix_expr PLUS_PLUS 
	;

predecrement_expr 
	: MINUS_MINUS unary_expr 
	;

preincrement_expr 
	: PLUS_PLUS unary_expr 
	;


primary_expr 
	: IDENTIFIER 
	| CONSTANT 
	| parenthesized_expr 
	;

relational_expr 
	: shift_expr 
	| relational_expr relational_op shift_expr 
relational_op 
	: LESS 
	| LESS_EQUAL 
	| GREATER 
	| GREATER_EQUAL 
	;

return_statement 
	: RETURN expr_opt SEMICOLON 
	;

shift_expr 
	: additive_expr 
	| shift_expr shift_op additive_expr 
shift_op 
	: LESS_LESS
	| GREATER_GREATER 
	;

signed_type_specifier 
	: SHORT 
	| SHORT INT 
	| SIGNED SHORT 
	| SIGNED SHORT INT 
	| INT 
	| SIGNED INT 
	| SIGNED 
	| LONG 
	| LONG INT 
	| SIGNED LONG 
	| SIGNED LONG INT 
	;

simple_declarator 
	: IDENTIFIER 
	;

statement 
	: expression_statement 
	| labeled_statement 
	| compound_statement 
	| conditional_statement 
	| iterative_statement 
	| break_statement 
	| continue_statement 
	| return_statement 
	| goto_statement 
	| null_statement 
	;

subscript_expr 
	: postfix_expr LEFT_SQUARE expr RIGHT_SQUARE 
	;

top_level_decl 
	: decl 
	| function_definition 
	;

translation_unit 
	: top_level_decl 
	| translation_unit top_level_decl 
	;


type_name 
	: declaration_specifiers abstract_declarator_opt 
	;
type_specifier 
	: integer_type_specifier 
         | void_type_specifier 
	;
unary_expr 
	: postfix_expr 
	| unary_minus_expr 
	| unary_plus_expr 
	| logical_negation_expr 
	| bitwise_negation_expr 
	| address_expr 
	| indirection_expr 
	| preincrement_expr 
	| predecrement_expr 
	;

unary_minus_expr 
	: MINUS cast_expr 
	;

unary_plus_expr 
	: PLUS cast_expr 
	;

unsigned_type_specifier 
	: UNSIGNED SHORT int_t_opt 
	| UNSIGNED int_t_opt 
	| UNSIGNED LONG int_t_opt 
	;

void_type_specifier 
	: VOID 
	;

while_statement 
	: WHILE LEFT_PAREN expr RIGHT_PAREN statement 
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

