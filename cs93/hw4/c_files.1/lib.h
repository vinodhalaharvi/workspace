typedef struct _encoding { 
	char * binary; 
	char * hex; 
} encoding; 

static encoding encoding_data[] = { 
	{.binary="0000", .hex="0"},
	{.binary="0001", .hex="1"},
	{.binary="0010", .hex="2"},
	{.binary="0011", .hex="3"},
	{.binary="0100", .hex="4"},
	{.binary="0101", .hex="5"},
	{.binary="0110", .hex="6"},
	{.binary="0111", .hex="7"},
	{.binary="1000", .hex="8"},
	{.binary="1001", .hex="9"},
	{.binary="1010", .hex="A"},
	{.binary="1011", .hex="B"},
	{.binary="1100", .hex="C"},
	{.binary="1101", .hex="D"},
	{.binary="1110", .hex="E"},
	{.binary="1111", .hex="F"},
	{NULL, NULL}
}; 

typedef struct _register {
	char * registernumber; 
	char * registername; 
	char * registerbits; 
} reg; 

static reg register_data[] =  {
	{.registernumber="$0", .registername="$zero", .registerbits="00000"},
	{.registernumber="$1", .registername="na", .registerbits="00001"},
	{.registernumber="$2", .registername="$v0", .registerbits="00010"},
	{.registernumber="$3", .registername="$v1", .registerbits="00011"},
	{.registernumber="$4", .registername="$a0", .registerbits="00100"},
	{.registernumber="$5", .registername="$a1", .registerbits="00101"},
	{.registernumber="$6", .registername="$a2", .registerbits="00110"},
	{.registernumber="$7", .registername="$a3", .registerbits="00111"},
	{.registernumber="$8", .registername="$t0", .registerbits="01000"},
	{.registernumber="$9", .registername="$t1", .registerbits="01001"},
	{.registernumber="$10", .registername="$t2", .registerbits="01010"},
	{.registernumber="$11", .registername="$t3", .registerbits="01011"},
	{.registernumber="$12", .registername="$t4", .registerbits="01100"},
	{.registernumber="$13", .registername="$t5", .registerbits="01101"},
	{.registernumber="$14", .registername="$t6", .registerbits="01110"},
	{.registernumber="$15", .registername="$t7", .registerbits="01111"},
	{.registernumber="$16", .registername="$s0", .registerbits="10000"},
	{.registernumber="$17", .registername="$s1", .registerbits="10001"},
	{.registernumber="$18", .registername="$s2", .registerbits="10010"},
	{.registernumber="$19", .registername="$s3", .registerbits="10011"},
	{.registernumber="$20", .registername="$s4", .registerbits="10100"},
	{.registernumber="$21", .registername="$s5", .registerbits="10101"},
	{.registernumber="$22", .registername="$s6", .registerbits="10110"},
	{.registernumber="$23", .registername="$s7", .registerbits="10111"},
	{.registernumber="$24", .registername="$t8", .registerbits="11000"},
	{.registernumber="$25", .registername="$t9", .registerbits="11001"},
	{.registernumber="$26", .registername="na", .registerbits="11010"},
	{.registernumber="$27", .registername="na", .registerbits="11011"},
	{.registernumber="$28", .registername="$gp", .registerbits="11100"},
	{.registernumber="$29", .registername="$sp", .registerbits="11101"},
	{.registernumber="$30", .registername="$fp", .registerbits="11110"},
	{.registernumber="$31", .registername="$ra", .registerbits="11111"}, 
	{NULL, NULL, NULL}
}; 

typedef struct _inst { 
	char * instname; 
	char * opcodebits; 
	char * aluopcodebits; 
} inst; 

static inst inst_data[100] = {
	{.instname="sll", .opcodebits="000000", .aluopcodebits="000000"},
	{.instname="srl", .opcodebits="000000", .aluopcodebits="000010"},
	{.instname="sra", .opcodebits="000000", .aluopcodebits="000011"},
	{.instname="sllv", .opcodebits="000000", .aluopcodebits="000100"},
	{.instname="srlv", .opcodebits="000000", .aluopcodebits="000110"},
	{.instname="srav", .opcodebits="000000", .aluopcodebits="000111"},
	{.instname="jr", .opcodebits="000000", .aluopcodebits="001000"},
	{.instname="jalr", .opcodebits="000000", .aluopcodebits="001001"},
	{.instname="syscall", .opcodebits="000000", .aluopcodebits="001100"},
	{.instname="break", .opcodebits="000000", .aluopcodebits="001101"},
	{.instname="mfhi", .opcodebits="000000", .aluopcodebits="010000"},
	{.instname="mthi", .opcodebits="000000", .aluopcodebits="010001"},
	{.instname="mflo", .opcodebits="000000", .aluopcodebits="010010"},
	{.instname="mtlo", .opcodebits="000000", .aluopcodebits="010011"},
	{.instname="mult", .opcodebits="000000", .aluopcodebits="011000"},
	{.instname="multu", .opcodebits="000000", .aluopcodebits="011001"},
	{.instname="div", .opcodebits="000000", .aluopcodebits="011010"},
	{.instname="divu", .opcodebits="000000", .aluopcodebits="011011"},
	{.instname="add", .opcodebits="000000", .aluopcodebits="100000"},
	{.instname="addu", .opcodebits="000000", .aluopcodebits="100001"},
	{.instname="sub", .opcodebits="000000", .aluopcodebits="100010"},
	{.instname="subu", .opcodebits="000000", .aluopcodebits="100011"},
	{.instname="and", .opcodebits="000000", .aluopcodebits="100100"},
	{.instname="or", .opcodebits="000000", .aluopcodebits="100101"},
	{.instname="xor", .opcodebits="000000", .aluopcodebits="100110"},
	{.instname="nor", .opcodebits="000000", .aluopcodebits="100111"},
	{.instname="slt", .opcodebits="000000", .aluopcodebits="101010"},
	{.instname="sltu", .opcodebits="000000", .aluopcodebits="101011"},
	{.instname="regimm", .opcodebits="000001", .aluopcodebits="na"},
	{.instname="j", .opcodebits="000010", .aluopcodebits=""},
	{.instname="jal", .opcodebits="000011", .aluopcodebits=""},
	{.instname="beq", .opcodebits="000100", .aluopcodebits=""},
	{.instname="bne", .opcodebits="000101", .aluopcodebits=""},
	{.instname="blez", .opcodebits="000110", .aluopcodebits=""},
	{.instname="bgtz", .opcodebits="000111", .aluopcodebits=""},
	{.instname="addi", .opcodebits="001000", .aluopcodebits=""},
	{.instname="addiu", .opcodebits="001001", .aluopcodebits=""},
	{.instname="slti", .opcodebits="001010", .aluopcodebits=""},
	{.instname="sltiu", .opcodebits="001011", .aluopcodebits=""},
	{.instname="andi", .opcodebits="001100", .aluopcodebits=""},
	{.instname="ori", .opcodebits="001101", .aluopcodebits=""},
	{.instname="xori", .opcodebits="001110", .aluopcodebits=""},
	{.instname="lui", .opcodebits="001111", .aluopcodebits=""},
	{.instname="beql", .opcodebits="010100", .aluopcodebits=""},
	{.instname="bnel", .opcodebits="010101", .aluopcodebits=""},
	{.instname="blezl", .opcodebits="010110", .aluopcodebits=""},
	{.instname="bgtzl", .opcodebits="010111", .aluopcodebits=""},
	{.instname="lb", .opcodebits="100000", .aluopcodebits=""},
	{.instname="lh", .opcodebits="100001", .aluopcodebits=""},
	{.instname="lwl", .opcodebits="100010", .aluopcodebits=""},
	{.instname="lwl", .opcodebits="100011", .aluopcodebits=""},
	{.instname="lbu", .opcodebits="100100", .aluopcodebits=""},
	{.instname="lhu", .opcodebits="100101", .aluopcodebits=""},
	{.instname="lwr", .opcodebits="100110", .aluopcodebits=""},
	{.instname="sb", .opcodebits="101000", .aluopcodebits=""},
	{.instname="sh", .opcodebits="101001", .aluopcodebits=""},
	{.instname="swl", .opcodebits="101010", .aluopcodebits=""},
	{.instname="swl", .opcodebits="101011", .aluopcodebits=""},
	{.instname="swr", .opcodebits="101110", .aluopcodebits=""},
	{NULL, NULL, NULL}
};


typedef  enum INSTYPE {RTYPE, ITYPE, J} INSTYPE; 
typedef struct _inst_info {
	char * name; 
	char * rsrc; 
	char * rdest; 
} inst_info;

typedef char * (*function_type)(char *[]); 

void (*ptr)(int, int);

struct inst_table {
	char * name;
	char * (*ptr)(char *[]);
};

char * getAluOpcodeBits(char * name); 
char * getOpcodebits(char * name);
char * getRegisterBits(char *registername); 
char * binaryToHex(char * binary); 
void exitOnNull(void * ptr, char * msg); 
void printTail(); 
char * getBits(int num, unsigned int SIZE); 
void printHeaders(); 
