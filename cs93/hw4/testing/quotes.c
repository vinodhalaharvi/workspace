#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 80

char * getasciiz(const char *input){
	char *str = (char * ) malloc(strlen(input) + 1);
	memset(str, '\0', strlen(input) + 1);
	sscanf(input, "%*[^\"]%*c%[^\"]%*c%*[^\n]%*c", str);
	return str; 
}


int main() {
	FILE *fp;
	char *input = "inputstring: .asciiz \"input test string\" # this is a sample comment"; 
	char str[128];
	printf("%s\n", getasciiz(input));
	return 0;
}
