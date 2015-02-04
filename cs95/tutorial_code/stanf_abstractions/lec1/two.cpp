#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
using namespace std; 

/* Program to read words from a file 
 * store it in a vector and print the words to the console
 * and print*/

void storeAndPrint(){
	std::vector<string> store; 
	string word; 
	ifstream input("input.txt"); 
	do {
		input >> word; 
		store.push_back(word); 
	} while (!input.fail());
	for (int i = 0; i < store.size(); i++) {
		cout << store[i] << endl;
	}
}


int main(int argc, const char *argv[])
{
	storeAndPrint(); 
	return 0;
}
