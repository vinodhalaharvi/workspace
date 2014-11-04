#include <stdio.h>

int isempty(char * string){
	int i =0; 
	int count = 0; 
	if (string == NULL)
		return 1; 
	while(string[i] != '\0') {
		if (string[i] != ' ' && string[i] != '\t') {
			count++; 
		}
		i++;
	}
	return (count == 0); 
}



int main(int argc, const char *argv[])
{
	printf("%d\n", isempty("   "));
	return 0;
}
