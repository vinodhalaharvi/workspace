#include <stdio.h>
#define BUFLEN 10

int mod1(int dividend, int divisor, char *string){
	int remainder = 0 ; 
	int quotient = 0 ;
	int temp; 
	while (dividend >= quotient * divisor + remainder) {
		quotient++; 	
	}
	quotient--; 
	remainder =  dividend - (quotient * divisor); 
	printf("%d", remainder);
	return quotient; 
}

char intToChar(int num){
	return num + '0';
}

void intToString(int num){
	int remainder = 0 ; 
	int quotient = 0 ;
	int divisor = 10 ; 
	int dividend = num; 
	char string[BUFLEN]; 
	int i = 0;
	while (dividend > 0 && i < BUFLEN-1) { 
		quotient = 0;
		while (dividend >= quotient * divisor + remainder) {
			quotient++; 	
		}
		quotient--; 
		string[i++] = intToChar(dividend - (quotient * divisor)); 
		dividend = quotient; 
	}
	string[i] = '\0';
	while(--i >= 0)
		putchar(string[i]); 
	printf("\n");
}

/*void intToString1(int num){
	int dividend = num; 
	char string[BUFLEN]; 
	while ((dividend = mod(dividend, 10, string)) != 0)
		; 
	printf("\n");
}*/



void main() {
	int num; 
	printf ("\nEnter the Number: ");
	scanf("%d", &num);
	intToString(num); 
}
