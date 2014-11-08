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
