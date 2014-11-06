#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char * removeSpaces(const char * s) {
	char * d = strdup(s); 
	char * res = d; 
	memset(d, '\0', strlen(s) + 1);
	do {
		if (!isspace(*s++))
			*d++ = *(s-1); 
	} while(!(*s == '\0'));
	return res; 
}

int eval_exp(char *expWithParen, int *error)
{
	int num1, num2; 
	char op[10], exp[100]; 
	sscanf(expWithParen, "(" "%99[^)]" ")", exp); 
	int n = sscanf(exp, "%i%2s%i", &num1, op, &num2); 
	if (n == 3) {
		if (strcmp(op, "<<") == 0) { return num1 << num2; 
		} else if (strcmp(op, ">>") == 0) { *error = 0 ; return num1 >> num2; 
		} else if (strcmp(op, "+") == 0) { *error = 0 ; return num1 + num2; 
		} else if (strcmp(op, "-") == 0) { *error = 0 ; return num1 - num2; 
		} else if (strcmp(op, "/") == 0) { *error = 0 ; return num1 / num2; 
		} else if (strcmp(op, "*") == 0) { *error = 0 ; return num1 * num2; 
		} else if (strcmp(op, "%") == 0) { *error = 0 ; return num1 % num2; 
		} else if (strcmp(op, "&") == 0) { *error = 0 ; return num1 & num2; 
		} else if (strcmp(op, "|") == 0) { *error = 0 ; return num1 | num2; 
		} else if (strcmp(op, "^") == 0) { *error = 0 ; return num1 ^ num2; 
		}
	}
	*error = 1; 
	return -1; 
}

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}


char * eval_register(char *expWithParen)
{
	int num1, num2; 
	char op[10]; 
	char *exp = newstr(100);
	sscanf(expWithParen, "(" "%99[^)]" ")", exp); 
	return exp; 
}

int main(int argc, const char *argv[])
{
	//char * exp = "(11 | 0xB)"; 
	char * exp = "($t0)"; 
	char op[10]; 
	int num1;
	int num2;
	int error; 
	printf("%d\n", eval_exp(exp, &error)); 
	if (error) {
		printf("%s\n", eval_register(exp)); 
	}
	return 0;
}
