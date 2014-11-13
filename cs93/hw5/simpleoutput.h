void pr_rs(const char * inst, int rs);
void pr_rs_rt_rd(const char * inst, int rs, int rt, int rd);
void pr_inst_index(const char * inst, int inst_index);
void pr_rt_imm(const char * inst, int rt, int imm);
void pr_rs_rt_imm(const char * inst, int rs, int rt, int imm);
void pr_rt_rd_sa(const char * inst, int rt, int rd, int sa);
void pr_base_rt_inst_index(const char * inst, int rt, int inst_index);
void pr_base_rt_offset(const char * inst, int base, int rt, int offset);
void pr_rs_rt_offset(const char * inst, int rs, int rt, int offset);
