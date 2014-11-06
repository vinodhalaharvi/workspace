#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "command.h"
#include <limits.h>
#include <errno.h>
#define BUFLEN 33


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
