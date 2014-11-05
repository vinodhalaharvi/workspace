CFLAGS=-Wall -ggdb -std=gnu99
CC=gcc
O=0
objects=lib.o command.o assembler.o 

#CPPFLAGS+=-I/usr/include/postgresql/
#LDLIBS=-lpq -lssh
#LDFLAGS=

all: $(objects)

#client : $(objects)
#	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(objects): %.o: %.c
	$(CC) -Wno-unused-variable $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $< $(LDLIBS)  

clean : cleanobj cleandiff

assembler: $(objects)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@ 

run: all assembler
	./assembler /tmp/test.asm /tmp/test.mif

debug: all assembler
	echo 'run /tmp/test.asm /tmp/test.mif' > .gdbinit
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
