.data
	outputString: .asciiz "\n"
.text

	# $a0 <- $a0
	mul10:
		sll $t0, $a0, 3
		sll $t1, $a0, 1 
		add $t0, $t0, $t1 	# n = (n << 3) + (n << 1)
		add $a0, $t0, $zero
		jr $ra


	#$v0 <- $a0, $a1
	multiply:
		addi $sp, $sp, -60
		# callee saved convention
		sw $s0, 24($sp) 
		sw $s1, 28($sp) 
		# do work 
		# registers used are
		#
		slt  $t4, $a0, $zero # check if the first number is negative
		beq  $t4, $zero, skip1
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
					beq $t5, $zero, skip4 # second number was negative
					sub  $v0, $zero, $v0 # flip sign 
					skip4:
						# and return
						lw $s0, 24($sp)
						lw $s1, 28($sp)
						add $sp, $sp, 60
						jr $ra
						# result  is in $v0
			label:
				sllv $t3, $a0, $t0 # shift left by the amount in $a0
				add $v0, $v0, $t3 # accumulator
				j back


	# $a0 <- $a0
	div10:
		addi $sp, $sp, -60
		# callee saved convention
		sw $s0, 24($sp)  # first on argument parameter
		sw $s1, 28($sp) 
		# save return address
		sw $ra, 32($sp) 
		# call another function
		addi $a1, $zero, 0x1999 # divisor, dividend is already in $a0
		jal multiply # the output is in $v0
		srl $a0, $v0, 16 # divident
		# restore saved registers
		# and return
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		lw $ra, 32($sp)
		add $sp, $sp, 60
		jr $ra


	# $a0 <- $a0
	toChar:
		add $a0, $a0, 48
		jr $ra

	# $a0 <- $a0
	toDigit:
		add $a0, $a0, -48 
		jr $ra

	printIntAndExit:
		li $v0, 1  #print
		syscall

		li $v0, 10  #exit
		syscall

	printInt:
		li $v0, 1  #print
		syscall
		jr $ra

	printStringAndExit:
		li $v0, 4  #print
		syscall

		li $v0, 10  #exit
		syscall

	printCharAndExit:
		li $v0, 11  #print
		syscall

		li $v0, 10  #exit
		syscall

	# a1 <-  changed
	storeOutput:
		la $a1, outputString
		sb $a0 ($a1)
		jr $ra

	main:
		addi $s0, $zero, 8679
		la   $s3, outputString
		mainLoop:	
			add  $a0, $s0, $zero
			jal div10 # output is in $a0
			add $s1, $a0, $zero
			jal mul10 # output is in $a0
			sub $t0, $s0, $a0
			add $s0, $s1, $zero
			add $a0, $t0, $zero
			#jal printInt
			sb   $a0, 0($s3)
			addi $s3, $s3, 1
			beq  $s0, $zero, exit
			j    mainLoop
		exit:
			li $v0, 4
			la $a0, outputString
			syscall

			li $v0, 10 
			syscall
