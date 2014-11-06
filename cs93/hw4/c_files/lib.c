#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include <errno.h>
#include <limits.h>

/* Vinod Halaharvi
 * HUID 80778287
 */


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
