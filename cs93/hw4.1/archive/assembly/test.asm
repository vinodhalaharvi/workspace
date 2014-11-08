	.text
main:
	jal 0x00000000
	nop
	lbu     $t0, 0xffff0000     # Read an I/O device
	sb      $t0, 0xffff0004     # Write to an I/O device
