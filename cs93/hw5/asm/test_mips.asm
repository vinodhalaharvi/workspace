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
		addi $t0, $zero, 10
		addi $t1, $zero, 9 
		addi $t2, $zero, 8
		add  $t3, $t1, $t2
		sub  $t0, $t3, $t0
		jal printAndExit

