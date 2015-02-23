#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <stack>
using namespace std; 

/* Simple implementation of stack
 * */


void printReverse(){
	ifstream input("input.txt"); 
	std::stack<string> stck; 
	do {
		string word; 
		input >> word; 
		stck.push(word); 
	} while (!input.fail());

	do {
		cout << stck.top() << endl; 
		stck.pop(); 
	} while (!stck.empty());

	return; 
}


int main(int argc, const char *argv[])
{
	printReverse(); 
	return 0;
}
