#include <stdio.h>
#include <sys/types.h>

int32_t div10(int32_t dividend)
{
	int64_t invDivisor = 0x1999;
	return (int32_t) ((invDivisor * dividend) >> 16);
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

/*
char res[10];
while ( a0 > 0) {
	s1 = a0;
	a0 = toChar(s1 - mul10(div10(a0)));
	store(a0); 
	a0 = div10(s1); 
}
res[i] = '\0';
*/



int main(int argc, const char *argv[])
{
	int num = 89879; 
	int i = 0; 
	char res[10];
	while ( num > 0) {
		res[i++] = toChar(num - mul10(div10(num)));
		num = div10(num); 

	}
	res[i] = '\0';
	return 0;
}
