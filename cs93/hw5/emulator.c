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
	FILE *rfile; 
	char *line = newstr(100);
	char *address = newstr(100);
	char *value = newstr(100);
	size_t len = 0; 
	int sn = 0 ; 
	getFiles(argc, argv, &rfile); 
	int lineno = 0; 
	unsigned int memindex = 0;
	while(getline(&line, &len, rfile) != EOF){
		lineno++; 
		line[strlen(line)-1] = '\0';
		if(strchr(line, ':') == NULL)
			continue; 
		int sn = sscanf(line, "  %4s: %4s;", address, value); 
		assert(hextoint(address) % 2 == 0); 
		memory[hextoint(address)] = hextoint(value) & 0xFFFF; 
		memory[hextoint(address)+2] = (hextoint(value) >> 16) & 0xFFFF; 
		memindex += 2;
	}
	char * output = newstr(200); 
	pc = 0;
	WINDOW * window; 
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	while(1) {
		getchar();  //wait for the user input
		ir = (memory[pc+2] << 16) | memory[pc]; 
		refresh_registers();	
		pc += 4; 
		doinst(getBits(ir, 32));
	}
	fclose(rfile);
	delwin(window);
	endwin();
	return 0; 
}
