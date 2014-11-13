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
		memory[locptr++] = lowertoint(bits); 
		memory[locptr++] = highertoint(bits); 
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

#define  STACK_BASE  (0x00FF08-0x00A000)/0x02
#define REG_IOCONTROL 0x00FF00/0x2
#define REG_IOBUFFER_1 0x00FF04/0x2
#define REG_IOBUFFER_2 0x00FF08/0x2  
static int sp = STACK_BASE; 

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
	assert(locptr == 0);
	put_sym("main", locptr);   
	locptr += 2; 

	put_sym("REG_IOCONTROL", REG_IOCONTROL); //hard places, not relative
	put_sym("REG_IOBUFFER_1", REG_IOBUFFER_1); 
	put_sym("REG_IOBUFFER_2", REG_IOBUFFER_2); 
	put_sym("STACK_BASE", STACK_BASE);  

	while(getline(&line, &len, rfile) != EOF){
		cleanLine(&line);
		if (filter(&line))
			continue; 
		if(is_valid_inst(line)){
			locptr += 2; 
		 }
		if (islabel(line)){
			if (isasciiz(line)) {
				char * label = getlabel(line); 
				//store the string at a location
				//and store that location in the symbol table
				int address = store_string(getasciiz(line)); 
				put_sym(label, address); 
			} else {
				char * label = getlabel(line); 
				if (is_in_skip_list(label)) {
					continue; 
				}
				put_sym(label, locptr); 
			}
		}
	}
	locptr = 0;  // reset location_ptr
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "command.h"
#include <limits.h>
#include <errno.h>
#define BUFLEN 33


/*
 * Description:  Most of the functions here take the tokens
 * which have been parsed by the processLine function
 * and return the bits corresponding the that instruction
 * @param tokens 
 * @returns bits corresponding the the instruction  
 */



char * lwcz(char * tokens[]){
	return "NOT IMPLEMENTED!"; 
}

char * swcz(char * tokens[]){
	return "not implemented!"; 
}

char * nop(char * tokens[]){
	return "00000000000000000000000000000000";
}
char * subu(char * tokens[]){
	return type6(
		getOpcodebits("subu"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("sub")
	     ); 
}

char * sub(char * tokens[]){
	return subu(tokens); 
}

char * add(char * tokens[]){
	return addu(tokens); 
}

char * addu(char * tokens[]){
	return type6(
		getOpcodebits("addu"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("addu")
	); 
}

char * and(char * tokens[]){
	return	type6(
		getOpcodebits("and"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("and")
	); 
}

char * or(char * tokens[]){
	return type6(
		getOpcodebits("or"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("or")
	); 
}

char * xor(char * tokens[]){
	//instead of getting this string
	//we have to generate a 32 bit number
	//and store it in the memmory and update 
	//the locptr
	return type6(
		getOpcodebits("xor"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("xor")
	); 
}

char * nor(char * tokens[]){
	return type6(
		getOpcodebits("nor"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("nor")
	); 
}

char * slt(char * tokens[]){
	return sltu(tokens); 
}

char * sltu(char * tokens[]){
	return type6(
		getOpcodebits("sltu"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("sltu")
	); 
}

char * sll(char * tokens[]){
	return type6(
		getOpcodebits("sll"), 
		"00000", 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
		getBits(atoi(tokens[3]), 5),
		getAluOpcodeBits("sll")
	); 
}

char * srl(char * tokens[]){
	return type6(
		getOpcodebits("srl"), 
		"00000", 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
		getBits(atoi(tokens[3]), 5),
		getAluOpcodeBits("srl")
	); 
}

char * sra(char * tokens[]){
	return type6(
		getOpcodebits("sra"), 
		"00000", 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
		getBits(atoi(tokens[3]), 5),
		getAluOpcodeBits("sra")
	); 
}

char * sllv(char * tokens[]){
	return type6(
		getOpcodebits("sllv"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000",
		getAluOpcodeBits("sllv")
	); 
}

char * srlv(char * tokens[]){
	return type6(
		getOpcodebits("srlv"), 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		"00000",
		getAluOpcodeBits("srlv")
	); 
}

char * srav(char * tokens[]){
	return type6(
		getOpcodebits("srav"), 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		"00000",
		getAluOpcodeBits("srav")
	); 
}

char * jalr(char * tokens[]){
	return type6(
		getOpcodebits("jalr"), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getRegisterBits(tokens[2]), 
		"00000",
		getAluOpcodeBits("jalr")
	); 
}

char * mfhi(char * tokens[]){
	return type5(
		getOpcodebits("mfhi"), 
		"0000000000", 
		getRegisterBits(tokens[1]), 
		"00000",
		getAluOpcodeBits("mfhi")
	); 
}

char * mflo(char * tokens[]){
	return type5(
		getOpcodebits("mflo"), 
		"0000000000", 
		getRegisterBits(tokens[1]), 
		"00000",
		getAluOpcodeBits("mflo")
	); 
}

char * mult(char * tokens[]){
	return multu(tokens);
}

char * multu(char * tokens[]){
	return type5(
		getOpcodebits("multu"), 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
                "0000000000",
		getAluOpcodeBits("multu")
	); 
}

char * _div(char * tokens[]){
	return divu(tokens);
}

char * divu(char * tokens[]){
	return type5(
		getOpcodebits("divu"), 
		getRegisterBits(tokens[1]), 
		getRegisterBits(tokens[2]), 
                "0000000000",
		getAluOpcodeBits("divu")
	); 
}

char * addi(char * tokens[]){
	return addiu(tokens); 
}

char * addiu(char * tokens[]){
	return type4(
                getOpcodebits("addiu"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * bgez(char * tokens[]){
	return type4(
                getOpcodebits("bgez"), 
                getRegisterBits(tokens[1]), 
                "00001", 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * bgezal(char * tokens[]){
	return type4(
                getOpcodebits("bgezal"), 
                getRegisterBits(tokens[1]), 
                "10001", 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * bltz(char * tokens[]){
	return type4(
                getOpcodebits("bltz"), 
                getRegisterBits(tokens[1]), 
                "00000", 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * bltzal(char * tokens[]){
	return type4(
                getOpcodebits("bltzal"), 
                getRegisterBits(tokens[1]), 
                "10000", 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * slti(char * tokens[]){
	return sltiu(tokens); 
}

char * sltiu(char * tokens[]){
	return type4(
                getOpcodebits("sltiu"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * andi(char * tokens[]){
	return type4(
                getOpcodebits("andi"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * ori(char * tokens[]){
	return type4(
                getOpcodebits("ori"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * xori(char * tokens[]){
	return type4(
                getOpcodebits("xori"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * la(char * tokens[]){
	char * bits =  type4(
                getOpcodebits("lui"), 
                "00000", 
                getRegisterBits(tokens[1]), 
                getBits(higher_byte(verify_atoi(tokens[2])), 16)
        ); 
	memory[locptr++] = lowertoint(bits); 
	memory[locptr++] = highertoint(bits); 
	return type4(
                getOpcodebits("ori"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[1]), 
                getBits(lower_byte(verify_atoi(tokens[2])), 16)
        ); 
}

char * lui(char * tokens[]){
	return type4(
                getOpcodebits("lui"), 
                "00000", 
                getRegisterBits(tokens[1]), 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * lb(char * tokens[]){
	return lbu(tokens);
}

char * lh(char * tokens[]){
	return lhu(tokens);
}

char * lwl(char * tokens[]){
	return type4(
                getOpcodebits("lwl"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * lw(char * tokens[]){
	return type4(
                getOpcodebits("lw"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * lbu(char * tokens[]){
	return type4(
                getOpcodebits("lbu"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * lhu(char * tokens[]){
	return type4(
                getOpcodebits("lhu"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * lwr(char * tokens[]){
	return type4(
                getOpcodebits("lwr"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * sb(char * tokens[]){
	return  type4(
                getOpcodebits("sb"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * sh(char * tokens[]){
	return type4(
                getOpcodebits("sh"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * sw(char * tokens[]){
	return type4(
                getOpcodebits("sw"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * swl(char * tokens[]){
	return type4(
                getOpcodebits("swl"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * swr(char * tokens[]){
	return type4(
                getOpcodebits("swr"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * jr(char * tokens[]){
	return type4(
                getOpcodebits("jr"), 
                getRegisterBits(tokens[1]), 
                "000000000000000",
		getAluOpcodeBits("jr")
        ); 
}

char * mthi(char * tokens[]){
	return type4(
                getOpcodebits("mthi"), 
                getRegisterBits(tokens[1]), 
                "000000000000000",
		getAluOpcodeBits("mthi")
        ); 
}

char * mtlo(char * tokens[]){
	return type4(
                getOpcodebits("mtlo"), 
                getRegisterBits(tokens[1]), 
                "000000000000000",
		getAluOpcodeBits("mtlo")
        ); 
}

char * beq(char * tokens[]){
	return type4(
                getOpcodebits("beq"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(verify_atoi(tokens[3]), 16)
        ); 
}

char * bne(char * tokens[]){
	return type4(
                getOpcodebits("bne"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[2]), 
                getBits(verify_atoi(tokens[3]), 16)
        ); 
}

char * blez(char * tokens[]){
	return type4(
                getOpcodebits("blez"), 
                getRegisterBits(tokens[1]), 
                "00000", 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * bgtz(char * tokens[]){
	return type4(
                getOpcodebits("bgtz"), 
                getRegisterBits(tokens[1]), 
                "00000", 
                getBits(verify_atoi(tokens[2]), 16)
        ); 
}

char * syscall(char * tokens[]){
	return type3(
                getOpcodebits("syscall"), 
                getBits(atoi(tokens[1]), 20), 
		getAluOpcodeBits("syscall")
        ); 
}

char * _break(char * tokens[]){
	return type3(
                getOpcodebits("break"), 
                getBits(atoi(tokens[1]), 22), 
		getAluOpcodeBits("break")
        ); 
}


char * j(char * tokens[]){
	return type2(
                getOpcodebits("j"), 
                getBits(verify_atoi(tokens[1]), 26)
        ); 
}

int verify_atoi(char *token){
	int value = 0 ; 
	if( isValidInt(token, 10, &value) ||
		isValidInt(token, 16, &value)) {
		return value; 
	} else {
		return get_sym_address(token); 
	}
}


char * jal(char * tokens[]){
	return type2(
			getOpcodebits("jal"), 
			getBits(verify_atoi(tokens[1]), 26)
		    ); 
}

char * copz(char * tokens[]){
	return type2(
                getOpcodebits("copz"), 
                getBits(atoi(tokens[1]), 26)
        ); 
}
/*
 * Description: 
 * @param  
 * @returns
 */

char * type2(char * arg0, char * arg1){
	char *res = (char *) malloc(BUFLEN); 
	memset(res, '\0', BUFLEN); 
	sprintf(res, "%s%s", arg0, arg1); 
	return res; 
}

char * type3(char * arg0, char * arg1, char * arg2){
	char *res = (char *) malloc(BUFLEN); 
	memset(res, '\0', BUFLEN); 
	sprintf(res, "%s%s%s", arg0, arg1, arg2); 
	return res; 
}

char * type4(char * arg0, char * arg1, char *arg2, char *arg3){
	char *res = (char *) malloc(BUFLEN); 
	memset(res, '\0', BUFLEN); 
	sprintf(res, "%s%s%s%s", arg0, arg1, arg2, arg3); 
	return res; 
}

char * type5(char * arg0, char * arg1, char *arg2, char *arg3, char *arg4){
	char *res = (char *) malloc(BUFLEN); 
	memset(res, '\0', BUFLEN); 
	sprintf(res, "%s%s%s%s%s", 
			arg0, arg1, arg2, arg3, arg4); 
	return res; 
}

char * type6(char * arg0, char * arg1, char *arg2, char *arg3, char *arg4, char *arg5){
	char *res = (char *) malloc(BUFLEN); 
	memset(res, '\0', BUFLEN); 
	sprintf(res, "%s%s%s%s%s%s", 
			arg0, arg1, arg2, arg3, arg4, arg5); 
	return res; 
}
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include <errno.h>
#include <limits.h>

/*
 * Description:  Get the address of the symbol from symbol table
 * @param symbol name
 * @returns symbol address in the symbol table
 */
unsigned int get_sym_address(const char * name){
	for (int i = 0; i < symmaxindex; i++) {
		if (strcmp(symbols[i].name, name) == 0) {
			return symbols[i].index; 
		}
	}
	fprintf(stderr, "name: %s;  %s\n", name, "error: symbol not found !!\n");
	assert(1 == 0);
}

/*
 * Description:  Is this symbol in the symbol table? 
 * @param  symbol name
 * @returns boolean, true if name found
 */
unsigned found_sym(const char * name) {
	for (int i = 0; i < MAX_SYMBOL_SIZE; i++) {
		if(symbols[i].name != NULL && (strcmp(symbols[i].name, name) == 0))
			return 1; 
	}
	return 0;
}

/*
 * Description: Helper function to dump the symbol table 
 * @param  void
 * @returns 1 if success
 */
unsigned dump_sym_table(){
	printf("\nsymbol table contents:\n");
	for (int i = 0; i < MAX_SYMBOL_SIZE; i++) {
		if(symbols[i].name != NULL) {
			printf("%s=0x%x\n", symbols[i].name, symbols[i].index);
		}
	}
	printf("\n");
	return 1;
}

/*
 * Description:  insert symbol in the symbol table
 * @param   symbol name and address
 * @returns 1 if successful 
 */
unsigned put_sym(const char * name, unsigned int loc){
	if (found_sym(name)) { 
		fprintf(stderr, "%s:%d: Duplicate symbol found ..\n", name, loc);
		fprintf(stderr, "Exiting on error .. \n"); 
		exit(0); 
	} else {
		symbols[symmaxindex].name = strdup(name); 
		symbols[symmaxindex].index = MEMORY_START_ADDRESS + loc; 
		symmaxindex++;
	}
	return 1;
}

/*
 * Description: get the line containing  the asciiz string
 * @param  input line
 * @returns asciiz string
 */
char * getasciiz(const char *input){
	char *str = (char * ) malloc(strlen(input) + 1);
	memset(str, '\0', strlen(input) + 1);
	sscanf(input, "%*[^\"]%*c%[^\"]%*c%*[^\n]%*c", str);
	return str; 
}


/*
 * Description:  is this a valid lable?
 * @param label name
 * @returns boolean true/false
 */
int islabel(const char * string){
	return (strchr(string, ':') != NULL); 
}

/*
 * Description: 
 * @param  
 * @returns
 */
int isasciiz(const char * string){
	return (strstr(string, ".asciiz") != NULL); 
}

/*
 * Description:  get label from line
 * @param input line
 * @returns label
 */
char * getlabel(const char *string){
	int i=0; 
	assert (string != NULL); 
	char * res = (char *) malloc(strlen(string)+1); 
	memset(res, '\0', strlen(string)+1); 
	int j = 0;
	while(string[i] != '\0') {
		if (string[i] != ' ' 
			&& string[i] != '\t' 
			&& string[i] != '\n'
			&& string[i] != ':') {
			res[j++] = string[i]; 
		}
		if (string[i] == ':')
			return res; 
		i++;
	}
	return res;
}

/*
 * Description: get input and output files 
 * @param  argc, argv, input file and output MIF file handlers
 * @returns void
 */
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


/*
 * Description: parse a line and return tokens split using space or a  
 * @param line from an assembly program
 * @returns void
 */
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

/*
 * Description: clean the line in assembly program 
 * @param pointer to the line 
 * @returns void
 */
void cleanLine(char **lineptr){
	(*lineptr)[strlen(*lineptr)-1] = '\0';  // remove new line 
	char *found = strchr(*lineptr, '#');  //remove everything after '#'
	int index; 
	if (found) {
		index = found - (*lineptr); 
		(*lineptr)[index] = '\0';
	}
}

/*
 * Description:  is this line empty
 * @param   line
 * @returns boolean true/false
 */
int isempty(const char *string){
	int i=0; 
	int count = 0; 
	if (string == NULL)
		return 1; 
	while(string[i] != '\0') {
		if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n') {
			count++; 
		}
		i++;
	}
	return (count == 0); 
}

/*
 * Description: Should this line be ignored from processing 
 * @param  line pointer 
 * @returns boolean true/false
 */
int filter(char **lineptr){
	if (strstr(*lineptr, ".data"))  {
		return 1; 
	}
	if (isempty(*lineptr))
		return 1; 
	if (strstr(*lineptr, ".text"))
		return 1; 
	if (strstr(*lineptr, ".text"))
		return 1; 
	return 0;
}


/*
 * Description: convert the lower 16 bits work to int and return
 * @param 32 bit word
 * @returns lower 16 bits 
 */
unsigned int lowertoint(char * bits){
        assert(32 == strlen(bits));
	assert(strlen(bits + 16) == 16); 
        return (int) strtol(bits + 16, NULL,  2);
}


/*
 * Description: convert the higher 16 bits work to int and return
 * @param 32 bit word
 * @returns higher 16 bits 
 *
 */
unsigned int highertoint(char * bits){
        char * temp = strdup(bits);
        assert(32 == strlen(temp));
        temp[16] = '\0';
        assert(16 == strlen(temp));
        return (int) strtol(temp, NULL,  2);
}

/*
 * Description:  convert hex to int
 * @param  
 * @returns
 */
unsigned int hextoint(char * hex){
	return (int)strtol(hex, NULL, 16);
}

/*
 * Description: convert binary to int
 * @param  
 * @returns
 */
unsigned int bin32toint(char * bits){
	assert(strlen(bits) == 32); 
	return (int) strtol(bits, NULL,  2); 
}

/* 
 * Description:  convert bin 16 bits to int
 * @param  
 * @returns
 */
unsigned int  bin16toint(char * bits){
	assert(strlen(bits) == 16); 
	return (int) strtol(bits, NULL,  2); 
}

/*
 * Description: get operation code bits for an instruction 
 * @param  
 * @returns
 */
char * getOpcodebits(char *name){
	int i = 0; 
	while (inst_data[i].instname != NULL) {
		if (strcmp(inst_data[i].instname,name) == 0 ){
			return  inst_data[i].opcodebits; 
		}
		i++; 
	}
	return NULL; 
}

/*
 * Description: convert the number to bits of given SIZE
 * @param  
 * @returns
 */
char * getBits(int num, unsigned int SIZE) { 
	char * bits = (char * ) malloc(SIZE+1);
	memset(bits, '\0', SIZE+1); 
	for (int i = 0; i < SIZE; i++) {
		if ( num >> i & 1)
			bits[SIZE-i-1] = '1'; 
		else 
			bits[SIZE-i-1] = '0'; 
	}   
	return bits; 
}

/*
 * Description:  Convert register pneumonic to bits
 * @param  
 * @returns
 */
char * getRegisterBits(char *registername){
	int i = 0; 
	//Does the register name match ?
	while (register_data[i].registername != NULL) {
		if (strcmp(register_data[i].registername,registername) == 0 ){
			return  register_data[i].registerbits; 
		}
		i++; 
	}
	i = 0; 
	// Does the register number match ? 
	while (register_data[i].registernumber != NULL) {
		if (strcmp(register_data[i].registernumber,registername) == 0 ){
			return  register_data[i].registerbits; 
		}
		i++; 
	}
	fprintf(stderr, "%s: No such register ..\n", registername);
	assert(1 == 0); 
	//we should never be here
	return NULL; 
}

/*
 * Description:  Get Alu operation code bits
 * @param  
 * @returns
 */
char * getAluOpcodeBits(char *name){
	int i = 0; 
	while (inst_data[i].instname != NULL) {
		if (strcmp(inst_data[i].instname,name) == 0 ){
			return  inst_data[i].aluopcodebits; 
		}
		i++; 
	}
	return NULL; 
}

/*
 * Description:  binary to Hex converter
 * @param  
 * @returns
 */
char * binaryToHex(char * binary){
	int i = 0; 
	while (encoding_data[i].binary != NULL) {
		if (strcmp(encoding_data[i].binary, binary) == 0){
			return  encoding_data[i].hex; 
		}
		i++; 
	}
	return NULL; 
}

/*
 * Description:  helper function to exit on null value
 * @param  
 * @returns
 */
void exitOnNull(void * ptr, char * msg){
	if (ptr == NULL) {
		perror(msg); 
		exit(99);
	}
}

/*
 * Description:  print end for mif file
 * @param  
 * @returns
 */
void printTail(FILE *MIFfile){
	fprintf(MIFfile, "END;\n");
	fflush(MIFfile); 
}

/*
 * Description:  print mif file header
 * @param  
 * @returns
 */
void printHeaders(FILE *MIFfile){
	fprintf(MIFfile, "\n");
	fprintf(MIFfile, "WIDTH=16;\n");
	fprintf(MIFfile, "DEPTH=32768;\n");
	fprintf(MIFfile, "\n");
	fprintf(MIFfile, "ADDRESS_RADIX=HEX;\n");
	fprintf(MIFfile, "DATA_RADIX=HEX;\n");
	fprintf(MIFfile, "\n");
	fprintf(MIFfile, "CONTENT BEGIN\n");
	fflush(MIFfile); 
}


/*
 * Description:  print the mif file contents
 * @param  
 * @returns
 */
void outputMIFfile(FILE *MIFfile) {
	uint16_t word;
	printHeaders(MIFfile); 
	for (int i = 0; i < locptr; i++) {
		fprintf(MIFfile, "  %04X: %04X;\n", i, memory[i]); 
	}
	fflush(MIFfile); 
	printTail(MIFfile); 
}

/*
 * Description:  remove spaces from the line,need for expression parsing
 * @param  
 * @returns
 */
char * removeSpaces(const char * s) {
	char * d = strdup(s); 
	char * res = d; 
	memset(d, '\0', strlen(s) + 1);
	do {
		if (!isspace(*s++))
			*d++ = *(s-1); 
	} while(!(*s == '\0'));
	return res; 
}

/*
 * Description:  allocate new string
 * @param  
 * @returns
 */
char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}


/*
 * Description: get register bits from for ex ($t1) 
 * @param  
 * @returns
 */
char * eval_register(char *expWithParen)
{
	char *exp = newstr(100);
	sscanf(expWithParen, "(" "%99[^)]" ")", exp); 
	return exp; 
}

/*
 * Description:  get offset applied to register for eg 0($t2)
 * @param  
 * @returns
 */
int register_offset(char * input){
	int offset; 
	char reg[2];
	int t = sscanf(input, "%i(%2s)", &offset, reg); 
	assert(t != -1); 
	return offset; 
}

/*
 * Description:  get register name from for ex 0($t1)
 * @param  
 * @returns
 */
char * register_name(char * input){
	int offset; 
	char *reg = newstr(2); 
	int t = sscanf(input, "%i(%2s)", &offset, reg); 
	assert(t != -1); 
	return reg; 
}


//test for presence of parenthesis in a string
unsigned int ifParen(const char *exp){
	if (strchr(exp, '(') != NULL)
		return 1; 
	else 
		return 0; 
}

/*
 * Description:  simple expression evaluater
 * @param  
 * @returns
 */
int eval_exp(char *expWithParen, int *error)
{
	int num1, num2; 
	char op[10], exp[100]; 
	sscanf(expWithParen, "(" "%99[^)]" ")", exp); 
	int n = sscanf(exp, "%i%2s%i", &num1, op, &num2); 
	assert(n != -1); 
	if (n == 3) {
		if (strcmp(op, "<<") == 0) { return num1 << num2; 
		} else if (strcmp(op, ">>") == 0) { *error = 0 ; return num1 >> num2; 
		} else if (strcmp(op, "+") == 0) { *error = 0 ; return num1 + num2; 
		} else if (strcmp(op, "-") == 0) { *error = 0 ; return num1 - num2; 
		} else if (strcmp(op, "/") == 0) { *error = 0 ; return num1 / num2; 
		} else if (strcmp(op, "*") == 0) { *error = 0 ; return num1 * num2; 
		} else if (strcmp(op, "%") == 0) { *error = 0 ; return num1 % num2; 
		} else if (strcmp(op, "&") == 0) { *error = 0 ; return num1 & num2; 
		} else if (strcmp(op, "|") == 0) { *error = 0 ; return num1 | num2; 
		} else if (strcmp(op, "^") == 0) { *error = 0 ; return num1 ^ num2; 
		}
	}
	*error = 1; 
	return -1; 
}

/*
 * Description:  get lower byte from 16 bit word
 * @param  
 * @returns
 */
int lower_byte(int word16bit){
	return  (word16bit  & 0xFF);
}

/*
 * Description:  get higher byte from 16 bit word
 * @param  
 * @returns
 */
int higher_byte(int word16bit) {
	return word16bit >> 8;
}
