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

void dump_memory(){
	for (int i = 0; i < memindex; i++) {
		printf("0x%4X, 0x%4X\n", i, memory[i]);
	}
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
		//printf("  %04X: %04X;", hextoint(address)
		//		, memory[hextoint(address)]);
		//getchar(); 
		//memory[hextoint(address)] = hextoint(value) & 0xFFFF; 
		//memory[hextoint(address)+1] = (hextoint(value) >> 16) & 0xFFFF; 
		memindex = hextoint(address); 
	}
	//char * output = newstr(200); 
	pc = 0;
	WINDOW * window; 
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	while(1) {
		getchar();  //wait for the user input
		ir = (memory[pc+1] << 16) | memory[pc]; 
		refresh_state();	
		pc += 2; 
		doinst(getBits(ir, 32));
	}
	fclose(rfile);
	delwin(window);
	endwin();
	return 0; 
}
