#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "emcommand.h"
#include <curses.h>
unsigned int memindex = 0;
char currInst[100];

/* Vinod Halaharvi
 * HUID 80778287
 */


/* Get files discriptors by opening the underlying files 
 * @param 
 * @returns
 */
void getFiles(int argc, const char * argv[], FILE **rfile){
	assert(argc == 2); 
	const char * inputfilepath =  argv[1]; 
	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 
	return ; 
}


/* Helper function to print heap, REG_IOCONTROL, and REG_IOBUFFER_* locations 
 * @param 
 * @returns
 */
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

/* call getchar() depending on an input instruction  
 * @param 
 * @returns
 */
void waitmaybe(const char * inst){
	if (inst != NULL && 
		strstr(currInst, inst)  != NULL)
		getchar();  
	return; 
}


/* Open the mif file,read instructions and load it to memory
 * start emulating or just disassembling. 
 * doinstr() parses the bits and emulates 
 * the underlying function
 * Optionally call curses display
 * @param 
 * @returns
 */
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
	//read each line and fill memory structure
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
	//initialize all registers and pc
	init_registers(); 
#ifdef DISASSEMBLY
	getchar(); 
	pc = 0;
	while(1) {
		//get the instructioon
		ir = (memory[pc+1] << 16) | memory[pc]; 
		//increment program counter
		pc += 2; 
		//emulate the instruction
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
	//print updated register information 
	//on the screen
	refresh_state();	
	getchar();  //wait for the user input
	int count = 0; 
	while(1) {
		ir = (memory[pc+1] << 16) | memory[pc]; 
		pc += 2; 
		doinst(getBits(ir, 32));
		refresh_state();	
		print_output(currInst); 
		logstring(getheapStr());
		sprintf(countStr, "instr count :%d", count); 
		//display instruction count
		instcountstring(countStr); 
		count++;
#ifdef SINGLESTEP
			getchar();  //sigle step each instruction
#endif
		waitmaybe("nop");  //stop at every nop for debugging
	}
	fclose(rfile);
	delwin(window);
	endwin();
#endif
	return 0; 
}
