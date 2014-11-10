/* Vinod Halaharvi
 * HUID: 80778287
 * */

#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "command.h"
#include <limits.h>
#include <errno.h>
#define DEBUG 1

#define  STACK_BASE  (0x00FF08-0x00A000)
#define REG_IOCONTROL 0x00FF00
#define REG_IOBUFFER_1 0x00FF04
#define REG_IOBUFFER_2 0x00FF08
static int sp = STACK_BASE; 

/* Initialize function pointer
 The individual functions are defined in lib.c
 There roughly one function for each instruction
 Here we have some functions that are not implemented yet.
 We probably might not need them. Those will be removed 
 after pset5 when everything seems to be working with 
 the functions we have here
 */
 
struct inst_table insts[] = {
	{"lwcz", &lwcz},
	{"swcz", &swcz},
	{"subu", &subu},
	{"sub", &sub},
	{"add", &add},
	{"addu", &addu},
	{"and", &and},
	{"or", &or},
	{"xor", &xor},
	{"nor", &nor},
	{"slt", &slt},
	{"sltu", &sltu},
	{"sll", &sll},
	{"srl", &srl},
	{"sra", &sra},
	{"sllv", &sllv},
	{"srlv", &srlv},
	{"srav", &srav},
	{"jalr", &jalr},
	{"mfhi", &mfhi},
	{"mflo", &mflo},
	{"mult", &mult},
	{"multu", &multu},
	{"_div", &_div},
	{"divu", &divu},
	{"addi", &addi},
	{"addiu", &addiu},
	{"bgez", &bgez},
	{"bgezal", &bgezal},
	{"bltz", &bltz},
	{"bltzal", &bltzal},
	{"slti", &slti},
	{"sltiu", &sltiu},
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
	{"mthi", &mthi},
	{"mtlo", &mtlo},
	{"beq", &beq},
	{"bne", &bne},
	{"blez", &blez},
	{"bgtz", &bgtz},
	{"syscall", &syscall},
	{"_break", &_break},
	{"j", &j},
	{"jal", &jal},
	{"copz", &copz},
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
	int i = 0;
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
	function_type func = getFunc(tokens[0]); 
	if (func) {
		bits = func(tokens);
		assert(address % 2 == 0);
		int t = bin32toint(bits); 
		memory[address] = t & 0xFFFF; 
		memory[address + 2] = (t >> 16) & 0xFFFF; 
		address += 2; 
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
static unsigned int sli;

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


/*
 * Description: 
 * @param  
 * @returns
 */
int store_string(char *str){
	int value; 
	int store_address = sp; 
	assert(STACK_BASE != 0 );  //make sure stack location is initialized
	do {
		value = *(str+1) << 8 | *str; 
		memory[STACK_BASE + sp++] = value; 
		str++; 
	} while(*str); 
	return store_address; 
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

	//First passs for label fixup
	assert(address == 0);
	put_sym("main", address);   
	address += 2; 

	put_sym("REG_IOCONTROL", REG_IOCONTROL); //hard places, not relative
	put_sym("REG_IOBUFFER_1", REG_IOBUFFER_1); 
	put_sym("REG_IOBUFFER_2", REG_IOBUFFER_2); 
	put_sym("STACK_BASE", STACK_BASE);  

	while(getline(&line, &len, rfile) != EOF){
		cleanLine(&line);
		if (filter(&line))
			continue; 
		if(is_valid_inst(line)){
			address += 2; 
		 }
		if (islabel(line)){
			if (isasciiz(line)) {
				char * label = getlabel(line); 
				//store the string at a location
				//and store that location in the symbol table
				//int address = store_string(getasciiz(line)); 
				put_sym(label, address); 
			} else {
				char * label = getlabel(line); 
				if (is_in_skip_list(label)) {
					continue; 
				}
				put_sym(label, address); 
			}
		}
	}
	address = 0;  // reset location_ptr
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
	printf("Helpful for debugging ..\n");
	while(getline(&line, &len, rfile) != EOF){
		lineno++; 
		cleanLine(&line);
		if (filter(&line))
			continue; 
		if (islabel(line))
			continue; 
		char * bits = processLine(line, rfile, MIFfile); 
		if (DEBUG){
			printf("%d:%s:0x%X:0x%X:0x%X\n", 
					lineno, line, bin32toint(bits), 
					highertoint(bits), lowertoint(bits));
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
int main(int argc, const char *argv[])
{
	size_t len = 0 ; 
	char * line = NULL; 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	do_first_pass(argc, argv); 
	dump_sym_table(); 
	do_second_pass(argc, argv); 
	outputMIFfile(MIFfile); 
	printf("%s\n", "\n\nThe output has been written to ./prob.mif file .. " );
	return 0;
}
