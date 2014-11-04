#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

unsigned int frombin32(char * bits){
	return (int) strtol(bits, NULL,  2); 
}

unsigned int frombin16(char * bits){
	return (int) strtol(bits, NULL,  2); 
}

unsigned int intFromlower16bits(char * bits){
	assert( 32 == strlen(bits) );
	return (int) strtol(bits + 16, NULL,  2); 
}

unsigned int intFromhigher16bits(char * bits){
	char * temp = strdup(bits); 
	assert(32 == strlen(temp));
	temp[16] = '\0'; 
	assert(16 == strlen(temp));
	return (int) strtol(temp, NULL,  2); 
}

int main(int argc, const char *argv[])
{
	printf("%d\n", intFromlower16bits("00000001000000011000000000100001"));
	printf("%d\n", intFromhigher16bits("00000001000000011000000000100001"));
	return 0;
}
