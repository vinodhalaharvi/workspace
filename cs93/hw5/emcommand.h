#define MIF_FILE_SIZE 65288
extern int registers[32];
extern unsigned int  pc;
extern unsigned int  ir; 
extern unsigned short  memory[MIF_FILE_SIZE];
extern char currInst[100]; 

#define REG_IOCONTROL 0x00FF00
#define REG_IOBUFFER_1 0x00FF04
#define REG_IOBUFFER_2 0x00FF08
#define STACK_BASE   (REG_IOCONTROL - 0x00A000)
#define HEAP_BASE    (STACK_BASE - 0x000A00)

extern int sp; 
extern int hp; 

int doinst(char * inst);
int sll(int rt, int rd, int sa);
int srl(int rt, int rd, int sa);
int sra(int rt, int rd, int sa);
int sllv(int rs, int rt, int rd);
int srlv(int rs, int rt, int rd);
int srav(int rs, int rt, int rd);
int jr(int rs);
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
void refresh_state();
char * newstr(int len);
void print_output(const char *str);
char * getBits(int num, unsigned int SIZE); 
unsigned int hextoint(char * hex);
extern char *regmap[32]; 
char * getheapStr(); 
void init_registers(); 
void logstring(const char *str); 
void instcountstring(const char *str); 
int nop(); 

