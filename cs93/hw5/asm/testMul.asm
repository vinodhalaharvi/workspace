.data
	inputString: .asciiz "input string\n"
.text
	main:
		add $a0, $zero, 11
		mul10
mul10:
        sll $t0, $a0, 3
        sll $t1, $a0, 1 
        add $t0, $t0, $t1 # n = (n << 3) + (n << 1)
        add $a0, $t0, $zero
        jr $ra

