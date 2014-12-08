.data
	newline: .asciiz "\n"
.text
	printAndExit:
		addi $a0, $t0, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		addi $a0, $t1, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		addi $a0, $t2, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		addi $a0, $t3, 0
		li $v0, 1
		syscall
		li $v0, 4
		la $a0, newline
		syscall
		li $v0, 10 
		syscall
	main:
	addi $t0, $zero, 8 
	addi $t1, $zero, 4 
	addi $t3, $zero, 3
	add  $t0, $t3, $t2
	add  $t2, $t3, $t2
	add  $t1, $zero, $t2
	add  $t0, $t2, $t2
	sub  $t2, $t0, $t1
	j skip
	add  $t2, $t3, $t2
	add  $t1, $zero, $t2
	add  $t0, $t2, $t2
	addi $t1, $zero, 5
	skip:
		sll  $t1, $t0, 3 
		sllv $t2, $t0, $t3
		sllv $t2, $t0, $t3
		slti $t1, $t2, 10
		sllv $t2, $t0, $t3
		srav $t1, $t2, $t3
		srl  $t1, $t0, 5
		srav $t1, $t2, $t3
	jal printAndExit
