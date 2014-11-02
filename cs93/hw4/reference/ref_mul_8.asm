/*for (i = 0; i < 32; i++) {
	if (((c >> i) & 1)  == 1) {
		res += (a << i);
	}
}*/

mul:
	#$t0 counter, 
	#$t1 mutiplicand
	#$t2 result
	#$t3 temp result of shift
	#$t4 temp result of shift & 1
	ori $t1, $v0, $0 # multiplicand 
	ori $t0, $0, 0x0 # counter variable
	loop:
		srl  $t3, $t1, $t0
		and  $t4, $t3, 0x1
		slti $t4, $t4, 0x1
		bez  $t4, loop
		srl  $t1, 

atoi:
    or      $v0, $zero, $zero   # num = 0
    or      $t1, $zero, $zero   # isNegative = false
    lb      $t0, 0($a0)
    bne     $t0, '+', .isp      # consume a positive symbol
    addi    $a0, $a0, 1
.isp:
    lb      $t0, 0($a0)
    bne     $t0, '-', .num
    addi    $t1, $zero, 1       # isNegative = true
    addi    $a0, $a0, 1
.num:
    lb      $t0, 0($a0)
    slti    $t2, $t0, 58        # *str <= '9'
    slti    $t3, $t0, '0'       # *str < '0'
    beq     $t2, $zero, .done
    bne     $t3, $zero, .done
    sll     $t2, $v0, 1
    sll     $v0, $v0, 3
    add     $v0, $v0, $t2       # num *= 10, using: num = (num << 3) + (num << 1)
    addi    $t0, $t0, -48
    add     $v0, $v0, $t0       # num += (*str - '0')
    addi    $a0, $a0, 1         # ++num
    j   .num
.done:
    beq     $t1, $zero, .out    # if (isNegative) num = -num
    sub     $v0, $zero, $v0
.out:
    jr      $ra         # return
