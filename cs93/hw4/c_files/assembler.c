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
	{NULL,  NULL},
};

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


char *  processLine(char * line, FILE *rfile, FILE *MIFfile){
	char *tokens[4]; 
	char * bits; 
	//unsigned int  resultBits; 
	for (int i = 0; i < 4; i++) {
		tokens[i] = ""; 
	}
	getTokens(line, tokens); 
	function_type func = getFunc(tokens[0]); 
	if (func) {
		fprintf(MIFfile, "%s\n", func(tokens)); 	
		bits = func(tokens);
		//resultBits = bin32toint(bits);
		memory[locptr++] = lowertoint(bits); 
		memory[locptr++] = highertoint(bits); 
	} else {
		//fprintf(stderr, "%s: Instruction not found ..\n", tokens[0]);
		printf("%s: Instruction not found ..\n", tokens[0]);
	}
	return bits; 
}

int main(int argc, const char *argv[])
{
	size_t len = 0 ; 
	char * line = NULL; 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	while(getline(&line, &len, rfile) != EOF){
		lineno++; 
		cleanLine(&line);
		//printf("%d: %s\n", lineno, line);
		if (filter(&line))
			continue; 
		if (islabel(line)){
			if (isasciiz(line)) {
				//printf("doasciiz() %d: .asciiz=%s\n", lineno, getasciiz(line));
				; 
			} else {
				char * label = getlabel(line); 
				//printf("label found() %d: %s\n", lineno, label);
				put_sym(label, lineno); 
			}
			continue; 
		}
		/*if(isexp(line)){
			line = doevalexp(line); 
		} 
		if(ispseudo(line)){
			line = dopseudo(line); 
		}*/
		char * bits = processLine(line, rfile, MIFfile); 
		printf("%d:%s:0x%X:0x%X:0x%X\n", 
				lineno, line, bin32toint(bits), 
				highertoint(bits), lowertoint(bits));
	}
	//dump_sym_table();
	for (int i = 0; i < locptr; i++) {
		printf("0x%x\n", memory[i]);
	}
	return 0;
}
