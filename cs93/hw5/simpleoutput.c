#include "emcommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void pr_rs(const char * inst, int rs){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s", inst, regmap[rs]); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_rs_rt_rd(const char * inst, int rs, int rt, int rd){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, %s", inst, regmap[rd], regmap[rs], regmap[rt]); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_inst_index(const char * inst, int inst_index){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %d", inst, inst_index); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_rt_imm(const char * inst, int rt, int imm){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %d", inst, regmap[rt], imm); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_rs_rt_imm(const char * inst, int rs, int rt, int imm){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, %d", inst, regmap[rt], regmap[rs], imm); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_rt_rd_sa(const char * inst, int rt, int rd, int sa){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, %d", inst, regmap[rd], regmap[rt], sa); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_base_rt_inst_index(const char * inst, int rt, int inst_index){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %d", inst, regmap[rt], inst_index); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}

void pr_base_rt_offset(const char * inst, int base, int rt, int offset){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %d(%s)", inst, regmap[rt], offset, regmap[base]); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}


void pr_rs_rt_offset(const char * inst, int rs, int rt, int offset){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "%s %s, %s, %d", inst, regmap[rt], regmap[rs], offset); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}


void pr_nop(){
	char * printstr = newstr(40);
	sprintf(printstr, "                                       ");                   
	sprintf(printstr, "nop"); 
#ifdef DISASSEMBLY
	printf("%40s ; ", printstr);
#endif
	memset(currInst, '\0', 100);
	memcpy(currInst, printstr, strlen(printstr));
	free(printstr); 
}


