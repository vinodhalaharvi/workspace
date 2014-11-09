.data
	inputString: .asciiz "787"
.text
	addToNumbers:
		addi $a0, $a0, $imm

stringToInt:
	addi $sp, $sp, -60
	# callee saved convention
	sw $s0, 24($sp)  
	add      $v0, $zero, $zero   # memory index
	add      $t1, $zero, $zero   # is negative flag
	lb       $t0, ($a0)
	addi     $s0, $zero, 45 # 45 is a '-'
	beq      $t0, $s0, Isneg
	loop4:
		lb      $t0, ($a0)
		beq     $t0, $zero, fixNeg 	# line feed
		sll     $t2, $v0, 1 # this and next line calculated (n<<3) + (n<<1)
		sll     $v0, $v0, 3 # which is same as multiplying by 10
		add     $v0, $v0, $t2       
		addi    $t0, $t0, -48 # convert to digit
		add     $v0, $v0, $t0       
		addi    $a0, $a0, 1         
		j   loop4
	Isneg:
		addi     $t1, $zero, 1       # set the negative flag
		addi     $a0, $a0, 1
		j loop4
	fixNeg:
		beq     $t1, $zero, result   # if negative flag is set, reverse sign 
		sub     $v0, $zero, $v0 # final output is in v0
	# and return
	result:
		lw $s0, 24($sp)
		add $sp, $sp, 60
		jr      $ra       
	main:
		la $a0, inputString 
		jal stringToInt

		addi $a0, $v0, $zero
		li $v0, 1
		syscall
