main:
	addi $t0, $t0, 7
	addi $t1, $t1, 6
	addi $t2, $t2, 3 
	addi $a0, $a0, 1 
	addi $a1, $a1, 3 
	andi $t1, $t0, 10
	add $t0, $t1, $t2
	sll $t1, $t0, 7
	sllv $t2, $t1, $t0
	slt $t1, $t0, $zero	
	slti $t1, $t2, 10
	srav $t1, $t2, $t3
	srl $t1, $t0, 2 
	sub $t1, $t0, $zero
	#beq testing
	addi $t0, $zero, 10
	addi $t1, $zero, 5
	addi $t3, $zero, 2
	sub  $t2, $t0, $t1
	addi $t1, $zero, 5
	sll  $t1, $t0, 3 
	beq  $zero, $zero, skip
	sllv $t2, $t0, $t3
	sllv $t2, $t0, $t3
	slti $t1, $t2, 10
	skip:
		sllv $t2, $t0, $t3
		srav $t1, $t2, $t3
		srl  $t1, $t0, 5
		srav $t1, $t2, $t3
	addi $t0, $zero, 10
	addi $t4, $zero, 7
	add  $t0, $t3, $t2
	bne  $zero, $t3, skip1
	add  $t2, $t3, $t2
	nop
	skip1: 
		add  $t1, $zero, $t2
		add  $t0, $t2, $t2
		bne  $zero, $t3, skip2
		sub  $t2, $t0, $t1
		addi $t1, $zero, 5
		nop
		skip2:
			sll  $t1, $t0, 3 
			sllv $t2, $t0, $t3
			sllv $t2, $t0, $t3
			slti $t1, $t2, 10
			sllv $t2, $t0, $t3
			srav $t1, $t2, $t3
			srl  $t1, $t0, 5
			srav $t1, $t2, $t3
