.data  # no relevance to the assembler.
	debug  : .asciiz "here\n"
	outputString : .asciiz ""
	REG_IOCONTROL: .word 1
	REG_IOBUFFER_1: .space 1
	REG_IOBUFFER_2: .space 1
.text  # no relevance to the assembler.
readChar:
	addi $sp, $sp, -60
	sw   $s0, 24($sp)  # first on argument parameter
	sw   $s1, 28($sp) 
	sw   $ra, 32($sp) 
	checkInputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, ($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 0x1 # $t1 <- is the bit 0 of $t0 set ? 
		beq $t1, $zero, checkInputReady # if not then busy wait
	readChar:
		la $t1, REG_IOBUFFER_1
		lb $v0 ($t1) # store $a0 to REG_IOBUFFER_2
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		lw $ra, 32($sp)
		addi $sp, $sp, 60
		jr $ra
# Store the input string at location $a0 and null terminate it
readStringFromDevice:
	addi $sp, $sp, -60
	sw   $s0, 24($sp)  # first on argument parameter
	sw   $s1, 28($sp) 
	sw   $ra, 32($sp) 
	loop2: 
		jal readChar # Wait for character input
		addi $t1, $zero, 0xA
		beq $v0, $t1, return2 # if line-feed return
		sb $v0, ($a0) # store the char read to memory
		addi $a0, $a0, 1 # increament location
		j loop2 # loop again
	return2:
		sb $zero ($a0) # store '\0' to null terminate string
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		lw $ra, 32($sp)
		addi $sp, $sp, 60
		jr $ra
	main:
		# $a0 will be the address to load the value
		la  $a0, outputString
		jal readStringFromDevice
		add $a0, $v0, $zero
		li $v0, 4
		syscall
		li $v0, 10 
		syscall
