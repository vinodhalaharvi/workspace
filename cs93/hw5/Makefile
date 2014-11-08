CFLAGS=-Wall -ggdb -std=gnu99
CC=gcc
O=0
emobjects=emcommand.o emlib.o emulator.o 
asobjects=aslib.o ascommand.o assembler.o

LDLIBS=-lncurses

all: $(objects)

$(emobjects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

$(asobjects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

clean : cleanobj cleandiff

emulator: $(emobjects)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

assembler: $(asobjects)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

runas:  assembler
	./assembler  asm/test.asm mif/test.mif

runem:  emulator
	./emulator  mif/test.mif

cleanobj:
	rm -f *.o
	rm emulator
	rm assembler
tags: 
	ctags *.[ch]

debug:  emulator
	echo 'run mif/test.mif' > .gdbinit
	gdb ./emulator

.PHONY: clean cleanobj cleandiff tags
