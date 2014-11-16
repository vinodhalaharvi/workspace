#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aslib.h"
#include "ascommand.h"
#include <limits.h>
#include <errno.h>
#define BUFLEN 33

/* Vinod Halaharvi
 * HUID 80778287
 */
/*
 * Description:  Most of the functions here take the tokens
 * which have been parsed by the processLine function
 * and return the bits corresponding the that instruction
 * @param tokens 
 * @returns bits corresponding the the instruction  
 */
char * nop(char * tokens[]){
	return "00000000000000000000000000000000";
}

char * sub(char * tokens[]){
	return type6(
		getOpcodebits("sub"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("sub")
	     ); 
}

char * add(char * tokens[]){
	return type6(
		getOpcodebits("add"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("add")
	); 
}

char * and(char * tokens[]){
	return	type6(
		getOpcodebits("and"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("and")
	); 
}

char * or(char * tokens[]){
	return type6(
		getOpcodebits("or"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("or")
	); 
}

char * xor(char * tokens[]){
	return type6(
		getOpcodebits("xor"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("xor")
	); 
}

char * nor(char * tokens[]){
	return type6(
		getOpcodebits("nor"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("nor")
	); 
}

char * slt(char * tokens[]){
	return type6(
		getOpcodebits("slt"), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[1]), 
		"00000", 
		getAluOpcodeBits("slt")
	);  
}

char * sll(char * tokens[]){
	return type6(
		getOpcodebits("sll"), 
		"00000", 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		getBits(atoi(tokens[3]), 5),
		getAluOpcodeBits("sll")
	); 
}

char * srl(char * tokens[]){
	return type6(
		getOpcodebits("srl"), 
		"00000", 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		getBits(atoi(tokens[3]), 5),
		getAluOpcodeBits("srl")
	); 
}

char * sra(char * tokens[]){
	return type6(
		getOpcodebits("sra"), 
		"00000", 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
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
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000",
		getAluOpcodeBits("srlv")
	); 
}

char * srav(char * tokens[]){
	return type6(
		getOpcodebits("srav"), 
		getRegisterBits(tokens[3]), 
		getRegisterBits(tokens[2]), 
		getRegisterBits(tokens[1]), 
		"00000",
		getAluOpcodeBits("srav")
	); 
}

char * addi(char * tokens[]){
	return type4(
                getOpcodebits("addi"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                //getBits(atoi(tokens[3]), 16)
                getBits(verify_atoi(tokens[3]), 16)
        ); 
}

char * slti(char * tokens[]){
	return type4(
                getOpcodebits("slti"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * andi(char * tokens[]){
	return type4(
                getOpcodebits("andi"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * ori(char * tokens[]){
	return type4(
                getOpcodebits("ori"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * xori(char * tokens[]){
	return type4(
                getOpcodebits("xori"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                getBits(atoi(tokens[3]), 16)
        ); 
}

char * la(char * tokens[]){
	char * bits =  type4(
                getOpcodebits("lui"), 
                "00000", 
                getRegisterBits(tokens[1]), 
                getBits(higher_16_byte(verify_atoi(tokens[2])), 16)
        ); 
	int t = bin32toint(bits);
	memory[wordaddress] = t & 0xFFFF; 
	memory[wordaddress + 1] = (t >> 16) & 0xFFFF; 
	wordaddress += 2; 
	return type4(
                getOpcodebits("ori"), 
                getRegisterBits(tokens[1]), 
                getRegisterBits(tokens[1]), 
                getBits(lower_16_byte(verify_atoi(tokens[2])), 16)
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
	return type4(
                getOpcodebits("lb"), 
                getRegisterBits(eval_register(tokens[2])), 
                getRegisterBits(tokens[1]), 
                getBits(register_offset(tokens[2]), 16)
        ); 
}

char * lh(char * tokens[]){
	return type4(
                getOpcodebits("lh"), 
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

char * sb(char * tokens[]){
	return  type4(
                getOpcodebits("sb"), 
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
char * jr(char * tokens[]){
	return type4(
                getOpcodebits("jr"), 
                getRegisterBits(tokens[1]), 
                "000000000000000",
		getAluOpcodeBits("jr")
        ); 
}

char * beq(char * tokens[]){
	return type4(
                getOpcodebits("beq"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                getBits(verify_atoi(tokens[3]), 16)
        ); 
}

char * bne(char * tokens[]){
	return type4(
                getOpcodebits("bne"), 
                getRegisterBits(tokens[2]), 
                getRegisterBits(tokens[1]), 
                getBits(verify_atoi(tokens[3]), 16)
        ); 
}


char * j(char * tokens[]){
	return type2(
                getOpcodebits("j"), 
                getBits(verify_atoi(tokens[1]), 26)
        ); 
}

int verify_atoi(char *token){
	int value = 0; 
	if( isValidInt(token, 10, &value) ||
		isValidInt(token, 16, &value)) {
		return value; 
	} else {
		return get_sym_address(token); 
	}
	assert( 1 == 0 ); 
}

char * jal(char * tokens[]){
	return type2(
			getOpcodebits("jal"), 
			getBits(verify_atoi(tokens[1]), 26)
		    ); 
}

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
