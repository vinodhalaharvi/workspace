#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *aluopcode[64] = {"na"};  
char *opcode[64] = {"na"}; 

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
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

unsigned int hextoint(char * hex){
	return (int)strtol(hex, NULL, 16);
}


void getFiles(int argc, const char * argv[], FILE **rfile){
	assert(argc == 2); 
	const char * inputfilepath =  argv[1]; 
	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 
	return ; 
}

unsigned int toint(char * bits){
	assert(strlen(bits) == 5); 
	return (int) strtol(bits, NULL,  2); 
}

int registers[32]; 


int sll(int rt, int rd, int sa){
	printf("%s\n", "sll");
	registers[rd] = registers[rt] << sa; 
	return 0; 
}

int srl(int rt, int rd, int sa){
	printf("%s\n", "srl");
	return 0;
}


int sra(int rt, int rd, int sa){
	printf("%s\n", "sra");
	return 0;
}

int sllv(int rs, int rt, int rd){
	printf("%s\n", "sllv");
	return 0;
}

int srlv(int rs, int rt, int rd){
	printf("%s\n", "srlv");
	return 0;
}

int srav(int rs, int rt, int rd){
	printf("%s\n", "srav");
	return 0;
}

int jr(int rs){
	printf("%s\n", "jr");
	return 0;
}

int jalr(int rs, int rd){
	printf("%s\n", "jalr");
	return 0;
}

int add(int rs, int rt, int rd){
	printf("%s\n", "add");
	return 0;
}

int addu(int rs, int rt, int rd){
	printf("%s\n", "addu");
	return 0;
}

int sub(int rs, int rt, int rd){
	printf("%s\n", "sub");
	return 0;
}

int subu(int rs, int rt, int rd){
	printf("%s\n", "subu");
	return 0;
}

int and(int rs, int rt, int rd){
	printf("and\n");
	return 0;
}

int or(int rs, int rt, int rd){
	printf("%s\n", "or");
	return 0;
}

int xor(int rs, int rt, int rd){
	printf("%s\n", "xor");
	return 0;
}

int nor(int rs, int rt, int rd){
	printf("%s\n", "nor");
	return 0;
}

int slt(int rs, int rt, int rd){
	printf("%s\n", "slt");
	return 0;
}

int sltu(int rs, int rt, int rd){
	printf("%s\n", "sltu");
	return 0;
}

int j(int inst_idnex){

	return 0;
}

int jal(int inst_idnex){

	return 0;
}


int beq(int rs, int rt, int offset){

	return 0;
}

int bne(int rs, int rt, int offset){

	return 0;
}


int blez(int rs, int offset){
	return 0;
}


int bgtz(int rs, int offset){
	return 0;

}


int addiu(int rs, int rt, int imm){
	return 0;
}


int slti(int rs, int rt, int imm){
	return 0;
}

int sltiu(int rs, int rt, int imm){
	return 0;

}
int andi(int rs, int rt, int imm){
	return 0;
}


int xori(int rs, int rt, int imm){

	return 0;
}

int addi(int rs, int rt, int imm){

	return 0;
}


int ori(int rs, int rt, int imm){

	return 0;
}

int lui(int rt, int imm){

	return 0;
}

int lb(int base , int rt, int offset){
	return 0;
}

int lh(int base , int rt, int offset){
	return 0;
}

int lwl(int base , int rt, int offset){
	return 0;
}

int lw(int base , int rt, int offset){
	return 0;
}

int lbu(int base , int rt, int offset){
	return 0;
}

int lhu(int base , int rt, int offset){
	return 0;
}

int lwr(int base , int rt, int offset){
	return 0;
}

int sb(int base , int rt, int offset){
	return 0;
}

int sh(int base , int rt, int offset){
	return 0;
}

int sw(int base , int rt, int offset){
	return 0;
}

int swl(int base , int rt, int offset){
	return 0;
}

int swr(int base , int rt, int offset){
	return 0;
}

int bgez(int rs, int offset){
	return 0;
}

int bgezal(int rs, int offset){
	return 0;
}

int bltz(int rs, int offset){
	return 0;
}

int bltzal(int rs, int offset){
	return 0;

}


int main(int argc, const char *argv[])
{
	char * input[20] = {
		"00000000000000000000000000000000x",
		"00000000000000000000000000000010x",
		"00000000000000000000000000000011x",
		"00000000000000000000000000000100x",
		"00000000000000000000000000000110x",
		"00000000000000000000000000000111x",
		"00000000000000000000000000001000x",
		"00000000000000000000000000001001x",
		"00000000000000000000000000100000x",
		"00000000000000000000000000100110x",
		"00000000000000000000000000100001x",
		"00000000000000000000000000100010x",
		"00000000000000000000000000100011x",
		"00000000000000000000000000100100x",
		"00000000000000000000000000100101x",
		"00000000000000000000000000101011x",
		"00000000000000000000000000100111x",
		"00000000000000000000000000101010x",
	}; 

	char * rs = newstr(10); 
	char * rt = newstr(10); 
	char * rd = newstr(10); 
	char * ig = newstr(2); 
	char * base = newstr(5);
	char * sa = newstr(5);
	char * offset = newstr(16);
	char * imm = newstr(16);
	char * inst_index = newstr(26);
	int count = 18; 


	for (int i = 0; i < count; i++) {
		assert(strlen(input[i]) == 33); 
		printf("%s\n", input[i]);
		if(sscanf(input[i], "00000000000%5s%5s%5s000000%1s", rt, rd, sa, ig) ==4)
			sll(toint(rt), toint(rd), toint(sa)); 
		if(sscanf(input[i], "00000000000%5s%5s%5s000010%1s", rt, rd, sa, ig) ==4)
			srl(toint(rt), toint(rd), toint(sa));
		if(sscanf(input[i], "00000000000%5s%5s%5s000011%1s", rt, rd, sa, ig) ==4)
			sra(toint(rt), toint(rd), toint(sa));
		if(sscanf(input[i], "000000%5s%5s%5s00000000100%1s", rs, rt, rd, ig) ==4)
			sllv(toint(rs), toint(rt), toint(rd)); 
		if(sscanf(input[i], "000000%5s%5s%5s00000000110%1s", rs, rt, rd, ig) ==4)
			srlv(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000000111%1s", rs, rt, rd, ig) ==4)
			srav(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s000000000000000001000%1s", rs, ig) ==2)
			jr(toint(rs));
		if(sscanf(input[i], "000000%5s00000%5s00000001001%1s", rs, rd, ig) ==3)
			jalr(toint(rs), toint(rd)); 
		if(sscanf(input[i], "000000%5s%5s%5s00000100000%1s", rs, rt, rd, ig) ==4)
			add(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100001%1s", rs, rt, rd, ig) ==4)
			addu(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100010%1s", rs, rt, rd, ig) ==4)
			sub(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100011%1s", rs, rt, rd, ig) ==4)
			subu(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100100%1s", rs, rt, rd, ig) ==4)
			and(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100101%1s", rs, rt, rd, ig) ==4)
			or(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100110%1s", rs, rt, rd, ig) ==4)
			xor(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000100111%1s", rs, rt, rd, ig) ==4)
			nor(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000101010%1s", rs, rt, rd, ig) ==4)
			slt(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000000%5s%5s%5s00000101011%1s", rs, rt, rd, ig) ==4)
			sltu(toint(rs), toint(rt), toint(rd));
		if(sscanf(input[i], "000010%26s%1s", inst_index, ig) ==2)
			j(toint(inst_index)); 
		if(sscanf(input[i], "000011%26s%1s", inst_index, ig) ==2)
			jal(toint(inst_index)); 
		if(sscanf(input[i], "000100%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
			beq(toint(rs), toint(rt), toint(offset)); 
		if(sscanf(input[i], "000101%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
			bne(toint(rs), toint(rt), toint(offset)); 
		if(sscanf(input[i], "000110%5s00000%16s%1s", rs, offset, ig) ==3)
			blez(toint(rs), toint(offset)); 
		if(sscanf(input[i], "000111%5s00000%16s%1s", rs, offset, ig) ==3)
			bgtz(toint(rs), toint(offset)); 
		if(sscanf(input[i], "001000%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			addi(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "001001%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			addiu(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "001010%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			slti(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "001011%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			sltiu(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "001100%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			andi(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "001101%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			ori(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "001110%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
			xori(toint(rs), toint(rt), toint(imm));
		if(sscanf(input[i], "00111100000%5s%16s%1s",  rt, imm, ig) ==3)
			lui(toint(rt), toint(imm)); 
		if(sscanf(input[i], "100000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lb(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "100001%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lh(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "100010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lwl(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "100011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lw(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "100100%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lbu(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "100101%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lhu(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "100110%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			lwr(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "101000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			sb(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "101001%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			sh(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "101010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			sw(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "101011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			swl(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "101110%5s%5s%16s%1s", base, rt, offset, ig) ==4)
			swr(toint(base), toint(rt), toint(offset));
		if(sscanf(input[i], "000001%5s00001%16s%1s", rs, offset, ig) ==3)
			bgez(toint(rs), toint(offset));
		if(sscanf(input[i], "000001%5s10001%16s%1s", rs, offset, ig) ==3)
			bgezal(toint(rs), toint(offset));
		if(sscanf(input[i], "000001%5s00000%16s%1s", rs, offset, ig) ==3)
			bltz(toint(rs), toint(offset));
	if(sscanf(input[i], "000001%5s10000%16s%1s", rs, offset, ig) ==3)
			bltzal(toint(rs), toint(offset));
	}

	//assert(1 == 0); 
	return 0; 
}
