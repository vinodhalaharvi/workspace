#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "emcommand.h"
#include <curses.h>
unsigned int memindex = 0;
char currInst[100];

void getFiles(int argc, const char * argv[], FILE **rfile){
	assert(argc == 2); 
	const char * inputfilepath =  argv[1]; 
	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 
	return ; 
}


void print_heap(){
	printf("%s\n", getheapStr());
	return; 
	printf("%s\n", "Printing heap .. ");
	printf("%s\n", "firstNumber");
	int i = 21760; 
	while(memory[i]){
		printf("%c", memory[i++]);
	}
	printf("\n");
	printf("%s\n", "secondNumber");
	i = 21764; 
	while(memory[i]){
		printf("%c", memory[i++]);
	}
	printf("\n");
	printf("%s\n", "outputString");
	i = 21768; 
	while(memory[i]){
		printf("%c", memory[i++]);
	}
	printf("\n");
}

void waitmaybe(const char * inst, 
		int count, int waitat){
		if (inst != NULL && 
			strstr(currInst, inst)  != NULL)
			getchar();  
		if (count % waitat == 0 )
			getchar(); 
		return; 
}


int main(int argc, const char *argv[])
{
	FILE *rfile; 
	char *line = newstr(100);
	char *address = newstr(100);
	char *value = newstr(100);
	char *countStr = newstr(100);
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
	init_registers(); 
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
	getchar();  //wait for the user input
	WINDOW * window; 
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	refresh_state();	
	getchar();  //wait for the user input
	int count = 0;  int waitat = 590; 
	while(1) {
		ir = (memory[pc+1] << 16) | memory[pc]; 
		pc += 2; 
		doinst(getBits(ir, 32));
		refresh_state();	
		print_output(currInst); 
		logstring(getheapStr());
		sprintf(countStr, "instr count :%d", count); 
		instcountstring(countStr); 
		count++;
		waitmaybe("nop", count, waitat); 
	}
	fclose(rfile);
	delwin(window);
	endwin();
#endif
	return 0; 
}
