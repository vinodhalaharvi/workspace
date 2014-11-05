#la is equivalent to 
#lui $t1, REG_IOCONTROL # $t1 <- REG_IOCONTROL
#lhu $t0, ($t1) # $t0 <- loadHalf($t1) (load unsigned)
# prob2
.data
	outputString: .asciiz "            \n"
.text
outputChar:
	nop
	checkOutputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, ($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 0x2 # $t1 <- is the bit 1 of $t0 set ? 
		beq $t1, $0, checkOutputReady # if not then busy wait
	writeAChar:
		la $t1, REG_IOBUFFER_2
		sh $v0 ($t1) # store $a0 to REG_IOBUFFER_2
		jr $ra
# prob3
inputChar:
	nop
	checkInputReady:	
		la $t1, REG_IOCONTROL # t1 <- REG_IOCONTROL address
		lw $t0, ($t1) # $t0 <- loadWord($t1) 
		andi $t1, $t0, 0x1 # $t1 <- is the bit 0 of $t0 set ? 
		beq $t1, $0, checkInputReady # if not then busy wait
	readAChar:
		la $t1, REG_IOBUFFER_1
		lhu $v0 ($t1) # store $a0 to REG_IOBUFFER_2
		jr $ra
# prob4
# $a0 has location of the null terminated string to output
outputStringToDevice:
	ori $t0, $ra, $0 # store the return value
	loop1: 
		lb $v0, ($a0) # $a0 has location of string
		beq $v0, $zero, return1 # if '\0' then return
		jal outputChar # output a character
		addi $a0, $a0, 1 # increament location
		j loop1 # loop again
	return1:
		jr $t0 # return to caller
# prob5
# Store the input string at location $a0 and null terminate it
inputStringFromDevice:
	ori $t0, $ra, $0 # store the return value	
	ori $t1, $0, '\n' # line-feed
	loop2: 
		jal inputChar # Wait for character input
		beq $v0, $t1, return2 # if line-feed return
		sb $v0, ($a0) # store the char read to memory
		addi $a0, $a0, 1 # increament location
		j loop2 # loop again
	return2:
		sb $zero ($a0) # store '\0' to null terminate string
		jr $t0 # return to caller
#prob6
# $a0 <- $a0
mul10:
	sll $t0, $a0, 3
	sll $t1, $a0, 1 
	add $t0, $t0, $t1
	add $a0, $t0, $zero
	jr $ra
	
# $a0 <- $a0
div10:
	addi $a1, $zero, 0x1999
	add $s0, $ra, $zero
	jal multiply
	srl $a0, $a0, 16
	add $ra, $s0, $zero
	jr $ra

# $a0 <- $a0
toChar:
	addi $a0, $a0, 48
	jr $ra

# $a0 <- $a0
toDigit:
	addi $a0, $a0, -48 
	jr $ra

# a1 <-  changed
storeOutput:
	la $a1, outputString
	sb $a0 ($a1)
	jr $ra
main:
	addi $a0, $zero, 8989
	loop3:	
		beq $a0, $zero, exit
		add $s1, $a0, $zero
		jal div10
		jal mul10
		sub $a0, $s1, $a0
		add $a0, $s1, $zero
		jal div10
		j loop3
	exit:
		#jal printIntAndExit
		nop
		j exit
# prob7
stringToInt:
	add      $v0, $zero, $zero   # memory index
	add      $t1, $zero, $zero   # is negative flag
	lb       $t0, ($a0)
	addi     $s6, $zero, 45 # 45 is a '-'
	beq      $t0, $s6, Isneg
	loop4:
		lb      $t0, ($a0)
		beq     $t0, $zero, fixNeg 	# line feed
		sll     $t2, $v0, 1
		sll     $v0, $v0, 3
		add     $v0, $v0, $t2       
		addi    $t0, $t0, -48
		add     $v0, $v0, $t0       
		addi    $a0, $a0, 1         
		j   loop4
	Isneg:
		addi     $t1, $zero, 1       # set the negative flag
		addi     $a0, $a0, 1
		j loop4
	fixNeg:
		beq     $t1, $zero, result    
		sub     $v0, $zero, $v0
	result:
		jr      $ra       
# prob8
# $a0 <- $a0, $a1 
multiply:
	slt  $t4, $a0, $zero
	beq  $t4, $zero, skip1
	sub  $a0, $zero, $a0 # flip sign 
	skip1:
	slt  $t5, $a1, $zero
	beq  $t5, $zero, skip2
	sub  $a1, $zero, $a1 # flip sign 
	skip2:
	add $t0, $zero, $zero
	loop: 
		srav  $t1, $a1, $t0
		andi  $t2, $t1, 1
		addi  $t1, $zero, 1
		beq   $t2, $t1 label 
		back:
			addi  $t0, $t0, 1
			slti  $t8, $t0, 32
			bne   $t8, $zero, loop	
			add $a0, $v0, $zero

			# fix sign before returning
			beq $t4, $zero, skip3
			sub  $a0, $zero, $a0 # flip sign 

			skip3:
			beq $t5, $zero, skip4
			sub  $a0, $zero, $a0 # flip sign 

			skip4:
			jr $ra
		label:
			sllv $t3, $a0, $t0
			add $v0, $v0, $t3
			j back
	jr $ra

# prob9

