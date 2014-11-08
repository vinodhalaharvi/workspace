#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _symbol_table {
	char * name; 
	unsigned index; 
} symbol_table;

static symbol_table symbols[100]; 
static unsigned int symmaxindex; 

unsigned int get_sym_address(const char * name){
	for (int i = 0; i < symmaxindex; i++) {
		if (strcmp(symbols[i].name, name) == 0) {
			return symbols[i].index; 
		}
	}
	printf("%s %s\n", name, "ERROR: SYMBOL NOT FOUND !!\n");
	assert(1 == 0);
}

unsigned put_sym_address(const char * name, unsigned int address){
	int i = 0;
	symbols[symmaxindex].name = strdup(name); 
	symbols[symmaxindex++].index = address; 
}

char *  get_label(const char * line){
	char * label = (char * ) malloc(100); 
	memset(label, '\0', 100);
	int n = sscanf(line, "%*[ \t]%[^':']", label); 
	assert(n == 1);{}
	return label; 
}


int main(int argc, const char *argv[])
{
	int lineno = 1; 
	size_t len = 0 ; 
	char * line = NULL; 
	//assert(argc == 2); 
	FILE * rfile = fopen(argv[1], "r"); 
	assert(rfile != NULL);

	line = strdup("this is a test string : and test again");
	char *found = strchr(line, ':'); 
	int index; 
	if (found) {
		index = found - line; 
		line[index] = '\0';
	}
	printf("%s\n", line);
	return 0;

	while(getline(&line, &len, rfile) != EOF){
		line[strlen(line)-1] = '\0';  // strip the newline
		if (strchr(line, ':')) {
			line[strlen(line)-1] = '\0';  // strip newline and ':'
			printf("%s\n", line);
		}
		if (strcmp(line, ".data") == 0) 
			continue; 
		if (strcmp(line, ".text") == 0)
			continue; 
		//printf("%d: %s\n", lineno, line);
		lineno++; 
	}
	return 0; 
}
