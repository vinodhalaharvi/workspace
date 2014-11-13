CFLAGS=-Wall -ggdb -std=gnu99
CC=gcc
O=0
asobjects=parseAsm.o

LDLIBS=-lncurses

all: $(objects)

$(emobjects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

$(asobjects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

clean : cleanobj 
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

parseAsm: $(asobjects)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

run:  parseAsm
	./parseAsm ./test.asm ./test.mif

cleanobj:
	rm -f *.o
	rm parseAsm
tags: 
	ctags *.[ch]

debug:  parseAsm
	gdb ./parseAsm

.PHONY: clean cleanobj 
