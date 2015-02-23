#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 

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
