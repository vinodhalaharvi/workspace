Vinod Halaharvi

# How to run
make clean 
make run 

Please check prob.asm file for all  assembly programs from 2 - 9 

# limitations 
1) No proper memory management. Memory is allocated  but not free-d. 
Since our programs are small we don't have to worry about memory leaks for this problem set. 
This will be taken care off during problem set 5 submission.

2) There are some function that says "not implemented yet". I am not sure if I will be needing those instructions in the future ? So I have left a place holder for those functions. These will be clean up during problem set 5 submission.


# output of sample run
make clean 
rm -f *.o
rm assembler
make run
gcc -Wno-unused-variable -Wall -ggdb -std=gnu99   -c -o lib.o lib.c   
gcc -Wno-unused-variable -Wall -ggdb -std=gnu99   -c -o command.o command.c   
gcc -Wno-unused-variable -Wall -ggdb -std=gnu99   -c -o assembler.o assembler.c   
gcc   lib.o command.o assembler.o   -o assembler 
./assembler ./prob.asm ./prob.mif | less

symbol table contents:
main=0x0
REG_IOCONTROL=0x7f80
REG_IOBUFFER_1=0x7f82
REG_IOBUFFER_2=0x7f84
STACK_BASE=0x2f84
outputString=0x2f84
outputChar=0x2
checkOutputReady=0x4
writeAChar=0xc
inputChar=0x12
checkInputReady=0x14
readAChar=0x1c
outputStringToDevice=0x22
loop1=0x24
return1=0x2e
inputStringFromDevice=0x30
loop2=0x34
return2=0x3e
mul10=0x42
div10=0x4c
toChar=0x58
toDigit=0x5c
storeOutput=0x60
signedDecimalToString=0x66
loop3=0x66
exit=0x76
stringToInt=0x7a
loop4=0x84
Isneg=0x96
fixNeg=0x9c
result=0xa0
multiply=0xa2
skip1=0xa8
skip2=0xae
loop=0xb0
back=0xb8
skip3=0xc4
skip4=0xc8
label=0xca
askFirstNumber=0x2f92
askSecondNumber=0x2fa6
firstNumber=0x2fbb
secondNumber=0x2fc2

Helpful for debugging ..
10:	nop :0x0:0x0:0x0
12:		la $t1, REG_IOCONTROL :0x35290080:0x3529:0x80
13:		lw $t0, ($t1) :0x0:0x0:0x7FF9
14:		andi $t1, $t0, 0x2 :0x31280000:0x3128:0x0
15:		beq $t1, $0, checkOutputReady :0x1120000C:0x1120:0xC
17:		la $t1, REG_IOBUFFER_2:0x35290084:0x3529:0x84
18:		sh $v0 ($t1) :0xA5227FF9:0xA522:0x7FF9
19:		jr $ra:0x3E00008:0x3E0:0x8
22:	nop:0x0:0x0:0x0
24:		la $t1, REG_IOCONTROL :0x35290080:0x3529:0x80
25:		lw $t0, ($t1) :0x0:0x0:0x7FF9
26:		andi $t1, $t0, 0x1 :0x31280000:0x3128:0x0
27:		beq $t1, $0, checkInputReady :0x1120000C:0x1120:0xC
29:		la $t1, REG_IOBUFFER_1:0x35290082:0x3529:0x82
30:		lhu $v0 ($t1) :0x95227FF9:0x9522:0x7FF9
31:		jr $ra:0x3E00008:0x3E0:0x8
35:	ori $t0, $ra, $0 :0x351F0000:0x351F:0x0
37:		lb $v0, ($a0) :0x90827FF9:0x9082:0x7FF9
38:		beq $v0, $zero, return1 :0x1040002E:0x1040:0x2E
39:		jal outputChar :0xC000002:0xC00:0x2
40:		addi $a0, $a0, 1 :0x24840001:0x2484:0x1
41:		j loop1 :0x8000024:0x800:0x24
43:		jr $t0 :0x1000008:0x100:0x8
47:	ori $t0, $ra, $0 :0x351F0000:0x351F:0x0
48:	ori $t1, $0, '\n' :0x35200000:0x3520:0x0
50:		jal inputChar :0xC000012:0xC00:0x12
51:		beq $v0, $t1, return2 :0x1049003E:0x1049:0x3E
52:		sb $v0, ($a0) :0xA0827FF9:0xA082:0x7FF9
53:		addi $a0, $a0, 1 :0x24840001:0x2484:0x1
54:		j loop2 :0x8000034:0x800:0x34
56:		sb $zero ($a0) :0xA0807FF9:0xA080:0x7FF9
57:		jr $t0 :0x1000008:0x100:0x8
61:	sll $t0, $a0, 3 :0x820C0:0x8:0x20C0
62:	sll $t1, $a0, 1 :0x92040:0x9:0x2040
63:	add $t0, $t0, $t1 :0x1284021:0x128:0x4021
64:	add $a0, $t0, $zero:0x82021:0x8:0x2021
65:	jr $ra:0x3E00008:0x3E0:0x8
69:	addi $a1, $zero, 0x1999 :0x24A00000:0x24A0:0x0
70:	add $s0, $ra, $zero :0x1F8021:0x1F:0x8021
71:	jal multiply :0xC0000A2:0xC00:0xA2
72:	srl $a0, $a0, 16 :0x42402:0x4:0x2402
73:	add $ra, $s0, $zero:0x10F821:0x10:0xF821
74:	jr $ra:0x3E00008:0x3E0:0x8
78:	addi $a0, $a0, 48 :0x24840030:0x2484:0x30
79:	jr $ra:0x3E00008:0x3E0:0x8
83:	addi $a0, $a0, -48  :0x2484FFD0:0x2484:0xFFD0
84:	jr $ra:0x3E00008:0x3E0:0x8
88:	la $a1, outputString :0x34A50084:0x34A5:0x84
89:	sb $a0 ($a1):0xA0A47FF9:0xA0A4:0x7FF9
90:	jr $ra:0x3E00008:0x3E0:0x8
96:		beq $a0, $zero, exit:0x1080000E:0x1080:0xE
97:		add $s1, $a0, $zero:0x48821:0x4:0x8821
98:		jal div10  :0xC00000D:0xC00:0xD
99:		jal mul10:0xC000042:0xC00:0x42
100:		sub $a0, $s1, $a0 :0x912022:0x91:0x2022
101:		add $a0, $s1, $zero :0x112021:0x11:0x2021
102:		jal div10 :0xC00000D:0xC00:0xD
103:		j loop3   :0x8000066:0x800:0x66
105:		jal storeOutput :0xC000060:0xC00:0x60
106:		jr $ra:0x3E00008:0x3E0:0x8
110:	add      $v0, $zero, $zero   :0x1021:0x0:0x1021
111:	add      $t1, $zero, $zero   :0x4821:0x0:0x4821
112:	lb       $t0, ($a0):0x90887FF9:0x9088:0x7FF9
113:	addi     $s6, $zero, 45 :0x26C0002D:0x26C0:0x2D
114:	beq      $t0, $s6, Isneg:0x11160096:0x1116:0x96
116:		lb      $t0, ($a0):0x90887FF9:0x9088:0x7FF9
117:		beq     $t0, $zero, fixNeg 	:0x1100000F:0x1100:0xF
118:		sll     $t2, $v0, 1 :0xA1040:0xA:0x1040
119:		sll     $v0, $v0, 3 :0x210C0:0x2:0x10C0
120:		add     $v0, $v0, $t2       :0x1421021:0x142:0x1021
121:		addi    $t0, $t0, -48 :0x2508FFD0:0x2508:0xFFD0
122:		add     $v0, $v0, $t0       :0x1021021:0x102:0x1021
123:		addi    $a0, $a0, 1         :0x24840001:0x2484:0x1
124:		j   loop4:0x8000084:0x800:0x84
126:		addi     $t1, $zero, 1       :0x25200001:0x2520:0x1
127:		addi     $a0, $a0, 1:0x24840001:0x2484:0x1
128:		j loop4:0x8000084:0x800:0x84
130:		beq     $t1, $zero, result   :0x112000A0:0x1120:0xA0
131:		sub     $v0, $zero, $v0 :0x401022:0x40:0x1022
133:		jr      $ra       :0x3E00008:0x3E0:0x8
137:	slt  $t4, $a0, $zero :0x4602B:0x4:0x602B
138:	beq  $t4, $zero, skip1:0x118000A8:0x1180:0xA8
139:	sub  $a0, $zero, $a0 :0x802022:0x80:0x2022
141:	slt  $t5, $a1, $zero :0x5682B:0x5:0x682B
142:	beq  $t5, $zero, skip2:0x11A000AE:0x11A0:0xAE
143:	sub  $a1, $zero, $a1 :0xA02822:0xA0:0x2822
145:	add $t0, $zero, $zero:0x4021:0x0:0x4021
147:		srav  $t1, $a1, $t0 :0x1254007:0x125:0x4007
148:		andi  $t2, $t1, 1:0x31490001:0x3149:0x1
149:		addi  $t1, $zero, 1:0x25200001:0x2520:0x1
150:		beq   $t2, $t1 label :0x114900CA:0x1149:0xCA
152:			addi  $t0, $t0, 1:0x25080001:0x2508:0x1
153:			slti  $t8, $t0, 32 :0x2F080020:0x2F08:0x20
154:			bne   $t8, $zero, loop	:0x170000B0:0x1700:0xB0
155:			add $a0, $v0, $zero:0x22021:0x2:0x2021
158:			beq $t4, $zero, skip3 :0x118000C4:0x1180:0xC4
159:			sub  $a0, $zero, $a0 :0x802022:0x80:0x2022
162:			beq $t5, $zero, skip4 :0x11A000C8:0x11A0:0xC8
163:			sub  $a0, $zero, $a0 :0x802022:0x80:0x2022
166:			jr $ra:0x3E00008:0x3E0:0x8
168:			sllv $t3, $a0, $t0 :0x1045804:0x104:0x5804
169:			add $v0, $v0, $t3 :0x1621021:0x162:0x1021
170:			j back:0x8000BAC:0x800:0xBAC
171:	jr $ra:0x3E00008:0x3E0:0x8
182:	la   $a0, askFirstNumber:0x3484000A:0x3484:0xA
183:	jal  outputStringToDevice:0xC000022:0xC00:0x22
184:	la   $a0, firstNumber:0x3484000F:0x3484:0xF
185:	jal inputStringFromDevice:0xC000030:0xC00:0x30
187:	la   $a0, askSecondNumber:0x3484000A:0x3484:0xA
188:	jal outputStringToDevice:0xC000022:0xC00:0x22
189:	la   $a0, secondNumber:0x348400C2:0x3484:0xC2
190:	jal inputStringFromDevice:0xC000030:0xC00:0x30
192:	la   $t0, firstNumber :0x3508000F:0x3508:0xF
193:	jal stringToInt:0xC00007A:0xC00:0x7A
194:	addi $a0, $t0, $zero:0x24880000:0x2488:0x0
196:	la   $t1, firstNumber:0x3529000F:0x3529:0xF
197:	jal stringToInt:0xC00007A:0xC00:0x7A
198:	addi $a1, $t1, $zero  :0x24A90000:0x24A9:0x0
200:	jal multiply :0xC0000A2:0xC00:0xA2
201:	jal signedDecimalToString :0xC000066:0xC00:0x66
203:	la $a0, outputString :0x34840084:0x3484:0x84
204:	jal outputStringToDevice :0xC000022:0xC00:0x22


The output has been written to ./prob.mif file .. 



# output of sample mif file
##

WIDTH=16;
DEPTH=32768;

ADDRESS_RADIX=HEX;
DATA_RADIX=HEX;

CONTENT BEGIN
  0000: 0000;
  0001: 0000;
  0002: 007F;
  0003: 3C09;
  0004: 0080;
  0005: 3529;
  0006: 7FF9;
  0007: 0000;
  0008: 0000;
  0009: 3128;
  000A: 000C;
  000B: 1120;
  000C: 007F;
  000D: 3C09;
  000E: 0084;
  000F: 3529;
  0010: 7FF9;
  0011: A522;
  0012: 0008;
  0013: 03E0;
  0014: 0000;
  0015: 0000;
  0016: 007F;
  0017: 3C09;
  0018: 0080;
  0019: 3529;
  001A: 7FF9;
  001B: 0000;
  001C: 0000;
  001D: 3128;
  001E: 000C;
  001F: 1120;
  0020: 007F;
  0021: 3C09;
  0022: 0082;
  0023: 3529;
  0024: 7FF9;
  0025: 9522;
  0026: 0008;
  0027: 03E0;
  0028: 0000;
  0029: 351F;
  002A: 7FF9;
  002B: 9082;
  002C: 002E;
  002D: 1040;
  002E: 0002;
  002F: 0C00;
  0030: 0001;
  0031: 2484;
  0032: 0024;
  0033: 0800;
  0034: 0008;
  0035: 0100;
  0036: 0000;
  0037: 351F;
  0038: 0000;
  0039: 3520;
  003A: 0012;
  003B: 0C00;
  003C: 003E;
  003D: 1049;
  003E: 7FF9;
  003F: A082;
  0040: 0001;
  0041: 2484;
  0042: 0034;
  0043: 0800;
  0044: 7FF9;
  0045: A080;
  0046: 0008;
  0047: 0100;
  0048: 20C0;
  0049: 0008;
  004A: 2040;
  004B: 0009;
  004C: 4021;
  004D: 0128;
  004E: 2021;
  004F: 0008;
  0050: 0008;
  0051: 03E0;
  0052: 0000;
  0053: 24A0;
  0054: 8021;
  0055: 001F;
  0056: 00A2;
  0057: 0C00;
  0058: 2402;
  0059: 0004;
  005A: F821;
  005B: 0010;
  005C: 0008;
  005D: 03E0;
  005E: 0030;
  005F: 2484;
  0060: 0008;
  0061: 03E0;
  0062: FFD0;
  0063: 2484;
  0064: 0008;
  0065: 03E0;
  0066: 002F;
  0067: 3C05;
  0068: 0084;
  0069: 34A5;
  006A: 7FF9;
  006B: A0A4;
  006C: 0008;
  006D: 03E0;
  006E: 000E;
  006F: 1080;
  0070: 8821;
  0071: 0004;
  0072: 000D;
  0073: 0C00;
  0074: 0042;
  0075: 0C00;
  0076: 2022;
  0077: 0091;
  0078: 2021;
  0079: 0011;
  007A: 000D;
  007B: 0C00;
  007C: 0066;
  007D: 0800;
  007E: 0060;
  007F: 0C00;
  0080: 0008;
  0081: 03E0;
  0082: 1021;
  0083: 0000;
  0084: 4821;
  0085: 0000;
  0086: 7FF9;
  0087: 9088;
  0088: 002D;
  0089: 26C0;
  008A: 0096;
  008B: 1116;
  008C: 7FF9;
  008D: 9088;
  008E: 000F;
  008F: 1100;
  0090: 1040;
  0091: 000A;
  0092: 10C0;
  0093: 0002;
  0094: 1021;
  0095: 0142;
  0096: FFD0;
  0097: 2508;
  0098: 1021;
  0099: 0102;
  009A: 0001;
  009B: 2484;
  009C: 0084;
  009D: 0800;
  009E: 0001;
  009F: 2520;
  00A0: 0001;
  00A1: 2484;
  00A2: 0084;
  00A3: 0800;
  00A4: 00A0;
  00A5: 1120;
  00A6: 1022;
  00A7: 0040;
  00A8: 0008;
  00A9: 03E0;
  00AA: 602B;
  00AB: 0004;
  00AC: 00A8;
  00AD: 1180;
  00AE: 2022;
  00AF: 0080;
  00B0: 682B;
  00B1: 0005;
  00B2: 00AE;
  00B3: 11A0;
  00B4: 2822;
  00B5: 00A0;
  00B6: 4021;
  00B7: 0000;
  00B8: 4007;
  00B9: 0125;
  00BA: 0001;
  00BB: 3149;
  00BC: 0001;
  00BD: 2520;
  00BE: 00CA;
  00BF: 1149;
  00C0: 0001;
  00C1: 2508;
  00C2: 0020;
  00C3: 2F08;
  00C4: 00B0;
  00C5: 1700;
  00C6: 2021;
  00C7: 0002;
  00C8: 00C4;
  00C9: 1180;
  00CA: 2022;
  00CB: 0080;
  00CC: 00C8;
  00CD: 11A0;
  00CE: 2022;
  00CF: 0080;
  00D0: 0008;
  00D1: 03E0;
  00D2: 5804;
  00D3: 0104;
  00D4: 1021;
  00D5: 0162;
  00D6: 0BAC;
  00D7: 0800;
  00D8: 0008;
  00D9: 03E0;
  00DA: 0000;
  00DB: 3C04;
  00DC: 000A;
  00DD: 3484;
  00DE: 0022;
  00DF: 0C00;
  00E0: 0000;
  00E1: 3C04;
  00E2: 000F;
  00E3: 3484;
  00E4: 0030;
  00E5: 0C00;
  00E6: 0000;
  00E7: 3C04;
  00E8: 000A;
  00E9: 3484;
  00EA: 0022;
  00EB: 0C00;
  00EC: 002F;
  00ED: 3C04;
  00EE: 00C2;
  00EF: 3484;
  00F0: 0030;
  00F1: 0C00;
  00F2: 0000;
  00F3: 3C08;
  00F4: 000F;
  00F5: 3508;
  00F6: 007A;
  00F7: 0C00;
  00F8: 0000;
  00F9: 2488;
  00FA: 0000;
  00FB: 3C09;
  00FC: 000F;
  00FD: 3529;
  00FE: 007A;
  00FF: 0C00;
  0100: 0000;
  0101: 24A9;
  0102: 00A2;
  0103: 0C00;
  0104: 0066;
  0105: 0C00;
  0106: 002F;
  0107: 3C04;
  0108: 0084;
  0109: 3484;
  010A: 0022;
  010B: 0C00;
END;
