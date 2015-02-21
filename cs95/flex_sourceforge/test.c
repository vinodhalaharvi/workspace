#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
 * this is test and this is test again
 */
typedef enum {true, false} boolean; 
int main(int argc, const char *argv[])
/*
 * one more freaking comment to get rid off
 */
{
	boolean condition = false; 
	switch (condition) {
		printf("Do someelse");
		case 1: ; 	break;
/*
 * here we go again.. 
 */
		default: ;
	}
	while (condition) {
		printf("Do something");
		printf("Do something");
		printf("Do something");
		printf("Do something");
		printf("Do something");
		printf("Do something");
		printf("Do something");
		break; 
		printf("Here we go again");
	}
	return 0;
}
