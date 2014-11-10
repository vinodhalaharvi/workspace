stringToIntTesting:
	addi $sp, $sp, -60
	# callee saved convention
	sw $ra, 32($sp) 
	la $a0, firstNumber 
	jal stringToInt
	add $t0, $v0, $zero
	add $a0, $t0, $zero
	li $v0, 1
	syscall
	la $a0, enterString
	li $v0, 4 
	syscall
	la $a0, secondNumber 
	jal stringToInt
	add $t1, $v0, $zero
	add $a0, $t1, $zero
	li $v0, 1
	syscall
	la $a0, enterString
	li $v0, 4 
	syscall
	# and return
	lw $ra, 32($sp)
	add $sp, $sp, 60
	jr $ra

