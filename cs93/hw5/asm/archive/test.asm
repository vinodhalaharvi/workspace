.data
        firstNumber:  .asciiz "-1112"
        secondNumber: .asciiz "1122"
.text
	jal main
        stringToInt:
                addi $sp, $sp, -60
		 # callee saved convention
                sw $s0, 24($sp)  
                add      $v0, $zero, $zero # memory index
                add      $t1, $zero, $zero # is negative flag
                lb       $t0, 0($a0)
                addi     $t8, $zero, 45 # 45 is a '-'
                beq      $t0, $t8, Isneg
                stringToIntLoop:
                        lb      $t0, 0($a0)
                        beq     $t0, $zero, fixNeg # line feed
                        sll     $t2, $v0, 1 # this and next line calculated (n<<3) + (n<<1)
                        sll     $v0, $v0, 3 # which is same as multiplying by 10
                        add     $v0, $v0, $t2       
                        addi    $t0, $t0, -48 # convert to digit
                        add     $v0, $v0, $t0       
                        addi    $a0, $a0, 1         
                        j  stringToIntLoop
                Isneg:
                        addi     $t1, $zero, 1 # set the negative flag
                        addi     $a0, $a0, 1
                        j stringToIntLoop
                fixNeg:
                        beq     $t1, $zero, result # if negative flag is set, reverse sign 
                        sub     $v0, $zero, $v0 # final output is in v0
		 # and return
                result:
                        lw  $s0, 24($sp)
                        addi $sp, $sp, 60
                        jr  $ra   
        main:
                # do work 
                # registers used are
                #
                #jal stringToIntTesting
                la $a0, firstNumber 
                jal stringToInt
                add $s0, $v0, $zero
                la $a0, secondNumber 
                jal stringToInt
                add $s1, $v0, $zero
                add $a0, $s0, $zero
                add $a1, $s1, $zero
                exitloop:
			nop
                        jal exitloop  
