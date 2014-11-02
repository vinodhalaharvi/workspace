#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
void getSymbolInfo(const char * line, char * tokens[]){
	const char d[] = "	 ,\n"; 
	char *linecopy;
	linecopy = strdup(line);
	char * token; 
	int i = 0; 
	token = strtok(linecopy, d); 
	//printf("%s\n", token);
	while ((token = strtok(NULL, d)) != NULL) {
		printf("%s\n", token);
	}
	return;
}

int main(int argc, const char *argv[])
{
	char * tokens[4]; 
	getSymbolInfo("add $r0, $r1, $r2", tokens); 	
	return 0;
}
