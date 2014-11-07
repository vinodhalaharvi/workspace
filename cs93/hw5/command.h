extern int registers[32];
extern int pc;
extern int ir; 

#define MEMORY_MAX 32627
extern int memory[MEMORY_MAX];

int doinst(char * inst);
int sll(int rt, int rd, int sa);
int srl(int rt, int rd, int sa);
int sra(int rt, int rd, int sa);
int sllv(int rs, int rt, int rd);
int srlv(int rs, int rt, int rd);
int srav(int rs, int rt, int rd);
int jr(int rs);
int jalr(int rs, int rd);
int add(int rs, int rt, int rd);
int addu(int rs, int rt, int rd);
int sub(int rs, int rt, int rd);
int subu(int rs, int rt, int rd);
int and(int rs, int rt, int rd);
int or(int rs, int rt, int rd);
int xor(int rs, int rt, int rd);
int nor(int rs, int rt, int rd);
int slt(int rs, int rt, int rd);
int sltu(int rs, int rt, int rd);
int j(int inst_idnex);
int jal(int inst_idnex);
int beq(int rs, int rt, int offset);
int bne(int rs, int rt, int offset);
int blez(int rs, int offset);
int bgtz(int rs, int offset);
int addiu(int rs, int rt, int imm);
int slti(int rs, int rt, int imm);
int sltiu(int rs, int rt, int imm);
int andi(int rs, int rt, int imm);
int xori(int rs, int rt, int imm);
int addi(int rs, int rt, int imm);
int ori(int rs, int rt, int imm);
int lui(int rt, int imm);
int lb(int base , int rt, int offset);
int lh(int base , int rt, int offset);
int lwl(int base , int rt, int offset);
int lw(int base , int rt, int offset);
int lbu(int base , int rt, int offset);
int lhu(int base , int rt, int offset);
int lwr(int base , int rt, int offset);
int sb(int base , int rt, int offset);
int sh(int base , int rt, int offset);
int sw(int base , int rt, int offset);
int swl(int base , int rt, int offset);
int swr(int base , int rt, int offset);
int bgez(int rs, int offset);
int bgezal(int rs, int offset);
int bltz(int rs, int offset);
int bltzal(int rs, int offset);
void refresh_registers();
char * newstr(int len);
void print_output(char *str);
char * getBits(int num, unsigned int SIZE); 
unsigned int hextoint(char * hex);

