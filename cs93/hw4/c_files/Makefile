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


run2: all assembler
	./assembler /tmp/asm/prob2.asm /tmp/asm/prob2.mif
run3: all assembler
	./assembler /tmp/asm/prob3.asm /tmp/asm/prob3.mif
run4: all assembler
	./assembler /tmp/asm/prob4.asm /tmp/asm/prob4.mif
run5: all assembler
	./assembler /tmp/asm/prob5.asm /tmp/asm/prob5.mif
run6: all assembler
	./assembler /tmp/asm/prob6.asm /tmp/asm/prob6.mif
run7: all assembler
	./assembler /tmp/asm/prob7.asm /tmp/asm/prob7.mif
run8: all assembler
	./assembler /tmp/asm/prob8.asm /tmp/asm/prob8.mif
run: all assembler
	./assembler /tmp/test.asm /tmp/test.mif


debug2: all assembler
	echo 'run /tmp/asm/prob2.asm /tmp/asm/prob2.mif' > .gdbinit
	gdb ./assembler
debug3: all assembler
	echo 'run /tmp/asm/prob3.asm /tmp/asm/prob3.mif' > .gdbinit
	gdb ./assembler
debug4: all assembler
	echo 'run /tmp/asm/prob4.asm /tmp/asm/prob4.mif' > .gdbinit
	gdb ./assembler
debug5: all assembler
	echo 'run /tmp/asm/prob5.asm /tmp/asm/prob5.mif' > .gdbinit
	gdb ./assembler
debug6: all assembler
	echo 'run /tmp/asm/prob6.asm /tmp/asm/prob6.mif' > .gdbinit
	gdb ./assembler
debug7: all assembler
	echo 'run /tmp/asm/prob7.asm /tmp/asm/prob7.mif' > .gdbinit
	gdb ./assembler
debug8: all assembler
	echo 'run /tmp/asm/prob8.asm /tmp/asm/prob8.mif' > .gdbinit
	gdb ./assembler
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
