#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include <errno.h>
#include <limits.h>

unsigned int get_sym_address(const char * name){
	for (int i = 0; i < symmaxindex; i++) {
		if (strcmp(symbols[i].name, name) == 0) {
			return symbols[i].index; 
		}
	}
	printf("%s %s\n", name, "ERROR: SYMBOL NOT FOUND !!\n");
	assert(1 == 0);
}

unsigned found_sym(const char * name) {
	int i = 0;
	for (int i = 0; i < MAX_SYMBOL_SIZE; i++) {
		if(symbols[i].name != NULL && (strcmp(symbols[i].name, name) == 0))
			return 1; 
	}
	return 0;
}

unsigned dump_sym_table(){
	int i = 0;
	printf("\nSYMBOL TABLE CONTENTS:\n");
	for (int i = 0; i < MAX_SYMBOL_SIZE; i++) {
		if(symbols[i].name != NULL) {
			printf("%s=0x%x\n", symbols[i].name, symbols[i].index);
		}
	}
	return 1;
}

unsigned put_sym(const char * name, unsigned int lineno){
	int i = 0;
	if (found_sym(name)) { 
		fprintf(stderr, "%s:%d: Duplicate symbol found ..\n", name, lineno);
		fprintf(stderr, "Exiting on error .. \n"); 
		exit(0); 
	} else {
		symbols[symmaxindex].name = strdup(name); 
		symbols[symmaxindex].index = MEMORY_START_ADDRESS + lineno; 
		symmaxindex++;
	}
	return 1;
}

void printSymbolInfo(char * tokens[]) {
	printf("%s(%s, %s, %s)\n", tokens[0], tokens[1], tokens[2], tokens[3]); 
}

char * getasciiz(const char *input){
	char *str = (char * ) malloc(strlen(input) + 1);
	memset(str, '\0', strlen(input) + 1);
	sscanf(input, "%*[^\"]%*c%[^\"]%*c%*[^\n]%*c", str);
	return str; 
}

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

int islabel(const char * string){
	return (strchr(string, ':') != NULL); 
}

int isasciiz(const char * string){
	return (strstr(string, ".asciiz") != NULL); 
}

char * getlabel(const char *string){
	int i=0; 
	int count = 0; 
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

void cleanLine(char **lineptr){
	(*lineptr)[strlen(*lineptr)-1] = '\0';  // remove new line 
	char *found = strchr(*lineptr, '#');  //remove everything after '#'
	int index; 
	if (found) {
		index = found - (*lineptr); 
		(*lineptr)[index] = '\0';
	}
}

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


unsigned int lowertoint(char * bits){
        assert(32 == strlen(bits));
	assert(strlen(bits + 16) == 16); 
        return (int) strtol(bits + 16, NULL,  2);
}


unsigned int highertoint(char * bits){
        char * temp = strdup(bits);
        assert(32 == strlen(temp));
        temp[16] = '\0';
        assert(16 == strlen(temp));
        return (int) strtol(temp, NULL,  2);
}

unsigned int hextoint(char * hex){
	return (int)strtol(hex, NULL, 16);
}

unsigned int bin32toint(char * bits){
	assert(strlen(bits) == 32); 
	return (int) strtol(bits, NULL,  2); 
}

unsigned int  bin16toint(char * bits){
	assert(strlen(bits) == 16); 
	return (int) strtol(bits, NULL,  2); 
}

/*
char * tobin(int num, unsigned int size){
	char * bits = (char *) malloc(size+1);
	memset(bits, '\0', size+1);
	itoa(num, bits, 2); 
	return bits; 
}*/

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

void exitOnNull(void * ptr, char * msg){
	if (ptr == NULL) {
		perror(msg); 
		exit(99);
	}
}

void printTail(FILE *MIFfile){
	fprintf(MIFfile, "END;\n");
}

void printHeaders(FILE *MIFfile){
	fprintf(MIFfile, "\n");
	fprintf(MIFfile, "WIDTH=16;\n");
	fprintf(MIFfile, "DEPTH=32768;\n");
	fprintf(MIFfile, "\n");
	fprintf(MIFfile, "ADDRESS_RADIX=HEX;\n");
	fprintf(MIFfile, "DATA_RADIX=HEX;\n");
	fprintf(MIFfile, "\n");
	fprintf(MIFfile, "CONTENT BEGIN\n");
}


/* REFERENCE: This function is taken from class notes */
void outputMIFfile(FILE *MIFfile, char *inputFile) {
	int address, firstAddress, lastAddress;
	uint16_t word;
	printHeaders(MIFfile); 
	address = 0;
	while((address+1) < MIF_FILE_SIZE) {
		firstAddress = address;
		word = memory[address] | (memory[address+1] << 8);
		address += 2;
		if(((address+1) < MIF_FILE_SIZE) &&
				((memory[address] | (memory[address+1] << 8)) == word)) {
			lastAddress = address;
			address += 2;
			while(((address+1) < MIF_FILE_SIZE) &&
					(memory[address] | (memory[address+1] << 8)) == word) {
				lastAddress = address;
				address += 2;
			}
			fprintf(MIFfile, "  [%04X..%04X]: %04X;\n", firstAddress >> 1,
					lastAddress >> 1, word);
		} else {
			fprintf(MIFfile, "  %04X: %04X;\n", firstAddress >> 1, word);
		}
	}
	printTail(MIFfile); 
}

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

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}


char * eval_register(char *expWithParen)
{
	int num1, num2; 
	char op[10]; 
	char *exp = newstr(100);
	sscanf(expWithParen, "(" "%99[^)]" ")", exp); 
	return exp; 
}

unsigned int ifParen(const char *exp){
	if (strchr(exp, '(') != NULL)
		return 1; 
	else 
		return 0; 
}

int eval_exp(char *expWithParen, int *error)
{
	int num1, num2; 
	char op[10], exp[100]; 
	sscanf(expWithParen, "(" "%99[^)]" ")", exp); 
	int n = sscanf(exp, "%i%2s%i", &num1, op, &num2); 
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

int lower_byte(int word16bit){
	return  (word16bit  & 0xFF);
}

int higher_byte(int word16bit) {
	return word16bit >> 8;
}
