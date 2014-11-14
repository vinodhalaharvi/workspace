jal main
multiply:
        addi $sp, $sp, -60
        sw $s0, 24($sp)
        sw $s1, 28($sp)
        slt  $t4, $a0, $zero
        beq  $t4, $zero, skip1
        sub  $a0, $zero, $a0
        skip1:
        slt  $t5, $a1, $zero
        beq  $t5, $zero, skip2
        sub  $a1, $zero, $a1
        skip2:
        add $t0, $zero, $zero
        addi $v0, $zero, 0
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
                                beq $t5, $zero, skip4
                                sub  $v0, $zero, $v0
                                skip4:
                                        lw $s0, 24($sp)
                                        lw $s1, 28($sp)
                                        addi $sp, $sp, 60
                                        jr $ra
                label:
                        sllv $t3, $a0, $t0
                        add $v0, $v0, $t3
                        j back
        main:
                addi $a0, $zero, 2
                addi $a1, $zero, 3
                jal multiply
                
               
