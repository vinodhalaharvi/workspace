#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}

void getFiles(int argc, const char * argv[], FILE **rfile){
	assert(argc == 2); 
	const char * inputfilepath =  argv[1]; 
	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 
	return ; 
}


int main(int argc, const char *argv[])
{
	FILE *rfile; 
	char *line = newstr(100);
	char *address = newstr(100);
	char *value = newstr(100);
	size_t len = 0; 
	int i = 0; 
	int sn = 0 ; 
	getFiles(argc, argv, &rfile); 
	while(getline(&line, &len, rfile) != EOF){
		line[strlen(line)-1] = '\0';
		if(strchr(line, ':') == NULL)
			continue; 
		int sn = sscanf(line, "  %4s: %4s;", address, value); 
		printf("%s, %s\n", address, value); 
	}
	fclose(rfile);
	return 0;
}
