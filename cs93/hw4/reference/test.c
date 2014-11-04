#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	unsigned long long num = 1; 
	num = (num<<16)/10; 
	printf("0x%llx\n", num);
	return 0;
}
