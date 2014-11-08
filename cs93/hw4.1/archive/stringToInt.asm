.data
	input: .asciiz "1999"
.text
	main:
		la $a0, input
		jal stringToInt 
		add $t0, $v0, $zero
		
		li $v0, 1
		add $a0, $t0, $zero
		syscall

		li $v0, 10 
		syscall
stringToInt:
	add      $v0, $zero, $zero   # memory index
	add      $t1, $zero, $zero   # is negative flag
	lb       $t0, 0($a0)
	beq      $t0, '-', .Isneg
	.loop:
		lb      $t0, 0($a0)
		beq     $t0, 0, .fixNeg 	# line feed
		sll     $t2, $v0, 1
		sll     $v0, $v0, 3
		add     $v0, $v0, $t2       
		addi    $t0, $t0, -48
		add     $v0, $v0, $t0       
		addi    $a0, $a0, 1         
		j   .loop
	.Isneg:
		addi     $t1, $zero, 1       # set the negative flag
		addi     $a0, $a0, 1
		j .loop
	.fixNeg:
		beq     $t1, $zero, .result    
		sub     $v0, $zero, $v0
	.result:
		jr      $ra       
