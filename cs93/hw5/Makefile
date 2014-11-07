CFLAGS=-Wall -ggdb -std=gnu99
CC=gcc
O=0
objects=command.o lib.o emulator.o

#CPPFLAGS+=-I/usr/include/postgresql/
#LDLIBS=-lpq -lssh
#LDFLAGS=

all: $(objects)

#client : $(objects)
#	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(objects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

clean : cleanobj cleandiff

emulator: $(objects)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

run:  emulator
	./emulator 

cleanobj:
	rm -f *.o
	rm emulator
tags: 
	ctags *.[ch]

debug:  
	gdb ./emulator

.PHONY: clean cleanobj cleandiff tags
