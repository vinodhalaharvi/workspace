#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std; 

/* Program to read words from a file 
 * and print*/

void printFile(const string & filename)
{
	ifstream input("input.txt"); 
	while (true) {
		string word;
		input >> word; 
		if (input.fail()) break; 
		cout << word << endl; 
	}
}

int main(int argc, const char *argv[])
{
	fund("input.txt");
	return 0;
}
