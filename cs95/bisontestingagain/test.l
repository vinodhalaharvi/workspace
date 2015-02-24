%x  string comment singlequote
%option yylineno
%option nounput

%{
#define YYSTYPE struct node *

#include "bison.h"
#include "node.h"
#include <assert.h>
#define YY_NO_INPUT
#define MAX_STR_CONST 32667

char *store, *yystring; 
int yystringlen = 0;
unsigned int literal_int = 0;

%}

digit	[0-9]
nonzerodigit	[1-9]
zero	0
number	 ({nonzerodigit}{digit}*)
singledigit	 {zero}
ws              [ \t\v\f]
newline         (\r\n|\n)
letter          [[:alpha:]]
id              [a-zA-Z][a-zA-Z_0-9]*

%%
 /* reserved keywords*/
"do"	{ return DO;}
"for"	{ return FOR;}
"return"	{ return RETURN;}
"break"	{ return BREAK;}
"short"	{ return SHORT;}
"else"	{ return ELSE;}
"goto"	{ return GOTO;}
"signed"	{ return SIGNED;}
"unsigned"	{ return UNSIGNED;}
"char"	{ return CHAR;}
"if"	{ return IF;}
"void"	{ return VOID;}
"int"	{ return INT;}
"continue"	{ return CONTINUE;}
"long"	{ return LONG;}
"while"	{ return WHILE;}
"{"	{ return LEFT_CURLY; }
"}"	{ return RIGHT_CURLY; }
{ws}*   /* eat up a space */

  /* operators begin */
"+="	{ return PLUS_EQUAL;}
"-="	{ return MINUS_EQUAL;}
"*="	{ return ASTERISK_EQUAL	;}
"/="	{ return SLASH_EQUAL;}
"%="	{ return PERCENT_EQUAL;}
"<<="	{ return LESS_LESS_EQUAL;}
">>="	{ return GREATER_GREATER_EQUAL;}
"&="	{ return AMPERSAND_EQUAL;}
"^="	{ return CARET_EQUAL;}
"|="	{ return VBAR_EQUAL;}
"++"	{ return PLUS_PLUS;}
"--"	{ return MINUS_MINUS;}
"<<"	{ return LESS_LESS;}
">>"	{ return GREATER_GREATER;}
"<="	{ return LESS_EQUAL;}
">="	{ return GREATER_EQUAL;}
"=="	{ return EQUAL_EQUAL;}
"!="	{ return EXCLAMATION_EQUAL;}
"&&"	{ return AMPERSAND_AMPERSAND;}
"||"	{ return VBAR_VBAR;}
"!"	{ return EXCLAMATION;}
"%"	{ return PERCENT;}
"^"	{ return CARET;}
"&"	{ return AMPERSAND;}
"*"	{ return ASTERISK;}
"-"	{ return MINUS;}
"+"	{ return PLUS;}
"="	{ return EQUAL;}
"~"	{ return TILDE;}
"|"	{ return VBAR;}
"<"	{ return LESS;}
">"	{ return GREATER;}
"/"	{ return SLASH;}
"?"	{ return QUESTION;}
"("	{ return LEFT_PAREN;}
")"	{ return RIGHT_PAREN;}
"["	{ return RIGHT_SQUARE;}
"]"	{ return LEFT_SQUARE;}
"{"	{ return LEFT_CURLY;}
"}" 	{ return RIGHT_CURLY;}
","	{ return COMMA;}
";"	{ return SEMICOLON;}
":"	{ return COLON;}
  /* operators end */




 /* handle comments */
 /* REFERENCE: flex office manual */
 /* http://flex.sourceforge.net/manual/Start-Conditions.html#Start-Conditions */
"/*"         {BEGIN(comment);}
<comment>[^*\n]*        
<comment>"*"+[^*/\n]*   
<comment>\n             
<comment>"*"+"/"        {BEGIN(INITIAL);}

 /* handle comments */
 /* REFERENCE: flex office manual */
 /* http://flex.sourceforge.net/manual/Start-Conditions.html#Start-Conditions */
 /* handle double quotes */
\" {
BEGIN(string); 
store = (char *) malloc(sizeof(char) * MAX_STR_CONST); 
memset(store, '\0', MAX_STR_CONST ); 
yystring = store; 
}
<string>\n {
/* yyerror("Quoted string not terminated properly.");  */
	return -1; 
}
 /* if not a double quote, not a slash or newline */
<string>[^\"\\\n] {
*store++ = *yytext; 
assert(++yystringlen < MAX_STR_CONST ); 
}
 /* Case for valid octal escape code */
<string>\\[0-7]{1,3} {
unsigned int result; 
(void)sscanf(yytext + 1, "%o", &result); 
if (result > 0xff)
	return -1; 
	/* yyerror("Octal code limits out of bounds within the string ..");  */
*store++ = result; 
assert(++yystringlen < MAX_STR_CONST); 
}
 /* If you get here, it's an invalid octal escape code */
<string>\\[0-9]+ {
return -1; 
/* yyerror("Invalid octal code inside the string.. ");  */
}
 /* change the escape literals to their true encoding */
<string>\\n { *store++ = '\n'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\t { *store++ = '\t'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\b { *store++ = '\b'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\r { *store++ = '\r'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\f { *store++ = '\f'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\v { *store++ = '\v'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\a { *store++ = '\a'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\? { *store++ = '\?'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\\\  { *store++ = '\\'; assert(++yystringlen < MAX_STR_CONST); }
<string>\\\' { *store++ = '\''; assert(++yystringlen < MAX_STR_CONST); }
 /*<string>\\\0 { *store++ = '\0'; assert(++yystringlen < MAX_STR_CONST); } */
<string>\\\" { *store++ = '"'; assert(++yystringlen < MAX_STR_CONST); }
 /* if this is not a escape character then ignore leading '\' */
<string>\\(.|\n)  {*store++ = yytext[1]; assert(++yystringlen < MAX_STR_CONST); }
 /* wrap up the string if we see a closing quote*/
<string>\" {
*store = '\0'; 
assert(++yystringlen < MAX_STR_CONST); 
/*yylval = node_number_from_literal(yystringlen); */
BEGIN(INITIAL); 
return STRING;
}

 /*Rules for character literals */
(\'\\[0-7]{1,3}\')	{
			(void) sscanf(yytext+2, "%o", &literal_int); 
			yylval = node_number_from_literal(literal_int); 
			return NUMBER; 
		}
(\'[^'\\]\')	{yylval = node_number_from_literal((int)yytext[1]); return NUMBER; }
(\'\\a\')	{yylval = node_number_from_literal('\a'); return NUMBER; }
(\'\\b\')	{yylval = node_number_from_literal('\b'); return NUMBER; }
(\'\\t\')	{yylval = node_number_from_literal('\t'); return NUMBER; }
(\'\\n\')	{yylval = node_number_from_literal('\n'); return NUMBER; }
(\'\\v\')	{yylval = node_number_from_literal('\v'); return NUMBER; }
(\'\\f\')	{yylval = node_number_from_literal('\f'); return NUMBER; }
(\'\\r\')	{yylval = node_number_from_literal('\r'); return NUMBER; }
 /* Decimal number which could either be a single digit '0' or
a valid number not starting with '0' */
 /* {number}  { yylval.d = atoi(yytext); return NUMBER; } */
{number}	{ yylval = node_number(yytext); return NUMBER; }
{zero}*{number} { return -1; }
{zero}	{yylval = node_number(yytext); return NUMBER; }
 /* constants end */
 /* identifiers */
{id}        { yylval = node_identifier(yytext, yyleng); return IDENTIFIER; } 
 /* newline and white space */
{newline}   {}
 /*everything else is an error */
.           return -1;
%%
