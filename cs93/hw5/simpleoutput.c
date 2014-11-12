#include "emcommand.h"
#include <stdio.h>
#include <stdlib.h>

void pr_reg(const char * inst, int reg1){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s", inst, regmap[reg1]); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_reg_reg(const char * inst, int reg1, int reg2){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s", inst, regmap[reg1], regmap[reg2]); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_reg_reg_reg(const char * inst, int reg1, int reg2, int reg3){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, %s", inst, regmap[reg1], regmap[reg2], regmap[reg3]); 
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

void pr_reg_imm(const char * inst, int reg, int imm){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, 0x%X", inst, regmap[reg], imm); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_reg_reg_imm(const char * inst, int reg1, int reg2, int imm){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, 0x%X", inst, regmap[reg1], regmap[reg2], imm); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_reg_reg_sa(const char * inst, int reg1, int reg2, int sa){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, 0x%X", inst, regmap[reg1], regmap[reg2], sa); 
	printf("%40s ; ", printstr);
	free(printstr); 
}

void pr_base_rt_inst_index(const char * inst, int reg, int inst_index){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, 0x%X", inst, regmap[reg], inst_index); 
	printf("%40s ; ", printstr);
	free(printstr); 
}



void pr_base_rt_offset(const char * inst, int base, int reg, int offset){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, 0x%X(%s)", inst, regmap[reg], offset, regmap[base]); 
	printf("%40s ; ", printstr);
	free(printstr); 
}


void pr_reg_reg_offset(const char * inst, int reg1, int reg2, int offset){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, 0x%X", inst, regmap[reg1], regmap[reg2], offset); 
	printf("%40s ; ", printstr);
	free(printstr); 
}
