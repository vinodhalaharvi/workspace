stringToInt:
addi $sp, $sp, -60
# callee saved convention
sw $s0, 24($sp)  
add      $v0, $zero, $zero   # memory index
add      $t1, $zero, $zero   # is negative flag
lb       $t0, ($a0)
addi     $t8, $zero, 45 # 45 is a '-'
beq      $t0, $t8, Isneg
stringToIntLoop:
lb      $t0, ($a0)
beq     $t0, $zero, fixNeg 	# line feed
sll     $t2, $v0, 1 # this and next line calculated (n<<3) + (n<<1)
sll     $v0, $v0, 3 # which is same as multiplying by 10
add     $v0, $v0, $t2       
addi    $t0, $t0, -48 # convert to digit
add     $v0, $v0, $t0       
addi    $a0, $a0, 1         
j  stringToIntLoop
