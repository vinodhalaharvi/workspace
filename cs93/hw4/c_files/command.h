char * lwcz(char * tokens[]);
char * swcz(char * tokens[]);
char * subu(char * tokens[]);
char * sub(char * tokens[]);
char * add(char * tokens[]);
char * addu(char * tokens[]);
char * and(char * tokens[]);
char * or(char * tokens[]);
char * xor(char * tokens[]);
char * nor(char * tokens[]);
char * slt(char * tokens[]);
char * sltu(char * tokens[]);
char * sll(char * tokens[]);
char * srl(char * tokens[]);
char * sra(char * tokens[]);
char * sllv(char * tokens[]);
char * srlv(char * tokens[]);
char * srav(char * tokens[]);
char * jalr(char * tokens[]);
char * mfhi(char * tokens[]);
char * mflo(char * tokens[]);
char * mult(char * tokens[]);
char * multu(char * tokens[]);
char * _div(char * tokens[]);
char * divu(char * tokens[]);
char * addi(char * tokens[]);
char * addiu(char * tokens[]);
char * bgez(char * tokens[]);
char * bgezal(char * tokens[]);
char * bltz(char * tokens[]);
char * bltzal(char * tokens[]);
char * slti(char * tokens[]);
char * sltiu(char * tokens[]);
char * andi(char * tokens[]);
char * ori(char * tokens[]);
char * xori(char * tokens[]);
char * lui(char * tokens[]);
char * lb(char * tokens[]);
char * lh(char * tokens[]);
char * lwl(char * tokens[]);
char * lw(char * tokens[]);
char * lbu(char * tokens[]);
char * lhu(char * tokens[]);
char * lwr(char * tokens[]);
char * sb(char * tokens[]);
char * sh(char * tokens[]);
char * sw(char * tokens[]);
char * swl(char * tokens[]);
char * swr(char * tokens[]);
char * jr(char * tokens[]);
char * mthi(char * tokens[]);
char * mtlo(char * tokens[]);
char * beq(char * tokens[]);
char * bne(char * tokens[]);
char * blez(char * tokens[]);
char * bgtz(char * tokens[]);
char * syscall(char * tokens[]);
char * _break(char * tokens[]);
char * j(char * tokens[]);
char * jal(char * tokens[]);
char * copz(char * tokens[]);

//pseudo instructions
char * la(char * tokens[]); 

char * type2(char * arg0, char * arg1);
char * type3(char * arg0, char * arg1, char * arg2);
char * type4(char * arg0, char * arg1, char *arg2, char *arg3);
char * type5(char * arg0, char * arg1, char *arg2, char *arg3, char *arg4);
char * type6(char * arg0, char * arg1, char *arg2, char *arg3, char *arg4, char *arg5);
