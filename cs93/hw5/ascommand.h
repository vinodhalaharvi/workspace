char * sub(char * tokens[]);
char * add(char * tokens[]);
char * and(char * tokens[]);
char * or(char * tokens[]);
char * xor(char * tokens[]);
char * nor(char * tokens[]);
char * slt(char * tokens[]);
char * sll(char * tokens[]);
char * srl(char * tokens[]);
char * sra(char * tokens[]);
char * mult(char * tokens[]);
char * sllv(char * tokens[]);
char * srlv(char * tokens[]);
char * srav(char * tokens[]);
char * jalr(char * tokens[]);
char * addi(char * tokens[]);
char * slti(char * tokens[]);
char * andi(char * tokens[]);
char * ori(char * tokens[]);
char * xori(char * tokens[]);
char * lui(char * tokens[]);
char * lb(char * tokens[]);
char * lh(char * tokens[]);
char * lw(char * tokens[]);
char * sb(char * tokens[]);
char * sh(char * tokens[]);
char * sw(char * tokens[]);
char * jr(char * tokens[]);
char * beq(char * tokens[]);
char * bne(char * tokens[]);
char * j(char * tokens[]);
char * jal(char * tokens[]);
char * nop(char * tokens[]); 

//pseudo instructions
char * la(char * tokens[]); 

char * type2(char * arg0, char * arg1);
char * type3(char * arg0, char * arg1, char * arg2);
char * type4(char * arg0, char * arg1, char *arg2, char *arg3);
char * type5(char * arg0, char * arg1, char *arg2, char *arg3, char *arg4);
char * type6(char * arg0, char * arg1, char *arg2, char *arg3, char *arg4, char *arg5);

//utility functions
function_type getFunc(const char * name); 
unsigned int is_valid_inst(const char *line); 
int isValidInt(const char *str, int base, int *value); 

