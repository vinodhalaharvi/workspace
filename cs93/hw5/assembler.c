/* Vinod Halaharvi
 * HUID: 80778287
 * */

#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "aslib.h"
#include "ascommand.h"
#include <limits.h>
#include <errno.h>

#define REG_IOCONTROL 0x00FF00
#define REG_IOBUFFER_1 0x00FF04
#define REG_IOBUFFER_2 0x00FF08
#define STACK_BASE   (REG_IOCONTROL - 0x00A000)
#define HEAP_BASE    (STACK_BASE - 0x000A00)

//static int sp = STACK_BASE; 
static int hp = HEAP_BASE; 

/* Initialize function pointer
 The individual functions are defined in aslib.c
 There roughly one function for each instruction
 Here we have some functions that are not implemented yet.
 We probably might not need them. Those will be removed 
 after pset5 when everything seems to be working with 
 the functions we have here
 */
 
struct inst_table insts[] = {
	{"sub", &sub},
	{"add", &add},
	{"and", &and},
	{"or", &or},
	{"xor", &xor},
	{"nor", &nor},
	{"slt", &slt},
	{"sll", &sll},
	{"srl", &srl},
	{"sra", &sra},
	{"sllv", &sllv},
	{"srlv", &srlv},
	{"srav", &srav},
	{"jalr", &jalr},
	{"addi", &addi},
	{"slti", &slti},
	{"andi", &andi},
	{"ori", &ori},
	{"xori", &xori},
	{"lui", &lui},
	{"lb", &lb},
	{"lh", &lh},
	{"lwl", &lwl},
	{"lw", &lw},
	{"lbu", &lbu},
	{"lhu", &lhu},
	{"lwr", &lwr},
	{"sb", &sb},
	{"sh", &sh},
	{"sw", &sw},
	{"swl", &swl},
	{"swr", &swr},
	{"jr", &jr},
	{"beq", &beq},
	{"bne", &bne},
	{"j", &j},
	{"jal", &jal},
	//pseudo instructions
	{"la", &la},
	{"nop", &nop},
	{NULL,  NULL},
};


/* Get function takes in name
 * and returns function pointer 
 * @param name, the name of the function
 * @returns function pointer
 */
function_type getFunc(const char * name){
	int i = 0;
	while((insts+i)->name != NULL){
		if (strcmp((insts+i)->name, name) == 0) {
			return (insts + i)->ptr; 
		}
		i++;
	}
	return (function_type) NULL; 
}


/* Check if the line contains a valid instruction
 * @param line, a parsed line from the assembly file
 * @return boolean, true if the line has valid instruction
 */
unsigned int is_valid_inst(const char *line){
	char *tokens[4]; 
	for (int i = 0; i < 4; i++) {
		tokens[i] = ""; 
	}
	getTokens(line, tokens); 
	function_type func = getFunc(tokens[0]); 
	if (func) {
		return 1;
	}
	return 0;
}


/* Is the string a valid int? 
 * @param str, string contain number value
 * @param base number radix
 * @param value, if the number is valid
 * @returns true if a valid int
 */
int isValidInt(const char *str, int base, int *value)
{
	char *endptr;
	long val;
	errno = 0;    
	val = strtol(str, &endptr, base);
	if(*endptr){
		return 0; 
	}
	if ((errno == ERANGE && (val == SHRT_MAX  || val == SHRT_MIN))
			|| (errno != 0 && val == 0)) {
		return 0; 
	}
	if (endptr == str) {
		return 0; 
	}
	*value = val;
	return 1; 
}

/*
 * Description:
 * @param line, input rfile and output MIFfile
 * @returns bits for mif file
 */
char *  processLine(char * line, FILE *rfile, FILE *MIFfile){
	char *tokens[4]; 
	char * bits; 
	for (int i = 0; i < 4; i++) {
		tokens[i] = ""; 
	}
	getTokens(line, tokens); 
	char * printstr = newstr(100);
	function_type func = getFunc(tokens[0]); 
	if (func) {
		bits = func(tokens);
		assert(strlen(bits) == 32);
		int t = bin32toint(bits); 
		memory[wordaddress] = t & 0xFFFF; 
		memory[wordaddress + 1] = (t >> 16) & 0xFFFF; 
		sprintf(printstr, "%s", line);
		printf("%60s ; ", printstr);
		printf("[0x%06X]:0x%08X\n", wordaddress, 
				(memory[wordaddress + 1] << 16)
				|  memory[wordaddress]);
		free(printstr);
		if(DEBUG == 1)
			getchar();
		wordaddress += 2; 
	} else {
		fprintf(stderr, "%s: Instruction not found ..\n", tokens[0]);
		assert(0==1); 
	}
	return bits; 
}

/*
 * Description: Skip list for hardcode labels
 */
static char *sym_skip_list[100] = {
	"main", 
	"REG_IOCONTROL", 
	"REG_IOBUFFER_1", 
	"REG_IOBUFFER_2", 
	"SP", 
	NULL 

}; 

/*
 * Description: check if the symbol is in the skip list
 * @param  symbol name
 * @returns true if the symbol is in the skip list
 */
int is_in_skip_list(char *sym){
	int i = 0 ;
	do {
		if (sym_skip_list[i] && strcmp(sym_skip_list[i], sym) ==0)
			return 1;
	} while(sym_skip_list[i++]); 
	return 0; 
}

int  align4(int address){
	int n; 
	return ((address + 3) & 0xFFFFFFFC); 
}

/*
 * Description: 
 * @param  
 * @returns
 */
int store_string(char *str){
	int value; 
	int store_address = hp; 
	//make sure heap location is initialized
	//and make sure heap is 4 byte memory aligned
	assert(hp >= 0 && hp % 4 == 0);  
	while (*str){
		memory[hp++] = *str++;
	}
	memory[hp] = '\0';
	hp = align4(hp);  //memory align to 4 byte boundary
	return store_address; 
}

char * get_string_from_memory(int address){
	char * res = newstr(100); 
	char * iter = res; 
	while(memory[address] && memory[address] != '\n')
		*iter++ = memory[address++]; 
	*iter = '\0';
	return res; 
}


/*
 * Description: 
 * @param  
 * @returns
 */
void do_first_pass(int argc, const char *argv[]){
	size_t len = 0 ; 
	char * line = NULL; 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	int tmpaddr = 0; 
	//First pass for label fixup
	assert(tmpaddr == 0);
	put_sym("main", tmpaddr);   
	tmpaddr += 2; 
	put_sym("REG_IOCONTROL", REG_IOCONTROL); //hard places, not relative
	put_sym("REG_IOBUFFER_1", REG_IOBUFFER_1); 
	put_sym("REG_IOBUFFER_2", REG_IOBUFFER_2); 
	put_sym("STACK_BASE", STACK_BASE);  
	while(getline(&line, &len, rfile) != EOF){
		cleanLine(&line);
		if (filter(&line))
			continue; 
		if(is_valid_inst(line)){
			tmpaddr += 2; 
		 }
		if (islabel(line)){
			if (isasciiz(line)) {
				char * label = getlabel(line); 
				//store the string at a location
				//and store that location in the symbol table
				int tmpaddr = store_string(getasciiz(line)); 
				put_sym(label, tmpaddr); 
			} else {
				char * label = getlabel(line); 
				if (is_in_skip_list(label)) {
					continue; 
				}
				put_sym(label, tmpaddr); 
			}
		}
	}
	fclose(rfile);
	fclose(MIFfile);
}

/*
 * Description: 
 * @param  
 * @returns
 */
void do_second_pass(int argc, const char *argv[]){
	size_t len = 0 ; 
	char * line = NULL; 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	assert(wordaddress == 0);
	while(getline(&line, &len, rfile) != EOF){
		lineno++; 
		cleanLine(&line);
		if (filter(&line))
			continue; 
		if (islabel(line))
			continue; 
		char * bits = processLine(line, rfile, MIFfile); 
	}
	fclose(rfile);
	fclose(MIFfile);
}

/*
 * Description: 
 * @param  
 * @returns
 */
int main(int argc, const char *argv[])
{
	assert(sizeof(short) == 2); 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	assert(argc == 3); 
	do_first_pass(argc, argv); 
	dump_sym_table(); 
	do_second_pass(argc, argv); 
	outputMIFfile(MIFfile); 
	printf("\nThe output has been written to  %s file .. \n", 
			argv[2]);
	//dump_memory(); 
	return 0;
}

