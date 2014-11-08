#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "command.h"
#include <curses.h>


unsigned get(int num, int start, int end){
	unsigned int res = 0; 
	for (int i = end; i <= start; i++) {
		res |= (num & ( 1 << i )); 
	}
	return (res >> end); 
}

int registers[32]; 
unsigned char memory[MEMORY_MAX]; 
unsigned int pc; 
unsigned int ir; 

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}


void refresh_registers(){
	WINDOW * window;
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	char * regstr = newstr(30);
	int j = 0; 
	int k = 13; 
	for (int i = 0; i < 32; i++) {
		sprintf(regstr, "$%d = 0x%x", i, registers[i]);
		if ( i % 6 == 0) {
			k = 0; 
			j += 14; 
		}
		mvaddstr(0 + k++, 0 + j, regstr); 
	}
	sprintf(regstr, "$%s = 0x%x", "PC", pc);
	mvaddstr(0 + k++, 0 + j, regstr); 
	free(regstr); 
	refresh();
}

void print_output(char *str){
	mvaddstr(0 + 20, 10, str); 
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

unsigned int toint(char * bits){
	assert(strlen(bits) == 5); 
	return (int) strtol(bits, NULL,  2); 
}


int doinst(char * inst){
	char * rs = newstr(10); 
	char * rt = newstr(10); 
	char * rd = newstr(10); 
	char * ig = newstr(2); 
	char * base = newstr(5);
	char * sa = newstr(5);
	char * offset = newstr(16);
	char * imm = newstr(16);
	char * inst_index = newstr(26);
	assert(strlen(inst) == 33); 
	if(sscanf(inst, "00000000000%5s%5s%5s000000%1s", rt, rd, sa, ig) ==4)
		return sll(toint(rt), toint(rd), toint(sa)); 
	if(sscanf(inst, "00000000000%5s%5s%5s000010%1s", rt, rd, sa, ig) ==4)
		return srl(toint(rt), toint(rd), toint(sa));
	if(sscanf(inst, "00000000000%5s%5s%5s000011%1s", rt, rd, sa, ig) ==4)
		return sra(toint(rt), toint(rd), toint(sa));
	if(sscanf(inst, "000000%5s%5s%5s00000000100%1s", rs, rt, rd, ig) ==4)
		return sllv(toint(rs), toint(rt), toint(rd)); 
	if(sscanf(inst, "000000%5s%5s%5s00000000110%1s", rs, rt, rd, ig) ==4)
		return srlv(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000000111%1s", rs, rt, rd, ig) ==4)
		return srav(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s000000000000000001000%1s", rs, ig) ==2)
		return jr(toint(rs));
	if(sscanf(inst, "000000%5s00000%5s00000001001%1s", rs, rd, ig) ==3)
		return jalr(toint(rs), toint(rd)); 
	if(sscanf(inst, "000000%5s%5s%5s00000100000%1s", rs, rt, rd, ig) ==4)
		return add(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100001%1s", rs, rt, rd, ig) ==4)
		return addu(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100010%1s", rs, rt, rd, ig) ==4)
		return sub(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100011%1s", rs, rt, rd, ig) ==4)
		return subu(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100100%1s", rs, rt, rd, ig) ==4)
		return and(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100101%1s", rs, rt, rd, ig) ==4)
		return or(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100110%1s", rs, rt, rd, ig) ==4)
		return xor(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100111%1s", rs, rt, rd, ig) ==4)
		return nor(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000101010%1s", rs, rt, rd, ig) ==4)
		return slt(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000101011%1s", rs, rt, rd, ig) ==4)
		return sltu(toint(rs), toint(rt), toint(rd));
	if(sscanf(inst, "000010%26s%1s", inst_index, ig) ==2)
		return j(toint(inst_index)); 
	if(sscanf(inst, "000011%26s%1s", inst_index, ig) ==2)
		return jal(toint(inst_index)); 
	if(sscanf(inst, "000100%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
		return beq(toint(rs), toint(rt), toint(offset)); 
	if(sscanf(inst, "000101%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
		return bne(toint(rs), toint(rt), toint(offset)); 
	if(sscanf(inst, "000110%5s00000%16s%1s", rs, offset, ig) ==3)
		return blez(toint(rs), toint(offset)); 
	if(sscanf(inst, "000111%5s00000%16s%1s", rs, offset, ig) ==3)
		return bgtz(toint(rs), toint(offset)); 
	if(sscanf(inst, "001000%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return addi(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "001001%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return addiu(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "001010%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return slti(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "001011%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return sltiu(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "001100%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return andi(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "001101%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return ori(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "001110%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return xori(toint(rs), toint(rt), toint(imm));
	if(sscanf(inst, "00111100000%5s%16s%1s",  rt, imm, ig) ==3)
		return lui(toint(rt), toint(imm)); 
	if(sscanf(inst, "100000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lb(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "100001%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lh(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "100010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lwl(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "100011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lw(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "100100%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lbu(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "100101%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lhu(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "100110%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lwr(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "101000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sb(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "101001%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sh(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "101010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sw(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "101011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return swl(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "101110%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return swr(toint(base), toint(rt), toint(offset));
	if(sscanf(inst, "000001%5s00001%16s%1s", rs, offset, ig) ==3)
		return bgez(toint(rs), toint(offset));
	if(sscanf(inst, "000001%5s10001%16s%1s", rs, offset, ig) ==3)
		return bgezal(toint(rs), toint(offset));
	if(sscanf(inst, "000001%5s00000%16s%1s", rs, offset, ig) ==3)
		return bltz(toint(rs), toint(offset));
	if(sscanf(inst, "000001%5s10000%16s%1s", rs, offset, ig) ==3)
		return bltzal(toint(rs), toint(offset));
	return 0; 
}

int sll(int rt, int rd, int sa){
	//printf("%s\n", "sll");
	//rd <- rt << sa
	registers[rd] = registers[rt] << sa; 
	return 0; 
}

int srl(int rt, int rd, int sa){
	// rd <- rt >> sa
	registers[rd] = (unsigned int) registers[rt] >> sa; 
	//printf("%s\n", "srl");
	return 0;
}


int sra(int rt, int rd, int sa){
	registers[rd] = registers[rt] >> sa; 
	//printf("%s\n", "sra");
	return 0;
}

int sllv(int rs, int rt, int rd){
	registers[rd] = registers[rt] << registers[rs]; 
	//printf("%s\n", "sllv");
	return 0;
}

int srlv(int rs, int rt, int rd){
	//printf("%s\n", "srlv");
	registers[rd] = (unsigned int) registers[rt] >> registers[rs]; 
	return 0;
}

int srav(int rs, int rt, int rd){
	//printf("%s\n", "srav");
	registers[rd] = registers[rt] >> registers[rs]; 
	return 0;
}

int jr(int rs){
	//printf("%s\n", "jr");
	pc = registers[rs]; 
	return 0;
}
int jalr(int rs, int rd){
	//printf("%s\n", "jalr");
	registers[rd] = pc + 4; 
	pc = registers[rs]; 
	return 0;
}

int add(int rs, int rt, int rd){
	//printf("%s\n", "add");
	registers[rd] = registers[rs] + registers[rt];
	return 0;
}

int addu(int rs, int rt, int rd){
	registers[rd] = registers[rs] + registers[rt];
	//printf("%s\n", "addu");
	return 0;
}

int sub(int rs, int rt, int rd){
	registers[rd] = registers[rs] - registers[rt];
	//printf("%s\n", "sub");
	return 0;
}

int subu(int rs, int rt, int rd){
	//printf("%s\n", "subu");
	registers[rd] = registers[rs] - registers[rt];
	return 0;
}

int and(int rs, int rt, int rd){
	//printf("and\n");
	registers[rd] = registers[rs] & registers[rt]; 
	return 0;
}

int or(int rs, int rt, int rd){
	//printf("%s\n", "or");
	registers[rd] = registers[rs] | registers[rt]; 
	return 0;
}

int xor(int rs, int rt, int rd){
	//printf("%s\n", "xor");
	registers[rd] = registers[rs] ^ registers[rt]; 
	return 0;
}

int nor(int rs, int rt, int rd){
	//printf("%s\n", "nor");
	registers[rd] = ~(registers[rs] | registers[rt]); 
	return 0;
}

int slt(int rs, int rt, int rd){
	//printf("%s\n", "slt");
	registers[rd] = registers[rs] < registers[rt]; 
	return 0;
}

int sltu(int rs, int rt, int rd){
	//printf("%s\n", "sltu");
	registers[rd] = (unsigned int ) registers[rs] < (unsigned int ) registers[rt]; 
	return 0;
}

int j(int inst_index){
	pc = (get(pc, 31, 28) << 28) | (inst_index << 2);
	return 0;
}

int jal(int inst_index){
	registers[31] = pc + 4; 
	pc = (get(pc, 31, 28) << 28) | (inst_index << 2);
	return 0;
}

int beq(int rs, int rt, int offset){
	if (registers[rs] == registers[rt])
		pc = pc + (offset << 2);
	return 0;
}

int bne(int rs, int rt, int offset){
	if (registers[rs] != registers[rt])
		pc = pc + (offset << 2);
	return 0;
}


int blez(int rs, int offset){
	if (registers[rs] <= 0)
		pc = pc + (offset << 2);
	return 0;
}


int bgtz(int rs, int offset){
	if (registers[rs] >= 0)
		pc = pc + (offset << 2);
	return 0;

}

int addiu(int rs, int rt, int imm){
	registers[rt] =  registers[rs] + imm; 
	return 0;
}

int slti(int rs, int rt, int imm){
	registers[rt] = registers[rs] < imm; 
	return 0;
}

int sltiu(int rs, int rt, int imm){
	registers[rt] = (unsigned int ) registers[rs] < (unsigned int )imm; 
	return 0;

}
int andi(int rs, int rt, int imm){
	registers[rt] = registers[rs] & imm; 
	return 0;
}


int xori(int rs, int rt, int imm){
	registers[rt] = registers[rs] ^ imm; 
	return 0;
}

int addi(int rs, int rt, int imm){
	registers[rt] = registers[rs] +  imm; 
	return 0;
}


int ori(int rs, int rt, int imm){
	registers[rt] = registers[rs] |  imm; 
	return 0;
}

int lui(int rt, int imm){
	registers[rt] = (imm << 16) && 0xFF; 
	return 0;
}

int lb(int base , int rt, int offset){
	lbu(base, rt, offset); 
	return 0;
}

int lh(int base , int rt, int offset){
	lhu(base, rt, offset); 
	return 0;
}

int lwl(int base , int rt, int offset){
	//printf("%s\n", "lwl Not implemented yet.. ");
	assert(0 == 1); 
	return 0;
}

int lw(int base , int rt, int offset){
	assert((base + offset) % 4 == 0); 
	registers[rt] = (
			  ((memory[base + offset + 3]) << 24) 
			| ((memory[base + offset + 2]) << 16)
			| ((memory[base + offset + 1]) << 8)
			| (memory[base + offset])
		); 
	return 0;
}

int lhu(int base , int rt, int offset){
	assert((base + offset) % 4 == 0); 
	registers[rt] = ((memory[base + offset + 1]) << 8)
			|(memory[base + offset]); 
	return 0;
}


int lbu(int base , int rt, int offset){
	assert((base + offset) % 4 == 0); 
	registers[rt] = memory[base + offset]; 
	return 0;
}

int lwr(int base , int rt, int offset){
	//printf("%s\n", "lwl Not implemented yet.. ");
	assert(0 == 1); 
	return 0;
}

int sb(int base , int rt, int offset){
	assert((base + offset) % 4 == 0); 
	memory[base + offset] = registers[rt] & 0xFF; 
	return 0;
}

int sh(int base , int rt, int offset){
	assert((base + offset) % 4 == 0); 
	memory[base + offset + 1] = (registers[rt] >> 8) & 0xFF; 
	memory[base + offset] = registers[rt] & 0xFF; 
	return 0;
}

int sw(int base , int rt, int offset){
	assert((base + offset) % 4 == 0); 
	memory[base + offset + 3] = (registers[rt] >> 24) & 0xFF; 
	memory[base + offset + 2] = (registers[rt] >> 16) & 0xFF; 
	memory[base + offset + 1] = (registers[rt] >> 8) & 0xFF; 
	memory[base + offset] = registers[rt] & 0xFF; 
	return 0;
}

int swl(int base , int rt, int offset){
	//printf("%s\n", "lwl Not implemented yet.. ");
	assert(0 == 1); 
	return 0;
}

int swr(int base , int rt, int offset){
	//printf("%s\n", "lwl Not implemented yet.. ");
	assert(0 == 1); 
	return 0;
}

int bgez(int rs, int offset){
	if (registers[rs] >= 0)
		pc = pc + (offset << 2);
	return 0;
}

int bgezal(int rs, int offset){
	//printf("%s\n", "bgezal Not implemented yet.. ");
	assert(0 == 1); 
	return 0;
}

int bltz(int rs, int offset){
	if (registers[rs] < 0)
		pc = pc + (offset << 2);
	return 0;
}

int bltzal(int rs, int offset){
	//printf("%s\n", "bltzal Not implemented yet.. ");
	assert(0 == 1); 
	return 0;

}
