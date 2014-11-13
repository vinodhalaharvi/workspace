#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}

typedef struct _register {
	char * registernumber; 
	char * registername; 
	char * registerbits; 
} reg; 

int isempty(const char *string){
	int i=0; 
	int count = 0; 
	if (string == NULL)
		return 1; 
	while(string[i] != '\0') {
		if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n') {
			count++; 
		}
		i++;
	}
	return (count == 0); 
}

int filter(char **lineptr){
	if (strstr(*lineptr, ".data"))  {
		return 1; 
	}
	if (isempty(*lineptr))
		return 1; 
	if (strstr(*lineptr, ".text"))
		return 1; 
	if (strstr(*lineptr, ".text"))
		return 1; 
	return 0;
}

void cleanLine(char **lineptr){
	(*lineptr)[strlen(*lineptr)-1] = '\0';  // remove new line 
	char *found = strchr(*lineptr, '#');  //remove everything after '#'
	int index; 
	if (found) {
		index = found - (*lineptr); 
		(*lineptr)[index] = '\0';
	}
}

int islabel(const char * string){
	return (strchr(string, ':') != NULL); 
}

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

void getFiles(int argc, const char * argv[], 
		FILE **rfile, FILE **MIFfile){
	assert(argc == 3); 
	const char * inputfilepath =  argv[1]; 
	const char * outputfilepath =  argv[2]; 
	*rfile = fopen(inputfilepath, "r"); 
	assert (rfile != NULL); 
	*MIFfile = fopen(outputfilepath, "w"); 
	assert (MIFfile != NULL); 
	return ; 
}
char * getRegisterBits(char *registername){
	int i = 0; 
	//Does the register name match ?
	while (register_data[i].registername != NULL) {
		if (strcmp(register_data[i].registername,registername) == 0 ){
			return  register_data[i].registerbits; 
		}
		i++; 
	}
	i = 0; 
	// Does the register number match ? 
	while (register_data[i].registernumber != NULL) {
		if (strcmp(register_data[i].registernumber,registername) == 0 ){
			return  register_data[i].registerbits; 
		}
		i++; 
	}
	fprintf(stderr, "%s: No such register ..\n", registername);
	assert(1 == 0); 
	//we should never be here
	return NULL; 
}


char *  loadstore(const char * inst, const char * rt, 
		int offset, const char *  base){
	char * printme = newstr(100);
	sprintf(printme, "%s %s %d(%s)", inst, rt, offset, base); 
	printf("%s\n", printme);
	free(printme);
	return  printme;
}

char *  imm(const char * inst, const char * rs, 
		const char *  rt, int immValue){
	char * printme = newstr(100);
	sprintf(printme, "%s %s %s %d", inst, rs, rt, immValue); 
	printf("%s\n", printme);
	free(printme);
	return  printme;
}


char *  regInst(const char * inst, const char * rs, 
		const char *  rt, const char * rd){
	char * printme = newstr(100);
	sprintf(printme, "%s %s %s %s", inst, rs, rt, rd); 
	printf("%s\n", printme);
	free(printme);
	return  printme;
}

char *  jumpInst(const char * inst, int inst_index){
	char * printme = newstr(100);
	sprintf(printme, "%s 0x%X", inst, inst_index); 
	printf("%s\n", printme);
	free(printme);
	return  printme;
}



void do_first_pass(int argc, const char *argv[]){
	size_t len = 0 ; 
	char * line = NULL; 
	FILE * rfile,  * MIFfile; 
	getFiles(argc, argv, &rfile, &MIFfile); 
	char * inst = newstr(100);
	char * base = newstr(100);
	char * rt = newstr(100);
	char * rs = newstr(100);
	char * rd = newstr(100);
	int offset;
	int immValue = 0; 
	int n = 0; 
	int instIndex = 0; 
	//char * loadstorestr = newstr(100); 
	const char * inststr = "%4[^ \t] %6[^,],%i(%6[^)])"; 
	while(getline(&line, &len, rfile) != EOF){
		cleanLine(&line);
		if (filter(&line))
			continue; 
		if (islabel(line))
			continue; 
		printf("%s\n", line);
		((n = sscanf(line, inststr, inst, rt, &offset, base)) == 4)
			&& loadstore(inst, rt, offset, base); 
		const char * immstr = "%4[^ \t] %6[^,],%6[^,],%d"; 
		((n = sscanf(line, immstr, inst, rs, rt, &immValue)) == 4)
			&& imm(inst, rs, rt, immValue); 
		const char * regStr = "%4[^ \t] %6[^,],%6[^,],%6[^,]"; 
		((n = sscanf(line, regStr, inst, rs, rt, rd)) == 4)
			&& regInst(inst, rs, rt, rd); 
		const char * jumpStr = "%4[^ \t] %i"; 
		((n = sscanf(line, jumpStr, inst, &instIndex)) == 2)
			&& jumpInst(inst, instIndex); 
	}
	fclose(rfile);
	fclose(MIFfile);
}

int main(int argc, const char *argv[])
{
	do_first_pass(argc, argv); 
	return 0;
}


