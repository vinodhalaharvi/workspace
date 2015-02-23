%{
#include "tokens.h"
int lineno = 0; 
int wordno = 0; 
int columnno = 0; 

void yyerror(){
	fprintf(stderr, "Mystery charater at %d::%d -> '%c'\n", lineno, columnno, *yytext);
}
%}

%%
"do"	{ return DO; }
"for"	{ return FOR; }
"return"	{ return RETURN; }
"break"	{ return BREAK; }
"short"	{ return SHORT; }
"else"	{ return ELSE; }
"goto"	{ return GOTO; }
"signed"	{ return SIGNED; }
"unsigned"	{ return UNSIGNED; }
"char"	{ return CHAR; }
"if"	{ return IF; }
"void"	{ return VOID; }
"int"	{ return INT; }
"continue"	{ return CONTINUE; }
"long"	{ return LONG; }
"while"	{ return WHILE; }
"+="	{ return PLUS_EQUAL; }
"-="	{ return MINUS_EQUAL; }
"*="	{ return ASTERISK_EQUAL	; }
"/="	{ return SLASH_EQUAL; }
"%="	{ return PERCENT_EQUAL; }
"<<="	{ return LESSTHAN_LESSTHAN_EQUAL; }
">>="	{ return GREATERTHAN_GREATERTHAN_EQUAL; }
"&="	{ return AMPERSAND_EQUAL; }
"^="	{ return CARET_EQUAL; }
"|="	{ return PIPE_EQUAL; }
"++"	{ return PLUS_PLUS; }
"--"	{ return MINUS_MINUS; }
"<<"	{ return LESSTHAN_LESSTHAN; }
">>"	{ return GREATHERTHAN_GREATERTHAN; }
"<="	{ return LESSTHAN_EQUAL; }
">="	{ return GREATERTHAN_EQUAL; }
"=="	{ return EQUAL_EQUAL; }
"!="	{ return EXCLAMATION_EQUAL; }
"&&"	{ return AMPERSAND_AMPERSAND; }
"||"	{ return PIPE_PIPE; }
"!"	{ return EXCLAMATION; }
"%"	{ return PERCENT; }
"^"	{ return CARET; }
"&"	{ return AMPERSAND; }
"*"	{ return ASTERISK; }
"-"	{ return MINUS; }
"+"	{ return PLUS; }
"="	{ return EQUAL; }
"~"	{ return TILDA; }
"|"	{ return PIPE; }
"<"	{ return LESSTHAN; }
">"	{ return GREATERTHAN; }
"/"	{ return SLASH; }
"?"	{ return QUESTIONMARK; }
"("	{ return OPENPAREN; }
")"	{ return CLOSEDPAREN; }
"["	{ return CLOSEDSQUAREBRACKET; }
"]"	{ return OPENSQUAREBRACKET; }
"{"	{ return OPENBRACE; }
"}"	{ return CLOSEDBRACE; }
","	{ return COMMA; }
";"	{ return SEMICOLON; }
":"	{ return COLON; }
"//".*
[ \s\t\v\f\r]+	{ return WHITESPACE; } 
[a-zA-Z_][a-zA-Z_0-9]*	{ wordno++; columnno += strlen(yytext); return IDENTIFIER; }
[-+]?[0-9]+		{ return NUMBER; }
\n		{ lineno++; columnno=0; return NEWLINE; }
. 		{ yyerror(); }
%%

//C functions will go here
int yywrap(void){
	return 1; 
}

int main(int argc, const char *argv[])
{
	yytokentype tok;
	while (tok = yylex()) {
		if (tok != NEWLINE && tok != WHITESPACE) 
			printf("(%s, %s)\n", yytext, get_token_to_string(tok));
	}
	return 0;
}
