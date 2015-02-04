#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
using namespace std; 

/* Program to demonstrate simple templates in C++
 * */
template <typename T, typename U>
T sum(T a , U b ){
	return a + b; 
}

int main(int argc, const char *argv[])
{
	cout << sum(2.1, 3) << endl ; 
	return 0;
}
