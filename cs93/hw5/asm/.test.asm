# Vinod Halaharvi
# HUID: 80778287
# vinod.halaharvi@gmail.com, halavin@iit.edu
# prob2
.data  # no relevance to the assembler.
	outputString: .asciiz ""
.text  # no relevance to the assembler.
# mimic REG_IOCONTROL write is always ready
jal main
outputChar:
	checkOutputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, 0($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 2 # $t1 <- is the bit 1 of $t0 set ? 
		beq $t1, $0, checkOutputReady # if not then busy wait
	writeAChar:
		la $t1, REG_IOBUFFER_2
		sb $a0, 0($t1) # store $a0 to REG_IOBUFFER_2
		jr $ra
	main:
		la $t1, REG_IOCONTROL
		addi $v0, $zero, 2
		sb $v0, 0($t1) 
		addi $a0, $zero, 10
		jal outputChar
		nop
		nop
