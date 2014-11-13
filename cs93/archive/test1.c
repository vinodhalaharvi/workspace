#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	for (int i = 0; i < 100; i++) {
		printf("%s\r\%s", "testing", "ING");
	}
	return 0;
}
