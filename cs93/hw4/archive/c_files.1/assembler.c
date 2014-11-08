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


//TODO
//DOES NOT YET WORK
char * getHexBits(char * binary, int size){
	char * res = (char *) malloc(size/4+1); 
	memset(res, '\0', size/4+1); 
	int j = 0; 
	char temp[5]; 
	memset(temp, '\0', 5); 
	for (int i = 0; i < size; i=i+4) {
		memcpy(temp, binary+i, 4); 
		memcpy(res+j, binaryToHex(temp), 1); 
		j++; 
	}
	return res; 
}

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
	{NULL,  NULL},
};


void getFiles(int argc, const char * argv[], FILE **rfile, FILE **MIFfile){
	assert(argc == 3); 
	const char * inputfilepath =  argv[1]; 
	const char * outputfilepath =  argv[2]; 

	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 

	*MIFfile = fopen(outputfilepath, "w"); 
	assert (MIFfile != NULL); 
	return ; 
}


void getTokens(const char * line, char * tokens[]){
	const char d[] = "	 ,\n"; 
	char *linecopy;
	linecopy = strdup(line);
	char * token; 
	tokens[0] = strdup(strtok(linecopy, d));
	int i = 1; 
	while ((token = strtok(NULL, d)) != NULL && i <= 4) {
		tokens[i] = strdup(token); 
		i++; 
	}
	return;
}


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

void printSymbolInfo(char * tokens[]) {
	printf("%s(%s, %s, %s)\n", tokens[0], tokens[1], tokens[2], tokens[3]); 
}

void processLine(char * line, FILE *rfile, FILE *MIFfile){
	char *tokens[4]; 
	for (int i = 0; i < 4; i++) {
		tokens[i] = ""; 
	}
	getTokens(line, tokens); 
	function_type func = getFunc(tokens[0]); 
	if (func) {
		fprintf(MIFfile, "%s\n", func(tokens)); 	
		printf("%s\n", func(tokens)); 	
	}
	return; 
}


int main(int argc, const char *argv[])
{
	int lineno = 1; 
	size_t len = 0 ; 
	char * line = NULL; 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	while(getline(&line, &len, rfile) != EOF){
		processLine(line, rfile, MIFfile); 
		lineno++; 
	}
	return 0;
}
