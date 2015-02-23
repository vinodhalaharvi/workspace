/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/calcfuncs.c,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/*
 * helper functions for calc
 */
#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include "calc.h"

/* symbol table */
/* hash a symbol */

struct ast * newast(int nodetype, struct ast *l, struct ast *r)
{
	struct ast *a = malloc(sizeof(struct ast));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast * newnum(double d)
{
	struct numval *a = malloc(sizeof(struct numval));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'K';
	a->number = d;
	return (struct ast *)a;
}


double eval(struct ast *a)
{
	double v;
	if(!a) {
		yyerror("internal error, null eval");
		return 0.0;
	}
	switch(a->nodetype) {
		/* constant */
		case 'K': v = ((struct numval *)a)->number; break;
		case '+': v = eval(a->l) + eval(a->r); break;
		case '-': v = eval(a->l) - eval(a->r); break;
		case '*': v = eval(a->l) * eval(a->r); break;
		case '/': v = eval(a->l) / eval(a->r); break;
		case 'M': v = -eval(a->l); break;
		case 'L': eval(a->l); v = eval(a->r); break;
		default: printf("internal error: bad node %c\n", a->nodetype);
	}
	return v;
}


void treefree(struct ast *a)
{
	switch(a->nodetype) {
		/* two subtrees */
		case '+':
		case '-':
		case '*':
		case '/':
		case '1':  case '2':  case '3':  case '4':  case '5':  case '6':
		case 'L':
			treefree(a->r);
			/* one subtree */
		case '|':
		case 'M': case 'C': case 'F':
			treefree(a->l);
			/* no subtree */
		case 'K': case 'N':
			break;
		case '=':
			free( ((struct symasgn *)a)->v);
			break;
		case 'I': case 'W':
			free( ((struct flow *)a)->cond);
			if( ((struct flow *)a)->tl) free( ((struct flow *)a)->tl);
			if( ((struct flow *)a)->el) free( ((struct flow *)a)->el);
			break;
		default: printf("internal error: free bad node %c\n", a->nodetype);
	}	  
	free(a); /* always free the node itself */
}

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

int main()
{
	printf("> "); 
	return yyparse();
}

/* debugging: dump out an AST */
int debug = 0;
void dumpast(struct ast *a, int level)
{

	printf("%*s", 2*level, "");	/* indent to this level */
	level++;
	if(!a) {
		printf("NULL\n");
		return;
	}
	switch(a->nodetype) {
		/* constant */
		case 'K': printf("number %4.4g\n", ((struct numval *)a)->number); break;
		case '+': case '-': case '*': case '/': case 'L':
			  printf("binop %c\n", a->nodetype);
			  dumpast(a->l, level);
			  dumpast(a->r, level);
			  return;
		default: printf("bad %c\n", a->nodetype);
			 return;
	}
}
