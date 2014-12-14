nop
jal main
main:
	addi $t0, $zero, 8 
	j skip
	addi $t1, $zero, 4 
	addi $t3, $zero, 3
	add  $t0, $t3, $t2
	add  $t2, $t3, $t2
	add  $t1, $zero, $t2
	add  $t0, $t2, $t2
	sub  $t2, $t0, $t1
	add  $t2, $t3, $t2
	add  $t1, $zero, $t2
	add  $t0, $t2, $t2
	addi $t1, $zero, 5
	nop
	skip:
		sll  $t1, $t0, 3 
		sllv $t2, $t0, $t3
		sllv $t2, $t0, $t3
		slti $t1, $t2, 10
		sllv $t2, $t0, $t3
		srav $t1, $t2, $t3
		srl  $t1, $t0, 5
		srav $t1, $t2, $t3
