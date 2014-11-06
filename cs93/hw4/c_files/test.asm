.data
	askFirstNumber: .asciiz "input First Number\n"
	askSecondNumber: .asciiz "input Second Number\n"
	firstNumber: .asciiz "       "
	secondNumber: .asciiz "       "
.text
	main:
	# ask for first number
	la   $a0, askFirstNumber
	jal  outputStringToDevice
	la   $a0, firstNumber
	jal inputStringFromDevice

	la   $a0, askSecondNumber
	jal outputStringToDevice
	la   $a0, secondNumber
	jal inputStringFromDevice

	la   $t0, firstNumber # first number argument in $a0
	jal stringToInt
	addi $a0, $t0, $zero

	la   $t1, firstNumber
	jal stringToInt
	addi $a1, $t1, $zero  # second number argument in $a1

	jal multiply # now call multiply, result in $a0
	jal signedDecimalToString # first argument is from $a0

	la $a0, outputString # result is stored here
	jal outputStringToDevice # output to device
