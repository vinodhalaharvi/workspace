.data 
	string:  .asciiz "-32767"
.text
	jal main
	main:
		add $t0, $t1, $t2
		addi $a0, $a0, 10
		andi $t1, $t0, 10
		chkpoint: 
			beq $t1, $zero, chkpoint 
			bne $t0, $zero, chkpoint
			j chkpoint	
			jal chkpoint
			jr $ra	
			la $a0, string 
			lw $t0, 12($t1) 
			sb $t0, 12($t1) 
			sll $t1, $t0, 7
			sllv $t2, $t0, $t1
			slt $t1, $t0, $zero	
			slti $t1, $t2, 10
			srav $t1, $t2, $t3
			srl $t1, $t0, $shiftamt
			sub $t1, $t0, $zero
			sw $t0, 12($t1) 
