%option noyywrap nodefault yylineno
%{
# include "calc.h"
# include "calc.tab.h"
%}
EXP	([Ee][-+]?[0-9]+)
%%
 /* single character ops */
"+" |
"-" |
"*" |
"/" |
"=" |
"(" |
")"     { return yytext[0]; }
 /* names */
[a-zA-Z][a-zA-Z0-9]*  { return IDENTIFIER; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUM; }
"//".*  
[ \t]   /* ignore white space */ 
\\\n    printf("c> "); /* ignore line continuation */
"\n"    { return EOL; }
.	{ yyerror("Mystery character %c\n", *yytext); }
%%
