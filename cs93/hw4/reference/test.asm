.data
	outputString: .asciiz "            \n"
.text

	# $a0 <- $a0, $a1 
	multiply:
		
		slt  $t4, $a0, $zero
		beq  $t4, $zero, skip1
		sub  $a0, $zero, $a0 # flip sign 
		skip1:
		slt  $t5, $a1, $zero
		beq  $t5, $zero, skip2
		sub  $a1, $zero, $a1 # flip sign 
		skip2:
		add $t0, $zero, $zero
		loop: 
			srav  $t1, $a1, $t0
			andi  $t2, $t1, 1
			beq   $t2, 1 label 
			back:
				addi  $t0, $t0, 1
				slti  $t8, $t0, 32
				bne   $t8, $zero, loop	
				add $a0, $v0, $zero

				# fix sign before returning
				beq $t4, $zero, skip3
				sub  $a0, $zero, $a0 # flip sign 

				skip3:
				beq $t5, $zero, skip4
				sub  $a0, $zero, $a0 # flip sign 

				skip4:
				jr $ra
			label:
				sllv $t3, $a0, $t0
				add $v0, $v0, $t3
				j back
		jr $ra

	# $a0 <- $a0
	mul10:
		sll $t0, $a0, 3
		sll $t1, $a0, 1 
		add $t0, $t0, $t1
		add $a0, $t0, $zero
		jr $ra

		
	# $a0 <- $a0
	div10:
		addi $a1, $zero, 0x1999
		add $s0, $ra, $zero
		jal multiply
		srl $a0, $a0, 16
		add $ra, $s0, $zero
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
		#addi $a0, $zero, 11
		#addi $a1, $zero, -11
		#jal mul10

		#addi $a0, $zero, 110
		#addi $a1, $zero, 0x1999
		#jal div10

		#addi $a0, $zero, 8989
		#add $s1, $a0, $zero
		#jal div10
		#jal mul10
		#sub $a0, $s1, $a0
		#jal toChar
		#jal printCharAndExit
		addi $a0, $zero, 8989
		loop1:	
			beq $a0, $zero, exit
			add $s1, $a0, $zero
			jal div10
			jal mul10
			sub $a0, $s1, $a0
			#jal toChar
			add $a0, $s1, $zero
			jal div10
			j loop1
		exit:
			jal printIntAndExit

