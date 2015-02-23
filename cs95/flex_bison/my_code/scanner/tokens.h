#ifndef _PROBLEMSET1
#define _PROBLEMSET1 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef enum yytokentype { 
	DO = 258,
	FOR,
	RETURN,
	BREAK,
	SHORT,
	ELSE,
	GOTO,
	SIGNED,
	UNSIGNED,
	CHAR,
	IF,
	VOID,
	INT,
	CONTINUE,
	CONST,
	LONG,
	WHILE,
	PLUS_EQUAL,
	MINUS_EQUAL,
	ASTERISK_EQUAL,
	SLASH_EQUAL,
	PERCENT_EQUAL,
	LESSTHAN_LESSTHAN_EQUAL,
	GREATERTHAN_GREATERTHAN_EQUAL,
	AMPERSAND_EQUAL,
	CARET_EQUAL,
	PIPE_EQUAL,
	PLUS_PLUS,
	MINUS_MINUS,
	LESSTHAN_LESSTHAN,
	GREATHERTHAN_GREATERTHAN,
	LESSTHAN_EQUAL,
	GREATERTHAN_EQUAL,
	EQUAL_EQUAL,
	EXCLAMATION_EQUAL,
	AMPERSAND_AMPERSAND,
	PIPE_PIPE,
	EXCLAMATION,
	PERCENT,
	CARET,
	AMPERSAND,
	ASTERISK,
	MINUS,
	PLUS,
	EQUAL,
	TILDA,
	PIPE,
	LESSTHAN,
	GREATERTHAN,
	SLASH,
	QUESTIONMARK,
	OPENPAREN,
	CLOSEDPAREN,
	CLOSEDSQUAREBRACKET,
	OPENSQUAREBRACKET,
	OPENBRACE,
	CLOSEDBRACE,
	COMMA,
	SEMICOLON,
	COLON, 
	WHITESPACE, 
	NUMBER, 
	IDENTIFIER, 
	NEWLINE
} yytokentype;

typedef struct _token_to_string {
	yytokentype tok; 
	char * tok_string; 
} token_to_string;
token_to_string token_to_strings[] =
{
	{DO,  "DO"},
	{FOR,  "FOR"},
	{RETURN,  "RETURN"},
	{BREAK,  "BREAK"},
	{SHORT,  "SHORT"},
	{ELSE,  "ELSE"},
	{GOTO,  "GOTO"},
	{SIGNED,  "SIGNED"},
	{UNSIGNED,  "UNSIGNED"},
	{CHAR,  "CHAR"},
	{IF,  "IF"},
	{VOID,  "VOID"},
	{INT,  "INT"},
	{CONTINUE,  "CONTINUE"},
	{CONST,  "CONST"},
	{LONG,  "LONG"},
	{WHILE,  "WHILE"},
	{PLUS_EQUAL,  "PLUS_EQUAL"},
	{MINUS_EQUAL,  "MINUS_EQUAL"},
	{ASTERISK_EQUAL,  "ASTERISK_EQUAL"},
	{SLASH_EQUAL,  "SLASH_EQUAL"},
	{PERCENT_EQUAL,  "PERCENT_EQUAL"},
	{LESSTHAN_LESSTHAN_EQUAL,  "LESSTHAN_LESSTHAN_EQUAL"},
	{GREATERTHAN_GREATERTHAN_EQUAL,  "GREATERTHAN_GREATERTHAN_EQUAL"},
	{AMPERSAND_EQUAL,  "AMPERSAND_EQUAL"},
	{CARET_EQUAL,  "CARET_EQUAL"},
	{PIPE_EQUAL,  "PIPE_EQUAL"},
	{PLUS_PLUS,  "PLUS_PLUS"},
	{MINUS_MINUS,  "MINUS_MINUS"},
	{LESSTHAN_LESSTHAN,  "LESSTHAN_LESSTHAN"},
	{GREATHERTHAN_GREATERTHAN,  "GREATHERTHAN_GREATERTHAN"},
	{LESSTHAN_EQUAL,  "LESSTHAN_EQUAL"},
	{GREATERTHAN_EQUAL,  "GREATERTHAN_EQUAL"},
	{EQUAL_EQUAL,  "EQUAL_EQUAL"},
	{EXCLAMATION_EQUAL,  "EXCLAMATION_EQUAL"},
	{AMPERSAND_AMPERSAND,  "AMPERSAND_AMPERSAND"},
	{PIPE_PIPE,  "PIPE_PIPE"},
	{EXCLAMATION,  "EXCLAMATION"},
	{PERCENT,  "PERCENT"},
	{CARET,  "CARET"},
	{AMPERSAND,  "AMPERSAND"},
	{ASTERISK,  "ASTERISK"},
	{MINUS,  "MINUS"},
	{PLUS,  "PLUS"},
	{EQUAL,  "EQUAL"},
	{TILDA,  "TILDA"},
	{PIPE,  "PIPE"},
	{LESSTHAN,  "LESSTHAN"},
	{GREATERTHAN,  "GREATERTHAN"},
	{SLASH,  "SLASH"},
	{QUESTIONMARK,  "QUESTIONMARK"},
	{OPENPAREN,  "OPENPAREN"},
	{CLOSEDPAREN,  "CLOSEDPAREN"},
	{CLOSEDSQUAREBRACKET,  "CLOSEDSQUAREBRACKET"},
	{OPENSQUAREBRACKET,  "OPENSQUAREBRACKET"},
	{OPENBRACE,  "OPENBRACE"},
	{CLOSEDBRACE,  "CLOSEDBRACE"},
	{COMMA,  "COMMA"},
	{SEMICOLON,  "SEMICOLON"},
	{COLON,  "COLON"},
	{WHITESPACE,  "WHITESPACE"},
	{IDENTIFIER,  "IDENTIFIER"},
	{NUMBER,  "NUMBER"},
	{NEWLINE,  "NEWLINE"}
};
const char *  get_token_to_string(yytokentype tok){
	for (int i = 0; i < sizeof(token_to_strings)/sizeof(token_to_string); i++) {
		if(token_to_strings[i].tok == tok)
			return token_to_strings[i].tok_string; 
	}
	return NULL;
}

#endif
