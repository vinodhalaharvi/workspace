.data
.text
	addi $sp, $zero, 500
	jal main
	testing:
		addi $sp, $sp, -60
		# callee saved convention
		sw $s0, 24($sp)  # first on argument parameter
		sw $s1, 28($sp) 
		addi $t0, $zero, 10
		# and return
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		addi $sp, $sp, 60
		#jr $ra
		main:
			jal testing
			addi $t1, $zero, 8 
			addi $t2, $zero, 7 
