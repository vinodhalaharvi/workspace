#include <stdio.h>

typedef struct _data { 
char * name; 
} data; 

data mydata [] = {
	{.name = "vinod"},
	{NULL},
}; 


int main(int argc, const char *argv[])
{
	int i =0; 
	while (mydata[i].name != NULL) {
		printf("%s\n", mydata[i].name);
		i++; 
	}
	return 0;
}
