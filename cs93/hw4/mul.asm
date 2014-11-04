.data
	printResult: .asciiz "Product value is: \n"
	here: .asciiz "HERE ..\n"
.text
	main:
		li $a0, 12
		li $a1, 12
		jal multiply
		done:
			add $a0, $v0, $zero
			li $v0, 1 
			syscall
			li $v0, 10 
			syscall
	multiply:
		add $s0, $zero, $zero
		add $t0, $zero, $zero
		loop: 
			srav  $t1, $a1, $t0
			andi  $t2, $t1, 1
			beq   $t2, 1 label 
			back:
				addi  $t0, $t0, 1
				slti  $t8, $t0, 32
				bne   $t8, $zero, loop	
				j done 
			label:
				sllv $t3, $a0, $t0
				add $v0, $v0, $t3
				j back
		jr $ra
	
