#include <stdio.h>

int mul(int a, int b){
	long res = 0;
	for (int i = 0; i < 32; i++) {
		if (((b >> i) & 1)  == 1) {
			res += (a << i); 
		}
	}
	return res; 
}

int charToInt(int num){
	return num - 48; 
}

int intToChar(int num){
	return num + 48; 
}

int stringToInt(char *str){
	int i = 0;
	int res = 0 ; 
	int negFlag = 0 ;
	long place = 1; 
	int len =0; 
	if (str[0] == '-') {
		negFlag = 1; 
		str++; 
	}
	while (str[i] != '\0') {
		i++; 
	}
	i--;
	while (i >= 0) {
		res += mul(place,charToInt(str[i]));
		place = mul(place,10); 
		i--; 
	}
	if (negFlag)
		res = mul(res, -1); 
	return res; 
}

int main(int argc, const char *argv[])
{
	printf("%d\n", mul(-5, -3));
	return 0;
}

