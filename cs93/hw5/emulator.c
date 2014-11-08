#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "command.h"
#include "lib.h"
#include <curses.h>


void getFiles(int argc, const char * argv[], FILE **rfile){
	assert(argc == 2); 
	const char * inputfilepath =  argv[1]; 
	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 
	return ; 
}

int main(int argc, const char *argv[])
{
	WINDOW * window; 
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	FILE *rfile; 
	char *line = newstr(100);
	char *address = newstr(100);
	char *value = newstr(100);
	size_t len = 0; 
	int sn = 0 ; 
	getFiles(argc, argv, &rfile); 
	int lineno = 0; 
	while(getline(&line, &len, rfile) != EOF){
		lineno++: 
		line[strlen(line)-1] = '\0';
		if(strchr(line, ':') == NULL)
			continue; 
		int sn = sscanf(line, "  %4s: %4s;", address, value); 
		memory[hextoint(address)] = hextoint(value); 
	}
	char * output = newstr(200); 
	pc = 0;
	
	for (int i = 0; i < lineno; i++) {
		printf("%x, %x\n", i,);
	}

	while(1) {
		sprintf(output, "%d\n", memory[pc]);
		print_output(output); //print the instruction on the screen 
		ir = memory[pc++]; 
		doinst(getBits(ir, 32));
		ir = memory[pc++]; 
		refresh_registers();	
		getchar();  //wait for the user input
		pc ++; 
	}
	fclose(rfile);
	delwin(window);
	endwin();
	return 0; 
}
