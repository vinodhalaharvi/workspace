# Vinod Halaharvi
# HUID: 80778287
# vinod.halaharvi@gmai.com, halavin@iit.edu
# prob2
.data  # no relevance to the assembler.
	outputString: .asciiz "            \n"
.text  # no relevance to the assembler.
outputChar:
	nop # do nothing instruction
	checkOutputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, ($t1) # $t0 <- loadWord($t1) 
		nop
		andi $t1, $t0, 0x2 # $t1 <- is the bit 1 of $t0 set ? 
		beq $t1, $0, checkOutputReady # if not then busy wait
	writeAChar:
		la $t1, REG_IOBUFFER_2
		sb $v0 ($t1) # store $a0 to REG_IOBUFFER_2
		jr $ra
# prob3
inputChar:
	nop
	checkInputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, ($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 0x1 # $t1 <- is the bit 0 of $t0 set ? 
		beq $t1, $0, checkInputReady # if not then busy wait
	readAChar:
		la $t1, REG_IOBUFFER_1
		lhu $v0 ($t1) # store $a0 to REG_IOBUFFER_2
		jr $ra
# prob4
# $a0 has location of the null terminated string to output
outputStringToDevice:
	ori $t0, $ra, $0 # store the return value
	loop1: 
		lb $v0, ($a0) # $a0 has location of string
		beq $v0, $zero, return1 # if '\0' then return
		jal outputChar # output a character
		addi $a0, $a0, 1 # increament location
		j loop1 # loop again
	return1:
		jr $t0 # return to caller
# prob5
# Store the input string at location $a0 and null terminate it
inputStringFromDevice:
	ori $t0, $ra, $0 # store the return value	
	ori $t1, $0, '\n' # line-feed
	loop2: 
		jal inputChar # Wait for character input
		beq $v0, $t1, return2 # if line-feed return
		sb $v0, ($a0) # store the char read to memory
		addi $a0, $a0, 1 # increament location
		j loop2 # loop again
	return2:
		sb $zero ($a0) # store '\0' to null terminate string
		jr $t0 # return to caller

