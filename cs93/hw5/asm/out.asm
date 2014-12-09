.data  # no relevance to the assembler.
	debug  : .asciiz "here\n"
	inputString: .asciiz "a"
	REG_IOCONTROL: .word 1
	REG_IOBUFFER_1: .space 1
	REG_IOBUFFER_2: .space 1
	
.text  # no relevance to the assembler.

# char to be writtne is in $a0
writeChar:
	addi $sp, $sp, -60
	sw   $s0, 24($sp)  # first on argument parameter
	sw   $s1, 28($sp) 
	sw   $ra, 32($sp) 
	checkOutputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, ($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 0x2 # $t1 <- is the bit 0 of $t0 set ? 
		beq $t1, $zero, checkOutputReady # if not then busy wait
	writeAChar:
		la $t1, REG_IOBUFFER_2
		sb $a0 ($t1) # store $a0 to REG_IOBUFFER_2
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		lw $ra, 32($sp)
		addi $sp, $sp, 60
		jr $ra

# Store string in $a0 to output device
writeStringFromDevice:
	addi $sp, $sp, -60
	sw   $s0, 24($sp)  # first on argument parameter
	sw   $s1, 28($sp) 
	sw   $ra, 32($sp) 
	loop2: 
		jal writeChar # Wait for character input
		addi $t1, $zero, 0x0
		beq $a0, $t1, return2 # if line-feed return
		addi $a0, $a0, 1 # increament location
		j loop2 # loop again
	return2:
		addi $t0, $zero, 0xA
		sb  $t0, ($a0) # store the char read to memory
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		lw $ra, 32($sp)
		addi $sp, $sp, 60
		jr $ra
	main:
		# $a0 will be the address to load the value
		la  $a0, outputString
		jal writeStringFromDevice
		add $a0, $v0, $zero
		li $v0, 4
		syscall
		li $v0, 10 
		syscall
