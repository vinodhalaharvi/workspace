CFLAGS=-Wall -ggdb -std=gnu99
CC=gcc
O=0
objects=lib.o command.o assembler.o 
#LDLIBS=
#LDFLAGS=

all: $(objects)

$(objects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

clean : cleanobj cleandiff

assembler: $(objects)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

run: all assembler
	./assembler ./prob.asm ./prob.mif | less

debug: all assembler
	echo 'run ./prob.asm ./prob.mif' > .gdbinit
	gdb ./assembler

cleanobj:
	rm -f *.o
	rm assembler

#tags: 
#	ctags -R --c++-kinds=+p --fields=+iaS \
#		--extra=+q . /usr/include /usr/local/include 

tags:	
	ctags -R *.[ch]

.PHONY: clean cleanobj cleandiff tags
