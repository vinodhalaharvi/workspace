#include "emcommand.h"
#include <stdio.h>
#include <stdlib.h>

void pr_rs(const char * inst, int rs){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s", inst, regmap[rs]); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_rs_rt_rd(const char * inst, int rs, int rt, int rd){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, %s", inst, regmap[rd], regmap[rt], regmap[rs]); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_inst_index(const char * inst, int inst_index){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s 0x%X", inst, inst_index); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_rt_imm(const char * inst, int rt, int imm){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, 0x%X", inst, regmap[rt], imm); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_rs_rt_imm(const char * inst, int rs, int rt, int imm){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, 0x%X", inst, regmap[rt], regmap[rs], imm); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_rt_rd_sa(const char * inst, int rt, int rd, int sa){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, 0x%X", inst, regmap[rd], regmap[rt], sa); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_base_rt_inst_index(const char * inst, int rt, int inst_index){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, 0x%X", inst, regmap[rt], inst_index); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_base_rt_offset(const char * inst, int base, int rt, int offset){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, 0x%X(%s)", inst, regmap[rt], offset, regmap[base]); 
	printf("%40s ; ", printstr);
	free(printstr); 
}


void pr_rs_rt_offset(const char * inst, int rs, int rt, int offset){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, 0x%X", inst, regmap[rt], regmap[rs], offset); 
	printf("%40s ; ", printstr);
	free(printstr); 
}
