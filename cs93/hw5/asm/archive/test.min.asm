.data
        firstNumber:  .asciiz "-32"
        secondNumber:  .asciiz "32"
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
		addi $t4, $zero, 0 
		addi $t4, $t4, 45 # 45 is a dash '-' char 
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
			la $v0, outputString #output is in $v0
			lw $s0, 24($sp)
			lw $s1, 28($sp)
			lw $s2, 32($sp) 
			lw $s3, 36($sp) 
			lw $ra, 40($sp) 
			addi $sp, $sp, 60
			jr $ra
        main:
                la $a0, -1999
		nop
		jal intToString # convert int to string 
		nop
		add $a0, $v0, $zero
		nop
