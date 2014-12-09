jal main
main:
	addi $t1, $zero, 0
	lb   $t0, 0($t1)
	addi $t1, $zero, 50
	sb   $t0, 0($t1) 
