#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function called for each element
void print (int elem)
{
	cout << 'a';
}

int main()
{
	vector<int> coll(5);
	for_each (coll.begin(), coll.end(), print); 
	cout << endl;
}
