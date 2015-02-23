%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int lineno = 0; int colno = 0; 
int number_of_lines = 0; 
%}
%%
\n { number_of_lines++; }
.  {/*ignore*/}
%%

int main(int argc, const char *argv[])
{
	yylex();
	printf("%d\n", number_of_lines);
	return 0;
}
