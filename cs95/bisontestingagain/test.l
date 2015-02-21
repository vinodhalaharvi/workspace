%{
#include "bison.h"
%}
%%
"{"	{ return LEFT_CURLY; }
"}"	{ return RIGHT_CURLY; }
"*"	{ return ASTERISK; }
"/"	{ return SLASH; }
"+"	{ return PLUS; }
"-"	{ return MINUS; }
[0-9][0-9]*  { yylval.d = atoi(yytext); return NUMBER; }
[ \t]*   /* eat up a space */
\n 
%%
