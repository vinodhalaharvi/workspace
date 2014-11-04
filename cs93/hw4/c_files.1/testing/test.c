#include <stdio.h>
#include <stdlib.h>

int mul(int a, int b){
	long res = 0;
	for (int i = 0; i < 32; i++) {
		if (((b >> i) & 1)  == 1) {
			res += (a << i); 
		}
	}
	return res; 
}

int mul1(int a0, int a1){
	long v0 = 0;
	for (int t0 = 0; t0 < 32; t0++) {
		int t1 = a1 >> t0; 
		int t2 = t1 & 1; 
		if (t2 == 1) {
			int t3 = a0 << t0; 
			v0 += t3; 
		}
	}
	return v0; 
}


int main(int argc, const char *argv[])
{
	printf("%d\n", mul1(5, 3));
	return 0;
}
