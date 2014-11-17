# Vinod Halaharvi
# HUID: 80778287
# vinod.halaharvi@gmail.com, halavin@iit.edu
# prob2
.data  # no relevance to the assembler.
	outputString: .asciiz ""
.text  # no relevance to the assembler.

# mimic REG_IOCONTROL wrie is always ready
la $t1, 0xFF00
#la $t1, 100 
nop
addi $v0, $zero, 2
sb $v0, 0($t1) 
nop
jal main
outputChar:
	nop # do nothing instruction
	checkOutputReady:	
		la $t1, 65280 # t1 <- REG_IOCONTROL address
		lw $t0, 0($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 2 # $t1 <- is the bit 1 of $t0 set ? 
		nop
		beq $t1, $0, checkOutputReady # if not then busy wait
	writeAChar:
		la $t1, REG_IOBUFFER_2
		sb $v0, 0($t1) # store $a0 to REG_IOBUFFER_2
		jr $ra
	main:
		jal outputChar
