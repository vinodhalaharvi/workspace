#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

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

void printTail(){
	printf("%s\n", "END;\n");

}

void printHeaders(){
	const char * headers = " \
DEPTH = 32;                   -- The size of memory in words\n \
WIDTH = 8;                    -- The size of data in bits\n \
ADDRESS_RADIX = HEX;          -- The radix for address values\n \
DATA_RADIX = BIN;             -- The radix for data values\n \
CONTENT                       -- start of (address : data pairs)\n \
BEGIN\n \
\n \
\n \
\n";  
	printf("%s\n", headers); 
}

