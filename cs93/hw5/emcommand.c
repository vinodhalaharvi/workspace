#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "emcommand.h"
#include "simpleoutput.h"
#include <curses.h>

char *regmap[32] =  {
	"$zero",
	"$at",
	"$v0",
	"$v1",
	"$a0",
	"$a1",
	"$a2",
	"$a3",
	"$t0",
	"$t1",
	"$t2",
	"$t3",
	"$t4",
	"$t5",
	"$t6",
	"$t7",
	"$s0",
	"$s1",
	"$s2",
	"$s3",
	"$s4",
	"$s5",
	"$s6",
	"$s7",
	"$t8",
	"$t9",
	"$k0",
	"$k1",
	"$gp",
	"$sp",
	"$fp",
	"$ra"
}; 


typedef struct _location {
	int x, y; 
} location;

location command = {.x = 20, .y = 0}; 

unsigned get(int num, int start, int end){
	unsigned int res = 0; 
	for (int i = end; i <= start; i++) {
		res |= (num & ( 1 << i )); 
	}
	return (res >> end); 
}

int registers[32]; 
unsigned short memory[MEMORY_MAX]; 
unsigned int pc; 
unsigned int ir; 

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}


void refresh_state(){
	WINDOW * window;
	if ((window = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing curses.\n");
		exit(EXIT_FAILURE);
	}
	char * printstr = newstr(30);
	int j = 0; 
	int k = 0;
	int p = 0; 
	if ( pc == 0 ) 
		p = pc; 
	else
		p = pc - 4; 
	for (int i = p; i < p+16; i++) {
		if ( i == pc)
			sprintf(printstr, " -> 0x%04X = 0x%08X", i, memory[i]);
		else 
			sprintf(printstr, "    0x%04X = 0x%08X", i, memory[i]);
		mvaddstr(0 + k++, 0 + j, printstr); 
	}
	j += 16; 
	for (int i = 0; i < 32; i++) {
		sprintf(printstr, "$%2d = 0x%08X", i, registers[i]);
		if ( i % 16 == 0) {
			k = 0; 
			j += 24; 
		}
		mvaddstr(0 + k++, 0 + j, printstr); 
	}
	sprintf(printstr, "$%s = 0x%08X", "PC", pc);
	mvaddstr(0 + k++, 0 + j, printstr); 
	sprintf(printstr, "$%s = 0x%08X", "IR", ir);
	mvaddstr(0 + k++, 0 + j, printstr); 
	free(printstr); 
	refresh();
}

void print_output(const char *str){
	assert (command.x > 0 ) ; 
	assert (command.y >= 0 ) ; 
	mvaddstr(command.x, command.y, str); 
}

char * getBits1(int num, unsigned int SIZE) { 
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

char * getBits(int num, unsigned int SIZE) { 
	char * bits = (char * ) malloc(SIZE+2);
	memset(bits, '\0', SIZE+2); 
	memset(bits, 'x', SIZE+1); 
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

unsigned int regint(char * bits){
	assert(strlen(bits) == 5); 
	return (int) strtol(bits, NULL,  2); 
}

unsigned int immint(char * bits){
	assert(strlen(bits) == 16); 
	return (int) strtol(bits, NULL,  2); 
}

unsigned int offsetint(char * bits){
	assert(strlen(bits) == 16); 
	return (int) strtol(bits, NULL,  2); 
}

unsigned int instint(char * bits){
	assert(strlen(bits) == 26); 
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
		return sll(regint(rt), regint(rd), regint(sa)); 
	if(sscanf(inst, "00000000000%5s%5s%5s000010%1s", rt, rd, sa, ig) ==4)
		return srl(regint(rt), regint(rd), regint(sa));
	if(sscanf(inst, "00000000000%5s%5s%5s000011%1s", rt, rd, sa, ig) ==4)
		return sra(regint(rt), regint(rd), regint(sa));
	if(sscanf(inst, "000000%5s%5s%5s00000000100%1s", rs, rt, rd, ig) ==4)
		return sllv(regint(rs), regint(rt), regint(rd)); 
	if(sscanf(inst, "000000%5s%5s%5s00000000110%1s", rs, rt, rd, ig) ==4)
		return srlv(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000000111%1s", rs, rt, rd, ig) ==4)
		return srav(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s000000000000000001000%1s", rs, ig) ==2)
		return jr(regint(rs));
	if(sscanf(inst, "000000%5s00000%5s00000001001%1s", rs, rd, ig) ==3)
		return jalr(regint(rs), regint(rd)); 
	if(sscanf(inst, "000000%5s%5s%5s00000100000%1s", rs, rt, rd, ig) ==4)
		return add(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100001%1s", rs, rt, rd, ig) ==4)
		return addu(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100010%1s", rs, rt, rd, ig) ==4)
		return sub(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100011%1s", rs, rt, rd, ig) ==4)
		return subu(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100100%1s", rs, rt, rd, ig) ==4)
		return and(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100101%1s", rs, rt, rd, ig) ==4)
		return or(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100110%1s", rs, rt, rd, ig) ==4)
		return xor(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100111%1s", rs, rt, rd, ig) ==4)
		return nor(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000101010%1s", rs, rt, rd, ig) ==4)
		return slt(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000101011%1s", rs, rt, rd, ig) ==4)
		return sltu(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000010%26s%1s", inst_index, ig) ==2)
		return j(instint(inst_index)); 
	if(sscanf(inst, "000011%26s%1s", inst_index, ig) ==2)
		return jal(instint(inst_index)); 
	if(sscanf(inst, "000100%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
		return beq(regint(rs), regint(rt), offsetint(offset)); 
	if(sscanf(inst, "000101%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
		return bne(regint(rs), regint(rt), offsetint(offset)); 
	if(sscanf(inst, "000110%5s00000%16s%1s", rs, offset, ig) ==3)
		return blez(regint(rs), offsetint(offset)); 
	if(sscanf(inst, "000111%5s00000%16s%1s", rs, offset, ig) ==3)
		return bgtz(regint(rs), offsetint(offset)); 
	if(sscanf(inst, "001000%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return addi(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001001%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return addiu(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001010%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return slti(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001011%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return sltiu(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001100%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return andi(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001101%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return ori(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001110%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return xori(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "00111100000%5s%16s%1s",  rt, imm, ig) ==3)
		return lui(regint(rt), immint(imm)); 
	if(sscanf(inst, "100000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lb(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100001%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lh(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lwl(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lw(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100100%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lbu(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100101%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lhu(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100110%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lwr(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "101000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sb(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "101001%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sh(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "101010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sw(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "101011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return swl(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "101110%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return swr(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "000001%5s00001%16s%1s", rs, offset, ig) ==3)
		return bgez(regint(rs), offsetint(offset));
	if(sscanf(inst, "000001%5s10001%16s%1s", rs, offset, ig) ==3)
		return bgezal(regint(rs), offsetint(offset));
	if(sscanf(inst, "000001%5s00000%16s%1s", rs, offset, ig) ==3)
		return bltz(regint(rs), offsetint(offset));
	if(sscanf(inst, "000001%5s10000%16s%1s", rs, offset, ig) ==3)
		return bltzal(regint(rs), offsetint(offset));
	assert(1 == 0); 
	return 0; 
}

int sll(int rt, int rd, int sa){
	pr_reg_reg_sa("sll", rt, rd, sa); 
	return 0; //deleteme 
	registers[rd] = registers[rt] << sa; 
	return 0; 
}

int srl(int rt, int rd, int sa){
	pr_reg_reg_sa("srl", rt, rd, sa); 
	return 0; //deleteme 
	registers[rd] = (unsigned int) registers[rt] >> sa; 
	return 0;
}


int sra(int rt, int rd, int sa){
	pr_reg_reg_sa("srl", rt, rd, sa); 
	return 0; //deleteme 
	registers[rd] = registers[rt] >> sa; 
	return 0;
}

int sllv(int rs, int rt, int rd){
	pr_reg_reg_reg("sllv", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rt] << registers[rs]; 
	return 0;
}

int srlv(int rs, int rt, int rd){
	pr_reg_reg_reg("srlv", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = (unsigned int) registers[rt] >> registers[rs]; 
	return 0;
}

int srav(int rs, int rt, int rd){
	pr_reg_reg_reg("srav", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rt] >> registers[rs]; 
	return 0;
}

int jr(int rs){
	pc = registers[rs]; 
	return 0;
}
int jalr(int rs, int rd){
	return 0; //deleteme 
	registers[rd] = pc + 4; 
	pc = registers[rs]; 
	return 0;
}

int add(int rs, int rt, int rd){
	pr_reg_reg_reg("add", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] + registers[rt];
	return 0;
}

int addu(int rs, int rt, int rd){
	pr_reg_reg_reg("addu", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] + registers[rt];
	return 0;
}

int sub(int rs, int rt, int rd){
	pr_reg_reg_reg("sub", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] - registers[rt];
	return 0;
}

int subu(int rs, int rt, int rd){
	pr_reg_reg_reg("subu", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] - registers[rt];
	return 0;
}

int and(int rs, int rt, int rd){
	pr_reg_reg_reg("and", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] & registers[rt]; 
	return 0;
}

int or(int rs, int rt, int rd){
	pr_reg_reg_reg("or", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] | registers[rt]; 
	return 0;
}

int xor(int rs, int rt, int rd){
	pr_reg_reg_reg("xor", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] ^ registers[rt]; 
	return 0;
}

int nor(int rs, int rt, int rd){
	pr_reg_reg_reg("nor", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = ~(registers[rs] | registers[rt]); 
	return 0;
}

int slt(int rs, int rt, int rd){
	pr_reg_reg_reg("slt", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = registers[rs] < registers[rt]; 
	return 0;
}

int sltu(int rs, int rt, int rd){
	pr_reg_reg_reg("sltu", rs, rt, rd); 
	return 0; //deleteme 
	registers[rd] = (unsigned int ) registers[rs] < (unsigned int ) registers[rt]; 
	return 0;
}

int j(int inst_index){
	pc = (get(pc, 31, 28) << 28) | (inst_index << 2);
	return 0;
}

int jal(int inst_index){
	pr_base_inst_index("jal", inst_index); 
	return 0; //deleteme 
	registers[31] = pc + 4; 
	pc = (get(pc, 31, 28) << 28) | (inst_index << 2);
	return 0;
}

int beq(int rs, int rt, int offset){
	pr_reg_reg_offset("beq", rs, rt, offset); 
	if (registers[rs] == registers[rt])
		pc = pc + (offset << 2);
	return 0;
}

int bne(int rs, int rt, int offset){
	pr_reg_reg_offset("bne", rs, rt, offset); 
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
	pr_reg_reg_imm("addiu", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] =  registers[rs] + imm; 
	return 0;
}

int slti(int rs, int rt, int imm){
	pr_reg_reg_imm("slti", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] = registers[rs] < imm; 
	return 0;
}

int sltiu(int rs, int rt, int imm){
	pr_reg_reg_imm("sltiu", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] = (unsigned int ) registers[rs] < (unsigned int )imm; 
	return 0;

}
int andi(int rs, int rt, int imm){
	pr_reg_reg_imm("andi", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] = registers[rs] & imm; 
	return 0;
}


int xori(int rs, int rt, int imm){
	pr_reg_reg_imm("xori", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] = registers[rs] ^ imm; 
	return 0;
}

int addi(int rs, int rt, int imm){
	pr_reg_reg_imm("addi", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] = registers[rs] +  imm; 
	return 0;
}


int ori(int rs, int rt, int imm){
	pr_reg_reg_imm("ori", rs, rt, imm);
	return 0; //deleteme 
	registers[rt] = registers[rs] |  imm; 
	return 0;
}

int lui(int rt, int imm){
	pr_reg_imm("lui", rt, imm); 
	return 0; //deleteme 
	registers[rt] = (imm << 16) & 0xFF; 
	return 0;
}

int lb(int base , int rt, int offset){
	pr_base_rt_offset("lb", base, rt, offset); 
	lbu(base, rt, offset); 
	return 0;
}

int lh(int base , int rt, int offset){
	pr_base_rt_offset("lhu", base, rt, offset); 
	lhu(base, rt, offset); 
	return 0;
}

int lwl(int base , int rt, int offset){
	assert(0 == 1); 
	return 0;
}

int lw(int base , int rt, int offset){
	pr_base_rt_offset("lw", base, rt, offset); 
	assert((base + offset) % 4 == 0); 
	return 0; //deleteme 
	registers[rt] = ((memory[base + offset + 2]) << 16) 
			| (memory[base + offset]); 
	return 0;
}

int lhu(int base , int rt, int offset){
	pr_base_rt_offset("lhu", base, rt, offset); 
	assert((base + offset) % 4 == 0); 
	return 0; //deleteme 
	registers[rt] = memory[base + offset]; 
	return 0;
}


int lbu(int base , int rt, int offset){
	pr_base_rt_offset("lbu", base, rt, offset); 
	assert((base + offset) % 4 == 0); 
	return 0; //deleteme 
	registers[rt] = memory[base + offset] & 0xFF; 
	return 0;
}

int lwr(int base , int rt, int offset){
	assert(0 == 1); 
	return 0;
}

int sb(int base , int rt, int offset){
	pr_base_rt_offset("sb", base, rt, offset); 
	assert((base + offset) % 4 == 0); 
	memory[base + offset] = registers[rt] & 0xFF; 
	return 0;
}

int sh(int base , int rt, int offset){
	pr_base_rt_offset("sh", base, rt, offset); 
	assert((base + offset) % 4 == 0); 
	memory[base + offset] = registers[rt] & 0xFFFF; 
	return 0;
}

int sw(int base , int rt, int offset){
	pr_base_rt_offset("sw", base, rt, offset); 
	assert((base + offset) % 2 == 0); 
	return 0; 
	memory[base + offset + 2] = (registers[rt] >> 16) & 0xFFFF; 
	memory[base + offset] = registers[rt] & 0xFFFF; 
	return 0;
}

int swl(int base , int rt, int offset){
	assert(0 == 1); 
	return 0;
}

int swr(int base , int rt, int offset){
	assert(0 == 1); 
	return 0;
}

int bgez(int rs, int offset){
	assert(0 == 1); 
	if (registers[rs] >= 0)
		pc = pc + (offset << 2);
	return 0;
}

int bgezal(int rs, int offset){
	assert(0 == 1); 
	return 0;
}

int bltz(int rs, int offset){
	if (registers[rs] < 0)
		pc = pc + (offset << 2);
	return 0;
}

int bltzal(int rs, int offset){
	assert(0 == 1); 
	return 0;
}

