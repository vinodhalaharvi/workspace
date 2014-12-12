#10 10 40 2 
main:
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

