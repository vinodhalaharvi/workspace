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
