#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
using namespace std; 

/* Program to read words from a file 
 * store it in a vector and print the words to the console
 * using iterators
 * and print*/

void storeAndPrintUsingIterators(){
	ifstream input("input.txt");
	std::vector<string> store; 
	do {
		string word; 
		input >> word; 
		store.push_back(word); 
	} while (!input.fail());

	std::vector<string>::iterator  itr; 
	for(itr = store.begin(); itr != store.end(); itr++){
		cout << *itr << endl; 
	}
	return; 
}


int main(int argc, const char *argv[])
{
	storeAndPrintUsingIterators(); 
	return 0;
}
