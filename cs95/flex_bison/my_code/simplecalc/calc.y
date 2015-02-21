/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/calc.y,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/* calculator with AST */

%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "calc.h"
%}

%union {
	char * s; 
	struct ast *a;
	double d;
}

/* declare tokens */
%token <d> NUM
%token <s> IDENTIFIER
%token EOL 
%right '='
%left '+' '-'
%left '*' '/'
%type <a> exp 
%start calclist

%%
calclist: /* nothing */
	| calclist exp EOL {
    if(debug) dumpast($2, 0);
     printf("= %4.4g\n> ", eval($2));
     treefree($2);
    }
  | calclist error EOL { yyerrok; printf("> "); }
 ;

exp: exp '+' exp          { $$ = newast('+', $1,$3); }
   | exp '-' exp          { $$ = newast('-', $1,$3);}
   | exp '*' exp          { $$ = newast('*', $1,$3); }
   | exp '/' exp          { $$ = newast('/', $1,$3); }
   | '(' exp ')'          { $$ = $2; }
   | NUM                  { $$ = newnum($1); }
;
%%
