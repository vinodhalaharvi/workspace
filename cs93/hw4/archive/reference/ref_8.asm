str_enter_multiplicand:		.asciiz "\nPlease enter the multiplicand: "
str_enter_multiplier:		.asciiz "\nPlease enter the multiplier: "
str_print_00_info:		.asciiz "00, nop shift"
str_print_01_info:		.asciiz "01, add shift"
str_print_10_info:		.asciiz "10, subtract shift"
str_print_11_info:		.asciiz "11, nop shift"
str_print_result:		.asciiz "\n\nResult -> [concat(U, V) of Step=32]: "
str_loop_counter:		.asciiz "\nStep="
str_tab:			.asciiz "\t"
str_n:				.asciiz "N="
str_u:				.asciiz "U="
str_v:				.asciiz "V="
str_x:				.asciiz "X="
str_y:				.asciiz "Y="
str_x_1:			.asciiz "X-1="



# 	Syscall variables
#	-----------------
sys_print_int:			.word 1
sys_print_binary:		.word 35
sys_print_string:		.word 4
sys_read_int:			.word 5
sys_exit:			.word 10


# ====== TEXT SEGMENT ====== #
	.text
	.globl main
main:
	# initialize loop counter = 0, U=0, V=0, X-1=0, N=0
	addi $s0, $zero, 0
	addi $s3, $zero, 0
	addi $s4, $zero, 0
	addi $s5, $zero, 0
	addi $s6, $zero, 0

	# ask for multiplicand
	lw   $v0, sys_print_string
	la   $a0, str_enter_multiplicand
	syscall

	# get integer into $s1
	lw   $v0, sys_read_int
	syscall
	add  $s1, $zero, $v0

	# ask for multiplier
	lw   $v0, sys_print_string
	la   $a0, str_enter_multiplier
	syscall

	# get integer into $s2
	lw   $v0, sys_read_int
	syscall
	add  $s2, $zero, $v0


#	general looping part of the algorithm -print the results of the last step 
#	-------------------------------------------------------------------------

print_step:

	# check for the loop counter
	beq  $s0, 33, exit

	# "Step"
	lw   $v0, sys_print_string
	la   $a0, str_loop_counter
	syscall

	# Print step
	lw   $v0, sys_print_int
	add  $a0, $zero, $s0
	syscall
	lw   $v0, sys_print_string
	la   $a0, str_tab
	syscall

	# "N"
	lw   $v0, sys_print_string
	la   $a0, str_n
	syscall

	# Print N
	lw   $v0, sys_print_int
	add  $a0, $zero, $s6
	syscall
	lw   $v0, sys_print_string
	la   $a0, str_tab
	syscall

	# "U"
	lw   $v0, sys_print_string
	la   $a0, str_u
	syscall

	# Print U
	lw   $v0, sys_print_binary
	add  $a0, $zero, $s3
	syscall
	lw   $v0, sys_print_string
	la   $a0, str_tab
	syscall

	# "V"
	lw   $v0, sys_print_string
	la   $a0, str_v
	syscall

	# Print V
	lw   $v0, sys_print_binary
	add  $a0, $zero, $s4
	syscall
	lw   $v0, sys_print_string
	la   $a0, str_tab
	syscall

	# "X"
	lw   $v0, sys_print_string
	la   $a0, str_x
	syscall

	# Print X
	lw   $v0, sys_print_binary
	add  $a0, $zero, $s1
	syscall
	lw   $v0, sys_print_string
	la   $a0, str_tab
	syscall

	# "X-1"
	lw   $v0, sys_print_string
	la   $a0, str_x_1
	syscall

	# Print X-1
	lw   $v0, sys_print_int
	add  $a0, $zero, $s5
	syscall
	lw   $v0, sys_print_string
	la   $a0, str_tab
	syscall


#	evaluate the values of x-1 and lsb of x -branch according to them
#	-----------------------------------------------------------------
	
	andi $t0, $s1, 1		# $t0 = LSB of X
	beq  $t0, $zero, x_lsb_0	# if ($t0 == 0) then goto x_lsb_0
	j    x_lsb_1			# if ($t1 == 1) then goto x_lsb_1

x_lsb_0: 				# when the LSB of X = 0
	beq  $s5, $zero, case_00	# if (X-1 == 0) then goto case_00
	j    case_01			# if (X-1 == 1) then goto case_01

x_lsb_1:				# when the LSB of X = 1
	beq  $s5, $zero, case_10	# if (X-1 == 0) then goto case_10
	j    case_11			# if (X-1 == 1) then goto case_11

case_00:
	# print info about action
	lw   $v0, sys_print_string
	la   $a0, str_print_00_info
	syscall
	# do nothing, but shifting
	andi $s6, $s6, 0		# set N=0 anyway
	andi $t0, $s3, 1		# LSB of U for overflow checking
	bne  $t0, $zero, V		# if LSB of U not zero, goto V, i.e. U overflows
	srl  $s4, $s4, 1		# shift right logical V by 1-bit
	j    shift			# goto shift other variables

case_01:
	# print info about action
	lw   $v0, sys_print_string
	la   $a0, str_print_01_info
	syscall
	# do addition and shifting
	add  $s3, $s3, $s2		# add Y to U
	andi $s5, $s5, 0		# X=0, so next time X-1=0
	ori  $s6, $s6, 1		# X-1=1, so next time N=1
	andi $t0, $s3, 1		# LSB of U for overflow checking
	bne  $t0, $zero, V		# if LSB of U not zero, goto V, i.e. U overflows
	srl  $s4, $s4, 1		# shift right logical V by 1-bit
	j    shift			# goto shift other variables

case_10:
	# print info about action
	lw   $v0, sys_print_string
	la   $a0, str_print_10_info
	syscall
	# do subtract and shifting
	sub  $s3, $s3, $s2		# sub Y from U
	ori  $s5, $s5, 1		# X=1, so next time X-1=1
	andi $s6, $s6, 0		# X-1=0, so next time N=0
	andi $t0, $s3, 1		# LSB of U for overflow checking
	bne  $t0, $zero, V		# if LSB of U not zero, goto update V
	srl  $s4, $s4, 1		# shift right logical V by 1-bit
	j    shift			# goto shift other variables

case_11:
	# print info about action
	lw   $v0, sys_print_string
	la   $a0, str_print_11_info
	syscall
	# do nothing, but shifting
	ori  $s6, $s6, 1		# set N=1 anyway
	andi $t0, $s3, 1		# LSB of U for overflow checking
	bne  $t0, $zero, V		# if LSB of U not zero, goto update
	srl  $s4, $s4, 1		# shift right logical V by 1-bit
	j    shift 			# goto shift other variables

V:
	andi $t0, $s4, 0x80000000	# What is the MSB of V?
	bne  $t0, $zero, shiftV		# If MSB == 1, goto shiftV
	srl  $s4, $s4, 1		# MSB == 0, so first shift right logical V by 1-bit
	ori  $s4, $s4, 0x80000000	# then make MSB of V = 1
	j    shift			# goto shift other variables

shiftV:
	srl  $s4, $s4, 1		# shift right logical V by 1-bit
	ori  $s4, $s4, 0x80000000	# MSB 0f V = 1
	j    shift			# goto shift other variables

shift:
	sra  $s3, $s3, 1		# shift right arithmetic U by 1-bit
	ror  $s1, $s1, 1		# rotate right X by 1-bit
	addi $s0, $s0, 1		# decrement loop counter
	beq  $s0, 32, save		# if it is last step, save the contents of the regs for result
	j    print_step			# loop again

save:
	add  $t1, $zero, $s3		# save U in $t1
	add  $t2, $zero, $s4		# save V in $t2
	j    print_step			# loop again


#	exit -calculation completed, so print result
#	--------------------------------------------

exit:
	# Print result
	lw   $v0, sys_print_string
	la   $a0, str_print_result
	syscall
	
	# Call U
	lw   $v0, sys_print_binary
	add  $a0, $zero, $t1
	syscall
	# Call V
	lw   $v0, sys_print_binary
	add  $a0, $zero, $t2
	syscall
	
	# Exit
	lw   $v0, sys_exit
	syscall
