.data
	newline: .asciiz "\n"
.text
	printAndExit:
		addi $a0, $t0, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		addi $a0, $t1, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		addi $a0, $t2, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		addi $a0, $t3, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		li $v0, 10 
		syscall
main:
	addi $a0, $zero, 11
	addi $a1, $zero, 12
	slt  $t4, $a0, $zero # check if the first number is negative beq  $t4, $zero, skip1
	sub  $a0, $zero, $a0 # flip sign 
	skip1:
	slt  $t5, $a1, $zero # check if the second number is negative 
	beq  $t5, $zero, skip2
	sub  $a1, $zero, $a1 # flip sign 
	skip2:
	add $t0, $zero, $zero
	addi $v0, $zero, 0 # initialize $v0
	multiplyloop: 
		srav  $t1, $a1, $t0 # shift multiplier to right
		andi  $t2, $t1, 1
		addi  $t1, $zero, 1
		beq   $t2, $t1 label 
		back:
			addi  $t0, $t0, 1
			slti  $t8, $t0, 32 # shift multiplicand to left
			bne   $t8, $zero, multiplyloop	
			# fix sign before returning
			beq $t4, $zero, skip3 # first number was negative
			sub  $v0, $zero, $v0 # flip sign 
			skip3:
				beq $t5, $zero, label # second number was negative
				sub  $v0, $zero, $v0 # flip sign 
		label:
			sllv $t3, $a0, $t0 # shift left by the amount in $a0
			add $v0, $v0, $t3 # accumulator
	jal printAndExit
