override CFLAGS += -Wall -ggdb -std=gnu99
#CFLAGS+=-DDEBUG=1

CC=gcc
O=0
emobjects=emcommand.o  emulator.o  simpleoutput.o
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
	rm -f emulator
	rm -f assembler
tags: 
	ctags *.[ch]

debugem:  emulator
	echo 'set confirm off' > .gdbinit
	echo 'run mif/test.mif' >> .gdbinit
	gdb ./emulator

debugas:  assembler
	echo 'set confirm off' > .gdbinit
	echo 'run asm/test.asm mif/test.mif' >> .gdbinit
	gdb ./assembler

.PHONY: clean cleanobj cleandiff tags
