# Vinod Halaharvi
# HUID: 80778287
# vinod.halaharvi@gmail.com, halavin@iit.edu
# (904) 200 1070
###################################

Known issues: 
###################################
Currently the IO interface has not been implemented. 
The input numbers are harded code in the asm/test.asm file. 
The multiplication routine works fine for all numbers but there are some issues with converting the result of negative number multiplication to string output. 
There is an option to make the emulator stop at each "nop" instruction. Other options are as shown below
The output of the multiplication is printed in the reverse digit order. 

How to run:
###################################
# debug assembler
make clean ; make runas CFLAGS+=-DDEBUG=1

# run assembler
make clean ; make runas

# do not emulate just print instructions
make clean ; make runem CFLAGS+=-DDISASSEMBLY=1 CFLAGS+=-DDONTEMULATE=1 

# emulate but regular display
make clean ; make runem CFLAGS+=-DDISASSEMBLY=1 

# if you are using EMULATE feature, Please press (Ctrl-D) key
# to single step the progress.

# emulate and curses display 
make clean ; make runem CFLAGS+=-DEMULATE=1 

# emulate and curses display and single step the progress
make clean ; make runem CFLAGS+=-DEMULATE=1  CFLAGS+=-DSINGLESTEP=1  

