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

char * eval_register(char *expWithParen)
{
        char *exp = newstr(100);
        if(sscanf(expWithParen, "%*[^(](%6[^)])",  exp) == 1)  
                return exp; 
        if(sscanf(expWithParen, "(%6[^)])",  exp) == 1)  
                return exp; 
        assert(1 == 0); 
}

int register_offset(char * input){
	int offset; 
	char reg[2];
	int t = sscanf(input, "%i(%6s)", &offset, reg); 
	assert(t != -1); 
	return offset; 
}

int main(int argc, const char *argv[])
{
	char * inst = newstr(100); 
	char * rs = newstr(100); 
	char * base = newstr(100); 
	int offset; 
	char * input = "0x7724($sp)"; 
	int output = register_offset(input); 
	printf("0x%x\n", output);
	return 0;
}
