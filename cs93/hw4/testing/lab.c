#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



int islabel(const char * string){
	return (strchr(string, ':') != NULL); 
}

int isasciiz(const char * string){
	return (strstr(string, ".asciiz") != NULL); 
}

char * getlabel(const char *string){
	int i=0; 
	int count = 0; 
	assert (string != NULL); 
	char * res = (char *) malloc(strlen(string)+1); 
	memset(res, '\0', strlen(string)+1); 
	int j = 0;
	while(string[i] != '\0') {
		if (string[i] != ' ' 
			&& string[i] != '\t' 
			&& string[i] != '\n'
			&& string[i] != ':') {
			res[j++] = string[i]; 
		}
		if (string[i] == ':')
			return res; 
		i++;
	}
	return res;
}


int main(int argc, const char *argv[])
{
	//char * string = "inputstring: .asciiz \"input string\n\" # this is a sample comment"; 
	char * string = "inputstring: .asciiz \"input string\n\" # this is a sample comment"; 
	//char * string = "\t \tinputstring: \n"; 
	if (islabel(string)) {
		printf("LABEL\n");
		if (isasciiz(string)){
			printf("ASCIIZ\n");
			printf("%s\n", getlabel(string)); 
			//getstring(string); 
		} else {
			printf("NOASCIIZ\n");
			printf("%s\n", getlabel(string)); 
		}
	}
	return 0;
}
