#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <assert.h>
#include <string.h>

int registers[32]; 
int pc; 

char * newstr(int len){
	assert(len >= 0);
	char * str = (char *) malloc(len + 1); 
	assert(str != NULL); 
	memset(str, '\0', len); 
	return str;
}

void refresh_registers(){
	WINDOW * mainwin;
	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 32; i++) { //sample input
		registers[i] = i;
	}
	char * regstr = newstr(30);
	int j = 0; 
	int k = 13; 
	for (int i = 0; i < 32; i++) {
		sprintf(regstr, "$%d = 0x%x", i, registers[i]);
		if ( i % 6 == 0) {
			k = 0; 
			j += 14; 
		}
		mvaddstr(0 + k++, 0 + j, regstr); 
	}
	sprintf(regstr, "$%s = 0x%x", "PC", pc);
	mvaddstr(0 + k++, 0 + j, regstr); 
	free(regstr); 
	refresh();
	delwin(mainwin);
	endwin();
	refresh();
}


int main(void) {
	refresh_registers(); 
	return EXIT_SUCCESS;
}
