#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "emcommand.h"
#include "emlib.h"
#include <curses.h>
unsigned int memindex = 0;

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
	getFiles(argc, argv, &rfile); 
	int lineno = 0; 
	while(getline(&line, &len, rfile) != EOF){
		lineno++; 
		line[strlen(line)-1] = '\0';
		if(strchr(line, ':') == NULL)
			continue; 
		int sn = sscanf(line, "  %4s: %4s;", address, value); 
		assert(sn == 2);
		memory[hextoint(address)] = hextoint(value);
		memindex = hextoint(address); 
	}
#ifdef DISASSEMBLY
	getchar(); 
	pc = 0;
	while(1) {
		ir = (memory[pc+1] << 16) | memory[pc]; 
		pc += 2; 
		doinst(getBits(ir, 32));
		printf("[0x%06X]:0x%08X\n", pc, 
				(memory[pc + 1] << 16)
				|  memory[pc]);

		getchar();  //wait for the user input
	}
	return 0; 
#elif EMULATE
	pc = 0;
	WINDOW * window; 
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	while(1) {
		ir = (memory[pc+1] << 16) | memory[pc]; 
		pc += 2; 
		doinst(getBits(ir, 32));
		refresh_state();	
		getchar();  //wait for the user input
	}
	fclose(rfile);
	delwin(window);
	endwin();
#endif
	return 0; 
}
