#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	const char string[] = "	blez rsrc, $offset-$"; 
	const char d[] = "	 ,"; 
	char * token , *cp ; 
	cp = strdupa(string); 
	token = strtok(cp, d); 
	printf("%s\n", token);
	while( (token = strtok(NULL, d)) != NULL){ 
		printf("%s\n", token);
	}
	return 0;
}
