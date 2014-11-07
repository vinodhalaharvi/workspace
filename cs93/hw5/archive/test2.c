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
	registers[rd] = registers[rt] << sa; 
}

int srl(int rt, int rd, int sa){
	return 0;
}


int sra(int rt, int rd, int sa){
	return 0;
}

int sllv(int rs, int rt, int rd){
	return 0;
}

int srlv(int rs, int rt, int rd){
	return 0;
}

int srav(int rs, int rt, int rd){
	return 0;
}

int jr(int rs){
	return 0;
}

int jalr(int rs, int rd){
	return 0;
}

int add(int rs, int rt, int rd){

	return 0;
}

int addu(int rs, int rt, int rd){
	return 0;
}

int sub(int rs, int rt, int rd){

	return 0;
}

int subu(int rs, int rt, int rd){
	return 0;
}

int and(int rs, int rt, int rd){
	return 0;
}

int or(int rs, int rt, int rd){
	return 0;
}

int xor(int rs, int rt, int rd){

	return 0;
}

int nor(int rs, int rt, int rd){

	return 0;
}

int slt(int rs, int rt, int rd){
	return 0;
}

int sltu(int rs, int rt, int rd){

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

}


int addiu(int rs, int rt, int imm){
	return 0;
}


int slti(int rs, int rt, int imm){

	return 0;
}

int sltiu(int rs, int rt, int imm){

}
int andi(int rs, int rt, int imm){
	return 0;
}


int xori(int rs, int rt, int imm){

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



int main(int argc, const char *argv[])
{
	//char * bits =  getBits(hextoint("0xFFFF"), 16);
	//printf("%d\n", strtol(bits, 16));
	//return 0; 
	//assert(strlen(bits) == 16); 
	//printf("%s\n", bits);
	//return 0;
	char * input = "00000000010001100000000000100011"; 
	assert(strlen(input) == 32); 

	char * rs = newstr(10); 
	char * rt = newstr(10); 
	char * rd = newstr(10); 
	char * base = newstr(5);
	char * sa = newstr(5);
	char * offset = newstr(16);
	char * offset = newstr(16);
	char * inst_index = newstr(26);

	if(sscanf(input, "00000000000%5s%5s%5s000000", rt, rd, sa) == 3) return sll(toint(rt), toint(rd), toint(sa)); 
	if(sscanf(input, "00000000000%5s%5s%5s000010", rt, rd, sa) == 3) return srl(toint(rt), toint(rd), toint(sa));
	if(sscanf(input, "00000000000%5s%5s%5s000011", rt, rd, sa) == 3) return sra(toint(rt), toint(rd), toint(sa));
	if(sscanf(input, "000000%5s%5s%5s00000000100", rs, rt, rd) == 3) return sllv(toint(rs), toint(rt), toint(rd)); 
	if(sscanf(input, "000000%5s%5s%5s00000000110", rs, rt, rd) == 3) return srlv(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000000111", rs, rt, rd) == 3) return srav(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s000000000000000001000", rs) == 1) return jr(toint(rs));
	if(sscanf(input, "000000%5s00000%5s00000001001", rs, rd) == 2) return jalr(toint(rs), toint(rd)); 
	if(sscanf(input, "000000%5s%5s%5s00000100000", rs, rt, rd) == 3) return add(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100001", rs, rt, rd) == 3) return addu(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100010", rs, rt, rd) == 3) return sub(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100011", rs, rt, rd) == 3) return subu(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100100", rs, rt, rd) == 3) return and(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100101", rs, rt, rd) == 3) return or(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100110", rs, rt, rd) == 3) return xor(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000100111", rs, rt, rd) == 3) return nor(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000101010", rs, rt, rd) == 3) return slt(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000000%5s%5s%5s00000101011", rs, rt, rd) == 3) return sltu(toint(rs), toint(rt), toint(rd));
	if(sscanf(input, "000010%26s", inst_index) == 1) return j(toint(inst_index)); 
	if(sscanf(input, "000011%26s", inst_index) == 1) return jal(toint(inst_index)); 
	if(sscanf(input, "000100%5s%5s%16s", rs, rt, offset) == 3) return beq(toint(rs), toint(rt), toint(offset)); 
	if(sscanf(input, "000101%5s%5s%16s", rs, rt, offset) == 3) return bne(toint(rs), toint(rt), toint(offset)); 
	if(sscanf(input, "000110%5s00000%16s", rs, offset) == 2) return blez(toint(rs), toint(offset)); 
	if(sscanf(input, "000111%5s00000%16s", rs, offset) == 2) return bgtz(toint(rs), toint(offset)); 
	if(sscanf(input, "001000%5s%5s%16s", rs, rt, imm) == 3) return addi(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "001001%5s%5s%16s", rs, rt, imm) == 3) return addiu(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "001010%5s%5s%16s", rs, rt, imm) == 3) return slti(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "001011%5s%5s%16s", rs, rt, imm) == 3) return sltiu(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "001100%5s%5s%16s", rs, rt, imm) == 3) return andi(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "001101%5s%5s%16s", rs, rt, imm) == 3) return ori(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "001110%5s%5s%16s", rs, rt, imm) == 3) return xori(toint(rs), toint(rt), toint(imm));
	if(sscanf(input, "00111100000%5s%16s",  rt, imm) == 2) return lui(toint(rt), toint(imm)); 
	if(sscanf(input, "100000%5s%5s%16s", base, rt, offset) == 3) return lb(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "100001%5s%5s%16s", base, rt, offset) == 3) return lh(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "100010%5s%5s%16s", base, rt, offset) == 3) return lwl(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "100011%5s%5s%16s", base, rt, offset) == 3) return lw(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "100100%5s%5s%16s", base, rt, offset) == 3) return lbu(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "100101%5s%5s%16s", base, rt, offset) == 3) return lhu(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "100110%5s%5s%16s", base, rt, offset) == 3) return lwr(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "101000%5s%5s%16s", base, rt, offset) == 3) return sb(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "101001%5s%5s%16s", base, rt, offset) == 3) return sh(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "101010%5s%5s%16s", base, rt, offset) == 3) return sw(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "101011%5s%5s%16s", base, rt, offset) == 3) return swl(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "101110%5s%5s%16s", base, rt, offset) == 3) return swr(toint(base), toint(rt), toint(offset));
	if(sscanf(input, "000001%5s00001%16s", rs, offset) == 2) return bgez(toinst(rs), toint(offset));
	if(sscanf(input, "000001%5s10001%16s", rs, offset) == 2) return bgezal(toinst(rs), toint(offset));
	if(sscanf(input, "000001%5s00000%16s", rs, offset) == 2) return bltz(toinst(rs), toint(offset));
	if(sscanf(input, "000001%5s10000%16s", rs, offset) == 2) return bltzal(toinst(rs), toint(offset));

	printf("%s\n", output);
	return 0; 
}
