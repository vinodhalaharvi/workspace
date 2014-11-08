#include <stdio.h>
#include <assert.h>

static void tester(const char *data)
{
    char word1[20], word2[32], word3[64];
    int n = sscanf(data, "%19s[:]", word1); 
    printf("%d\n", n);
    //int n = sscanf(data, "%19s %31[^, ] %*[,]%63s", word1, word2, word3);
    //printf("Test data: <<%s>>\n", data);
    if (n == 1) {
    	/* code */
	    printf("%s\n", word1); 
    }
    //printf("n = %d; w1 = <<%s>>, w2 = <<%s>>, w3 = <<%s>>\n", n, word1, word2, word3);
}


int main(int argc, const char *argv[])
{
	int lineno = 1; 
	size_t len = 0 ; 
	char * line = NULL; 
	FILE *rfile = fopen(argv[1], "r"); 
	assert (rfile != NULL); 
	while(getline(&line, &len, rfile) != EOF){
		tester(line); 
		lineno++; 
	}
	return 0;
}
