#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "emcommand.h"
#include "simpleoutput.h"
#include <curses.h>

int sp = STACK_BASE; 
int hp = HEAP_BASE; 

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
location loglocation = {.x = 21, .y = 0}; 

unsigned get(int num, int start, int end){
	unsigned int res = 0; 
	for (int i = end; i <= start; i++) {
		res |= (num & ( 1 << i )); 
	}
	return (res >> end); 
}

int registers[32]; 
unsigned short memory[MIF_FILE_SIZE]; 
unsigned int pc; 
unsigned int ir; 

void init_registers(){
	for (int i = 0; i < 31; i++) {
		registers[i] = 0;
	}
	registers[29] = sp;
}

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
			//sprintf(printstr, " -> 0x%04X = 0x%08X", i, memory[i]); 
			sprintf(printstr, " -> %d = %d", i, memory[i]);
		else 
			//sprintf(printstr, "    0x%04X = 0x%08X", i, memory[i]);
			sprintf(printstr, "    %d = %d", i, memory[i]);
		mvaddstr(0 + k, 0 + j, "       "); 
		mvaddstr(0 + k++, 0 + j, printstr); 
	}
	j += 12; 
	for (int i = 0; i < 32; i++) {
		sprintf(printstr, "$%2d (%s) = %d", i, regmap[i], registers[i]);
		if ( i % 16 == 0) {
			k = 0; 
			j += 28; 
		}
		mvaddstr(0 + k, 0 + j, "                    "); 
		mvaddstr(0 + k++, 0 + j, printstr); 
	}
	sprintf(printstr, "$%s = %d", "PC", pc);
	mvaddstr(0 + k, 0 + j, "                    "); 
	mvaddstr(0 + k++, 0 + j, printstr); 
	sprintf(printstr, "$%s = %d", "IR", ir);
	mvaddstr(0 + k, 0 + j, "                    "); 
	mvaddstr(0 + k++, 0 + j, printstr); 

	//TODO test this 
	char * stackStr = newstr(31); 
	for (int i = 0; i < 30; i++) {
		*stackStr++ = (char) memory[0x5500+i];
	}
	*stackStr = '\0';
	mvaddstr(21, 0, stackStr); 

	free(printstr); 
	refresh();
}

void print_output(const char *str){
	assert (command.x > 0 ) ; 
	assert (command.y >= 0 ) ; 
	mvaddstr(command.x, command.y, "                                             "); 
	mvaddstr(command.x, command.y, str); 
	refresh();
}

void logstring(const char *str){
	assert (loglocation.x > 0 ) ; 
	assert (loglocation.y >= 0 ) ; 
	mvaddstr(loglocation.x, loglocation.y, "                                             "); 
	mvaddstr(loglocation.x, loglocation.y, str); 
	refresh();
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
	int res =  (int) strtol(bits, NULL,  2); 
	assert( 0 <= res &&  res <= 31); 
	return res; 
}

unsigned int immint(char * bits){
	assert(strlen(bits) == 16); 
	return (short) strtol(bits, NULL,  2); 
}

unsigned int offsetint(char * bits){
	assert(strlen(bits) == 16); 
	return (short) strtol(bits, NULL,  2); 
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
	if(sscanf(inst, "000000%5s%5s%5s00000100000%1s", rs, rt, rd, ig) ==4)
		return add(regint(rs), regint(rt), regint(rd));
	if(sscanf(inst, "000000%5s%5s%5s00000100010%1s", rs, rt, rd, ig) ==4)
		return sub(regint(rs), regint(rt), regint(rd));
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
	if(sscanf(inst, "000010%26s%1s", inst_index, ig) ==2)
		return j(instint(inst_index)); 
	if(sscanf(inst, "000011%26s%1s", inst_index, ig) ==2)
		return jal(instint(inst_index)); 
	if(sscanf(inst, "000100%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
		return beq(regint(rs), regint(rt), offsetint(offset)); 
	if(sscanf(inst, "000101%5s%5s%16s%1s", rs, rt, offset, ig) ==4)
		return bne(regint(rs), regint(rt), offsetint(offset)); 
	if(sscanf(inst, "001000%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return addi(regint(rs), regint(rt), immint(imm));
	if(sscanf(inst, "001010%5s%5s%16s%1s", rs, rt, imm, ig) ==4)
		return slti(regint(rs), regint(rt), immint(imm));
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
	if(sscanf(inst, "101000%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sb(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "100011%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return lw(regint(base), regint(rt), offsetint(offset));
	if(sscanf(inst, "101010%5s%5s%16s%1s", base, rt, offset, ig) ==4)
		return sw(regint(base), regint(rt), offsetint(offset));
	assert(1 == 0); 
	return 0; 
}

int sll(int rt, int rd, int sa){
	pr_rt_rd_sa("sll", rt, rd, sa); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rt] << sa; 
	return 0; 
}

int srl(int rt, int rd, int sa){
	pr_rt_rd_sa("srl", rt, rd, sa); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = (unsigned int) registers[rt] >> sa; 
	return 0;
}


int sra(int rt, int rd, int sa){
	pr_rt_rd_sa("srl", rt, rd, sa); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rt] >> sa; 
	return 0;
}

int sllv(int rs, int rt, int rd){
	pr_rs_rt_rd("sllv", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rt] << registers[rs]; 
	return 0;
}

int srlv(int rs, int rt, int rd){
	pr_rs_rt_rd("srlv", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = (unsigned int) registers[rt] >> registers[rs]; 
	return 0;
}

int srav(int rs, int rt, int rd){
	pr_rs_rt_rd("srav", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rt] >> registers[rs]; 
	return 0;
}

int add(int rs, int rt, int rd){
	pr_rs_rt_rd("add", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rs] + registers[rt];
	return 0;
}

int sub(int rs, int rt, int rd){
	pr_rs_rt_rd("sub", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rs] - registers[rt];
	return 0;
}

int and(int rs, int rt, int rd){
	pr_rs_rt_rd("and", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rs] & registers[rt]; 
	return 0;
}

int or(int rs, int rt, int rd){
	pr_rs_rt_rd("or", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rs] | registers[rt]; 
	return 0;
}

int xor(int rs, int rt, int rd){
	pr_rs_rt_rd("xor", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rs] ^ registers[rt]; 
	return 0;
}

int nor(int rs, int rt, int rd){
	pr_rs_rt_rd("nor", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = ~(registers[rs] | registers[rt]); 
	return 0;
}

int slt(int rs, int rt, int rd){
	pr_rs_rt_rd("slt", rs, rt, rd); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rd] = registers[rs] < registers[rt]; 
	return 0;
}


int jr(int rs){
	pr_rs("jr", rs); 
#ifdef DONTEMULATE
	return 0;
#endif
	pc = registers[rs]; 
	return 0;
}

int j(int inst_index){
	pr_inst_index("j", inst_index); 
#ifdef DONTEMULATE
	return 0;
#endif
	//pc = (get(pc, 31, 28) << 28) | (inst_index << 2);
	pc = inst_index;  // not accurate. 
	return 0;
}

int jal(int inst_index){
	pr_inst_index("jal", inst_index); 
#ifdef DONTEMULATE
	return 0;
#endif
	//registers[31] = pc + 4; 
	registers[31] = pc; 
	//pc = (get(pc, 31, 28) << 28) | (inst_index << 2); 
	pc = inst_index;  // not accurate. 
	return 0;
}

int beq(int rs, int rt, int offset){
	pr_rs_rt_offset("beq", rs, rt, offset); 
#ifdef DONTEMULATE
	return 0;
#endif
	if (registers[rs] == registers[rt])
		//pc = pc + (offset << 2); 
		pc = offset;  // not accurate.
	return 0;
}

int bne(int rs, int rt, int offset){
	pr_rs_rt_offset("bne", rs, rt, offset); 
#ifdef DONTEMULATE
	return 0;
#endif
	if (registers[rs] != registers[rt])
		//pc = pc + (offset << 2); 
		pc = offset;  // not accurate.
	return 0;
}


int slti(int rs, int rt, int imm){
	pr_rs_rt_imm("slti", rs, rt, imm);
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rt] = registers[rs] < imm; 
	return 0;
}

int andi(int rs, int rt, int imm){
	pr_rs_rt_imm("andi", rs, rt, imm);
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rt] = registers[rs] & imm; 
	return 0;
}


int xori(int rs, int rt, int imm){
	pr_rs_rt_imm("xori", rs, rt, imm);
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rt] = registers[rs] ^ imm; 
	return 0;
}

int addi(int rs, int rt, int imm){
	pr_rs_rt_imm("addi", rs, rt, imm);
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rt] = registers[rs] +  imm; 
	return 0;
}


int ori(int rs, int rt, int imm){
	pr_rs_rt_imm("ori", rs, rt, imm);
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rt] = registers[rs] |  imm; 
	return 0;
}

int lui(int rt, int imm){
	pr_rt_imm("lui", rt, imm); 
#ifdef DONTEMULATE
	return 0;
#endif
	registers[rt] = (imm << 16) & 0xFF; 
	return 0;
}

int lb(int base , int rt, int offset){
	pr_base_rt_offset("lb", base, rt, offset); 
#ifdef DONTEMULATE
	return 0;
#endif
	//assert((registers[base] + offset) % 2 == 0); 
	//registers[rt] = memory[registers[base] + offset] & 0xFF; 
	registers[rt] =  (char) memory[registers[base] + offset]; 
	return 0;
}


int sb(int base , int rt, int offset){
	pr_base_rt_offset("sb", base, rt, offset); 
#ifdef DONTEMULATE
	return 0;
#endif
	//assert((base + offset) % 4 == 0); 
	//memory[registers[base] + offset] = registers[rt] & 0xFF; 
	memory[registers[base] + offset] = (char) registers[rt]; 
	return 0;
}

int lw(int base , int rt, int offset){
	pr_base_rt_offset("lw", base, rt, offset); 
#ifdef DONTEMULATE
	return 0;
#endif
	//assert((registers[base] + offset) % 4 == 0); 
	registers[rt] = ((memory[registers[base] + offset + 2]) << 16) 
			| (memory[registers[base] + offset]); 
	return 0;
}


int sw(int base , int rt, int offset){
	pr_base_rt_offset("sw", base, rt, offset); 
#ifdef DONTEMULATE
	return 0;
#endif
	//assert((registers[base] + offset) % 2 == 0); 
	memory[registers[base] + offset + 2] = (registers[rt] >> 16) & 0xFFFF; 
	memory[registers[base] + offset] = registers[rt] & 0xFFFF; 
	return 0;
}


char * getheapStr(){
	int i = 21760; 
	char * printStr = newstr(100); 
	char * res = printStr; 
	while(memory[i]){
		*printStr++ = memory[i++];
	}
	*printStr++ = ' ';
	i = 21764; 
	while(memory[i]){
		*printStr++ = memory[i++];
	}
	*printStr++ = ' ';
	//i = 21768; 
	for (int i = 21768; i < 21768 + 5; i++) {
		*printStr++ = memory[i++];
	}
	/*while(memory[i]){
		*printStr++ = memory[i++];
	}*/
	return res; 
}

