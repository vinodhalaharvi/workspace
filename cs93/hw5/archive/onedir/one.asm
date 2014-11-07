./assembler /tmp/test.asm /tmp/test.mif
1: 
2: 
3: 
4: 
5: 
6: outputChar:
7: 	nop
8: 	loadControlWord:	
9: 		la $t1, REG_IOCONTROL 
10: 		lw $t0, ($t1) 
11: 		andi $t1, $t0, 0x2 
12: 		beq $t1, $0, loadControlWord 
13: 	writeAChar:
14: 		la $t1, REG_IOBUFFER_2
15: 		sh $v0 ($t1) 
16: 		jr $ra
17: 
18: 
19: inputChar:
20: 	nop
21: 	loadControlWord:	
22: 		la $t1, REG_IOCONTROL 
23: 		lw $t0, ($t1) 
24: 		andi $t1, $t0, 0x1 
25: 		beq $t1, $0, loadControlWord 
26: 	readAChar:
27: 		la $t1, REG_IOBUFFER_1
28: 		lhu $v0 ($t1) 
29: 		jr $ra
30: 
31: 
32: 
33: 
34: outputString:
35: 	ori $t0, $ra, $0 
36: 	loop: 
37: 		lb $v0, ($a0) 
38: 		beqz $v0, return 
39: 		jal outputChar 
40: 		addi $a0, $a0, 1 
41: 		j loop 
42: 	return:
43: 		jr $t0 
44: 
45: 
46: 
47: inputString:
48: 	ori $t0, $ra, $0 
49: 	ori $t1, $0, '\n' 
50: 	loop: 
51: 		jal inputChar 
52: 		beq $v0, $t1, return 
53: 		sb $v0, ($a0) 
54: 		addi $a0, $a0, 1 
55: 		j loop 
56: 	return:
57: 		sb 0x0, ($a0) 
58: 		jr $t0 
59: 
60: 
61: 
62: 
63: 
64: 
65: 
66: 
67: 
68: 
69: 
70: 
71: 
72: 
73: 
74: 
75: 
76: 
77: stringToInt:
78: 	add      $v0, $zero, $zero   
79: 	add      $t1, $zero, $zero   
80: 	lb       $t0, 0($a0)
81: 	beq      $t0, '-', .Isneg
82: 	.loop:
83: 		lb      $t0, 0($a0)
84: 		beq     $t0, 0, .fixNeg 	
85: 		sll     $t2, $v0, 1
86: 		sll     $v0, $v0, 3
87: 		add     $v0, $v0, $t2       
88: 		addi    $t0, $t0, -48
89: 		add     $v0, $v0, $t0       
90: 		addi    $a0, $a0, 1         
91: 		j   .loop
92: 	.Isneg:
93: 		addi     $t1, $zero, 1       
94: 		addi     $a0, $a0, 1
95: 		j .loop
96: 	.fixNeg:
97: 		beq     $t1, $zero, .result    
98: 		sub     $v0, $zero, $v0
99: 	.result:
100: 		jr      $ra       
101: 
102: 
103: multiply:
104: 	add $s0, $zero, $zero
105: 	add $t0, $zero, $zero
106: 	loop: 
107: 		srav  $t1, $a1, $t0
108: 		andi  $t2, $t1, 1
109: 		beq   $t2, 1 label 
110: 		back:
111: 			addi  $t0, $t0, 1
112: 			slti  $t8, $t0, 32
113: 			bne   $t8, $zero, loop	
114: 			j done 
115: 		label:
116: 			sllv $t3, $a0, $t0
117: 			add $v0, $v0, $t3
118: 			j back
119: 	jr $ra
120: 
121: 
122: 
