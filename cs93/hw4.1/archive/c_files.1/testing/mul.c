#include <stdio.h>
#include <stdlib.h>
#define BUFLEN 80

/*
 * Vinod Halaharvi
 * HUID: 80778287
 * halavin@iit.edu, vinod.halaharvi@gmail.com
 */

/* 
 * Flip the sign, if the input is negative make 
 * if positive for "computation ready"
 * */
int flipSign(int a){
	return ~a + 1; 
}


/* Helper function to convert from character 
 * to int
 * */
int charToInt(char ch){
	return ch - '0'; 
}


/* Main function to multiply two numbers*/
long mul(int a, int b){
	int i = 0; 
	long res = 0;
	int c; 
	int signFlip = 0; 
	if ( b < 0) {
		signFlip = 1 ; 
		c = flipSign(b); 
	} else {
		c = b; 
	}
	/* Long from multiplication 
	 * shift multiplicand to left and add to accumulator 
	 * if the multiplier bit position is 1 else 
	 * skip */
	for (i = 0; i < 32; i++) {
		if (((c >> i) & 1)  == 1) {
			res += (a << i); 
		}
	}
	if (signFlip == 1)
		return flipSign(res); 
	else 
		return res; 
}



/* Convert string to an integer */
int atoii(char *str){
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
		res += mul(place , charToInt(str[i]));
		place = mul(place, 10); 
		i--; 
	}
	if (negFlag)
		res = mul(res, -1); 
	return res; 
}

/* Helper function convert integer to char*/
char intToChar(int num){
	return num + '0';
}


/* Function to conver the final resultant integer to string*/
void intToString(int num){
	int remainder = 0 ; 
	int quotient = 0 ;
	int divisor = 10 ; 
	char string[BUFLEN]; 
	int i = 0;
	int dividend; 
	int negFlag = 0; 

	if ( num == 0 )  {
		putchar('0'); 
		putchar('\n');
		return; 
	}

	if (num < 0) {
		negFlag = 1; 
		dividend = mul(num, -1); 
	} else {
		dividend = num; 
	}
	/* This is akin to find modulus */
	while (dividend > 0 && i < BUFLEN-1) { 
		quotient = 0;
		while (dividend >= mul(quotient , divisor + remainder)) {
			quotient++; 	
		}
		quotient--; 
		string[i++] = intToChar(dividend - mul(quotient , divisor)); 
		dividend = quotient; 
	}
	string[i] = '\0';
	if (negFlag)
		putchar('-'); 
	while(--i >= 0)
		putchar(string[i]); 
	putchar('\n');
}

/* printf like utility*/
void printString(char *str){
	int i = 0; 
	while (str[i++] != '\0') {
		putchar(str[i]); 
	}
}

/* check if the character is a valid digit between 0 and 9*/
int isValidDigit(char ch){
	if ( ch - '0' >= 0 && ch - '0' <= 9)
		return 1; 
	else
		return 0;
}

/* verify if the string is a valid integer*/
int verify(char *string){
	int i =0; 
	char ch; 
	if (string[0] == '-')
		i++; 
	while((ch = string[i++]) != '\0') {
		if (!isValidDigit(ch)) {
				printString("\nNot an invalid Integer..\n"); 
				exit(99); 
			}

	}
	return atoii(string); 
}

/* main program to provider application interface*/
int main(int argc, const char *argv[]){
	char ch; 
	char buf[80];
	int count = 0; int i = 0; 
	int nums[2]; int j=0; 
	int k =0; 

	for (i = 0; i < 2; i++) {
		if (i == 0) {
			printString("\nPlease enter First Number: "); 
		} else {
			printString("\nPlease enter Second Number: "); 
		}
		while ((ch = getchar()) != '\n'){
			buf[k++] = ch; 
		}
		buf[k] = '\0';
		k = 0; 
		nums[j++] = verify(buf); 
	}
	printString("\n");
	intToString(mul(nums[0], nums[1])); 
	return 0;
}
