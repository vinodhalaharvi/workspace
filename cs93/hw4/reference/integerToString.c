#include <stdio.h>
#include <sys/types.h>
/*
int32_t proc 
    mov    edx,1999999Ah    ; load 1/10 * 2^32
    imul   eax              ; edx:eax = dividend / 10 * 2 ^32
    mov    eax,edx          ; eax = dividend / 10
    ret
int32_t endp
*/

int32_t div10(int32_t dividend)
{
	int64_t invDivisor = 0x1999999A;
	return (int32_t) ((invDivisor * dividend) >> 32);
}

int mul10(int num){
	return (num << 3) + (num << 1); 
}

int toChar(int digit){
	return digit + 48; 
}

int toDigit(int character){
	return character - 48; 
}


int main(int argc, const char *argv[])
{
	int num = 89879; 
	printf("%c\n", toChar(num - mul10(div10(num))));
	return 0;
}
