#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eval(char *exp)
{
	int num1;
	char op[10]; 
	int num2;
	int n = sscanf(exp, "%d %s %d", &num1, &op[0], &num2); 
	if (n == 3) { 
		if (strcmp(op, "<<") == 0) { return num1 << num2; 
		} else if (strcmp(op, ">>") == 0) { return num1 >> num2; 
		} else if (strcmp(op, "+") == 0) { return num1 + num2; 
		} else if (strcmp(op, "-") == 0) { return num1 - num2; 
		} else if (strcmp(op, "/") == 0) { return num1 / num2; 
		} else if (strcmp(op, "*") == 0) { return num1 * num2; 
		} else if (strcmp(op, "%") == 0) { return num1 % num2; 
		} else if (strcmp(op, "&") == 0) { return num1 & num2; 
		} else if (strcmp(op, "|") == 0) { return num1 | num2; 
		} else if (strcmp(op, "^") == 0) { return num1 ^ num2; 
		}
	}
	return -1;
}


int main(int argc, const char *argv[])
{
	char * exp = "2 + 2"; 
	char op[10]; 
	int num1;
	int num2;
	printf("%d\n", eval(exp));
	return 0;


}
