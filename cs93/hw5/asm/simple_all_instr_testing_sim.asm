jal main
main:
	addi $t0, $zero, 10
	addi $t1, $zero, 5
	addi $t3, $zero, 2
	sub  $t2, $t0, $t1
	sll  $t1, $t0, 3 
	sllv $t2, $t0, $t1
	slt  $t1, $t0, $zero	
	slti $t1, $t2, 10
	srav $t1, $t2, $t3
	srl  $t1, $t0, 5
	sub  $t1, $t0, $zero
