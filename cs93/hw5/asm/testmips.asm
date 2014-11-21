.data
        firstNumber:  .asciiz "-32767"
        secondNumber: .asciiz "32767"
	outputString: .asciiz "00000000000"
.text
	jal main
	# $a0 <- $a0
	mul10:
		sll $t0, $a0, 3
		sll $t1, $a0, 1 
		add $t0, $t0, $t1 	# n = (n << 3) + (n << 1)
		add $a0, $t0, $zero
		jr $ra
	# $a0 <- $a0
	div10:
		addi $sp, $sp, -60
		sw $s0, 24($sp)  # first on argument parameter
		sw $s1, 28($sp) 
		sw $ra, 32($sp) 
		addi $t0, $zero, 0
		addi $t1, $zero, 0
		addi $t3, $zero, 0
		addi $t4, $zero, 0
		#$t0 = ($a0 >> 1) + ($a0 >> 2);
		srl $t3, $a0, 1
		add $t0, $t3, $zero
		srl $t4, $a0, 2
		add $t0, $t3, $t4
		#$t0 = $t0 + ($t0 >> 4);
		srl $t3, $t0, 4
		add $t0, $t3, $t0
		#$t0 = $t0 + ($t0 >> 8);
		srl $t3, $t0, 8
		add $t0, $t3, $t0
		#$t0 = $t0 + ($t0 >> 16);
		srl $t3, $t0, 16
		add $t0, $t3, $t0
		#$t0 = $t0 >> 3;
		srl $t0, $t0, 3
		#$t1 = $a0 - ((($t0 << 2) + $t0) << 1);
		sll $t3, $t0, 2 
		add $t3, $t3, $t0
		sll $t3, $t3, 1 
		sub $t1, $a0, $t3
		#return $t0 + ($t1 > 9);
		addi $t4, $zero, 9
		slt  $t3, $t4, $t1
		add $t0, $t0, $t3
		add $v0, $t0, $zero
		lw $s0, 24($sp)
		lw $s1, 28($sp)
		lw $ra, 32($sp)
		addi $sp, $sp, 60
		jr $ra
	# $a0 <- $a0
	toChar:
		addi $a0, $a0, 48
		jr $ra
	intToString:
		addi $sp, $sp, -60
		# callee saved convention
		sw $s0, 24($sp)  # first on argument parameter
		sw $s1, 28($sp) 
		sw $s2, 32($sp) 
		sw $s3, 36($sp) 
		sw $ra, 40($sp) 
		# do work 
		la   $s3, outputString
		slt  $t4, $a0, $zero # check if the first number is negative
		beq  $t4, $zero, intToStringskip
		addi $t4, $zero, 0 # check if the first number is negative
		addi $t4, $t4, 45 
		sb   $t4, 0($s3)
		addi $s3, $s3, -1
		sub  $a0, $zero, $a0 # flip sign  of $a0
		intToStringskip:
		addi $s3, $s3, 11
		add $s0, $a0, $zero
		mainLoop:	
			add  $a0, $s0, $zero
			jal  div10 # output is in $v0
			add $a0, $v0, $zero
			add $s1, $v0, $zero
			jal  mul10 # output is in $v0
			sub $t0, $s0, $a0
			add $a0, $t0, $zero
			jal toChar
			sb   $a0, 0($s3)
			addi $s3, $s3, -1
			add  $s0, $s1, $zero
			beq  $s0, $zero, exit
			j mainLoop
		exit:
			la $v0, outputString #output is in $a0
			lw $s0, 24($sp)
			lw $s1, 28($sp)
			lw $s2, 32($sp) 
			lw $s3, 36($sp) 
			lw $ra, 40($sp) 
			addi $sp, $sp, 60
			jr $ra
        stringToInt:
                addi $sp, $sp, -60
		 # callee saved convention
                sw $s0, 24($sp)  
                add      $v0, $zero, $zero # memory index
                add      $t1, $zero, $zero # is negative flag
                lb       $t0, 0($a0)
                addi     $t8, $zero, 45 # 45 is a '-'
                beq      $t0, $t8, Isneg
                stringToIntLoop:
                        lb      $t0, 0($a0)
                        beq     $t0, $zero, fixNeg # line feed
                        sll     $t2, $v0, 1 # this and next line calculated (n<<3) + (n<<1)
                        sll     $v0, $v0, 3 # which is same as multiplying by 10
                        add     $v0, $v0, $t2       
                        addi    $t0, $t0, -48 # convert to digit
                        add     $v0, $v0, $t0       
                        addi    $a0, $a0, 1         
                        j  stringToIntLoop
                Isneg:
                        addi     $t1, $zero, 1 # set the negative flag
                        addi     $a0, $a0, 1
                        j stringToIntLoop
                fixNeg:
                        beq     $t1, $zero, result # if negative flag is set, reverse sign 
                        sub     $v0, $zero, $v0 # final output is in v0
		 # and return
                result:
                        lw  $s0, 24($sp)
                        addi $sp, $sp, 60
                        jr  $ra   
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
						addi $sp, $sp, 60
						jr $ra
						# result  is in $v0
			label:
				sllv $t3, $a0, $t0 # shift left by the amount in $a0
				add $v0, $v0, $t3 # accumulator
				j back
        main:
                la $a0, firstNumber 
                jal stringToInt
                add $s0, $v0, $zero
                la $a0, secondNumber 
                jal stringToInt # strings to ints 
                add $s1, $v0, $zero
                add $a0, $s0, $zero
                add $a1, $s1, $zero
		jal multiply # multiply 
		add $a0, $v0, $zero
		jal intToString # convert int to string 
		add $a0, $v0, $zero
		li $v0, 4
		syscall
		li $v0, 10 
		syscall
		nop
