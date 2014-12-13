# Vinod Halaharvi
# HUID: 80778287
# vinod.halaharvi@gmail.com, halavin@iit.edu
# (904) 200 1070
###################################

Known issues: 
###################################
Currently the IO interface has not been implemented. 
The input numbers are harded code in the asm/test.asm file. 

How to run:
###################################
# debug assembler
# for modelSim and my emulator mif file gneration WORDADDRESSABLE should be 1
make clean ; make runas CFLAGS+=-DDEBUG=1 CFLAGS+=-DWORDADDRESSABLE=1

# debug assembler
# for modelSim and my emulator mif file gneration WORDADDRESSABLE should be 1
make clean ; make runas  CFLAGS+=-DWORDADDRESSABLE=1

#for altera hardware mif file it's BYTEADDRESSABLE 
#and so WORDADDRESSABLE should not be defined
make clean ; make runas

# run assembler is the default for running 
# for altera hardware
make clean ; make runas

# do not emulate just print instructions
make clean ; make runem CFLAGS+=-DDISASSEMBLY=1 CFLAGS+=-DDONTEMULATE=1  CFLAGS+=-DWORDADDRESSABLE=1

# emulate but regular display
make clean ; make runem CFLAGS+=-DDISASSEMBLY=1 CFLAGS+=-DWORDADDRESSABLE=1

# if you are using EMULATE feature, Please press (Ctrl-D) key
# to single step the progress.

# emulate and curses display 
make clean ; make runem CFLAGS+=-DEMULATE=1 CFLAGS+=-DWORDADDRESSABLE=1

# emulate and curses display and single step the progress
make clean ; make runem CFLAGS+=-DEMULATE=1  CFLAGS+=-DSINGLESTEP=1  CFLAGS+=-DWORDADDRESSABLE=1

