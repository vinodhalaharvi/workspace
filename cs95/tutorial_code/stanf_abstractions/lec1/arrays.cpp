#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std; 

int main(int argc, const char *argv[])
{
	int arrOnStack[50]; 
	int *arrOnHeap; 

	arrOnHeap = new int [50] ;

	for (int i = 0; i < 50; i++) {
		arrOnStack[i] = i; 
		arrOnHeap[i] = arrOnStack[i] * 2;
	}

	for (int i = 0; i < 50; i++) {
		cout << arrOnHeap[i];
		cout << endl; 
	}

	delete [] arrOnHeap; 
	return 0;
}
