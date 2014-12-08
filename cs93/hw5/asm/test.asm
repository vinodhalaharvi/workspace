jal main
main:
	addi $a0, $zero, 0
	multiplyloop: 
		srav  $t1, $a1, $t0 
		andi  $t2, $t1, 1
		addi  $t1, $zero, 1
		beq   $t2, $t1 label 
		back:
			addi  $t0, $t0, 1
			slti  $t8, $t0, 32 
			bne   $t8, $zero, multiplyloop	
			
			beq $t4, $zero, skip3 
			sub  $v0, $zero, $v0 
			skip3:
				beq $t5, $zero, label 
				sub  $v0, $zero, $v0 
		label:
			sllv $t3, $a0, $t0 
			add $v0, $v0, $t3 
			add $t0, $zero, $v0
