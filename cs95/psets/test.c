#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	while(tok = yylex){
		print_token(tok); 
	}
	return 0;
}
