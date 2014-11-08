import re
(REGISTER, IMMEDIATE , JUMP)  = (0, 1, 2)
(ALU, OTHER)  = (0, 1)


# DONE AND CORRECT
instNameToALUFunctionMap={
	"sll": "000000",
	"srl": "000010",
	"sra": "000011",
	"sllv": "000100",
	"srlv": "000110",
	"srav": "000111",
	"jr": "001000",
	"jalr": "001001",
	"syscall": "001100",
	"break": "001101",
	"mfhi": "010000",
	"mthi": "010001",
	"mflo": "010010",
	"mtlo": "010011",
	"mult": "011000",
	"multu": "011001",
	"div": "011010",
	"divu": "011011",
	"add": "100000",
	"addu": "100001",
	"sub": "100010",
	"subu": "100011",
	"and": "100100",
	"or": "100101",
	"xor": "100110",
	"nor": "100111",
	"slt": "101010",
	"sltu": "101011",
}

instNameToSubTypeMap = {
	"add": ALU,
	"addu": ALU,
	"and": ALU,
	"break": ALU,
	"div": ALU,
	"divu": ALU,
	"jalr": ALU,
	"jr": ALU,
	"mfhi": ALU,
	"mflo": ALU,
	"mthi": ALU,
	"mtlo": ALU,
	"mult": ALU,
	"multu": ALU,
	"nor": ALU,
	"or": ALU,
	"sll": ALU,
	"sllv": ALU,
	"sra": ALU,
	"srav": ALU,
	"srl": ALU,
	"srlv": ALU,
	"sub": ALU,
	"subu": ALU,
	"syscall": ALU,
	"xor": ALU,
}



instNameToTypeMap = {
	"addiu": IMMEDIATE,
	"andi": IMMEDIATE,
	"divu": REGISTER,
	"multu": REGISTER,
	"nor":  REGISTER,
	"or":  REGISTER,
	"ori":  IMMEDIATE,
	"sll":  REGISTER,
	"sllv": REGISTER,
	"sra":  REGISTER,
	"srav": REGISTER,
	"srl":  REGISTER,
	"srlv": REGISTER,
	"subu": REGISTER,
	"xor":  REGISTER,
	"xori": IMMEDIATE,
	"lui": IMMEDIATE,
	"sltu":  REGISTER,
	"sltiu": IMMEDIATE,
	"bczt": IMMEDIATE,
	"bczf": IMMEDIATE,
	"beq": IMMEDIATE,
	"bgez": IMMEDIATE,
	"bgezal": IMMEDIATE,
	"bgtz": IMMEDIATE,
	"blez": IMMEDIATE,
	"bgezal": IMMEDIATE,
	"bltzal": IMMEDIATE,
	"bltz": IMMEDIATE,
	"bne":  IMMEDIATE,
	"j":  JUMP,
	"jal":  JUMP,
	"jalr": REGISTER,
	"jr": REGISTER,
	"lb": IMMEDIATE,
	"lbu": IMMEDIATE,
	"lh": IMMEDIATE,
	"lhu": IMMEDIATE,
	"lw": IMMEDIATE,
	"lwcz": IMMEDIATE,
	"lwl": IMMEDIATE,
	"lwr": IMMEDIATE,
	"sb": IMMEDIATE,
	"sh": IMMEDIATE,
	"sw": IMMEDIATE,
	"swcz": IMMEDIATE,
	"swl": IMMEDIATE,
	"swr": IMMEDIATE,
	"mfhi": REGISTER,
	"mflo": REGISTER,
}

registerEncodingMap = {
	"$0": "00000",
	"$1": "00001",
	"$2": "00010",
	"$3": "00011",
	"$4": "00100",
	"$5": "00101",
	"$6": "00110",
	"$7": "00111",
	"$8": "01000",
	"$9": "01001",
	"$10": "01010",
	"$11": "01011",
	"$12": "01100",
	"$13": "01101",
	"$14": "01110",
	"$15": "01111",
	"$16": "10000",
	"$17": "10001",
	"$18": "10010",
	"$19": "10011",
	"$20": "10100",
	"$21": "10101",
	"$22": "10110",
	"$23": "10111",
	"$24": "11000",
	"$25": "11001",
	"$26": "11010",
	"$27": "11011",
	"$28": "11100",
	"$29": "11101",
	"$30": "11110",
	"$31": "11111",
}

def getRegisterBits(register):
	"""docstring for getRegisterEncodinggisiterE"""
	return registerEncodingMap[register]


# DONE AND CORRECT
instNameToOpCodeMap = {
	"special": "000000",
	"regimm": "000001",
	"j": "000010",
	"jal": "000011",
	"beq": "000100",
	"bne": "000101",
	"blez": "000110",
	"bgtz": "000111",
	"addi": "001000",
	"addiu": "001001",
	"slti": "001010",
	"sltiu": "001011",
	"andi": "001100",
	"ori": "001101",
	"xori": "001110",
	"lui": "001111",
	"beql": "010100",
	"bnel": "010101",
	"blezl": "010110",
	"bgtzl": "010111",
	"lb": "100000",
	"lh": "100001",
	"lwl": "100010",
	"lwl": "100011",
	"lbu": "100100",
	"lhu": "100101",
	"lwr": "100110",
	"sb": "101000",
	"sh": "101001",
	"swl": "101010",
	"swl": "101011",
	"swr": "101110",
}



def getOpcodeBits(instString):
	"""docstring for getOpcodeBits"""
	return instNameToOpCodeMap[instString]

def getInstType(instName):
	"""docstring for getInstType"""
	return  instNameToTypeMap[instName]

def getInstSubType(instName):
	"""docstring for getInstType"""
	return  instNameToSubTypeMap.get(instName, OTHER)

def getALUFunctionBits(instName):
	"""docstring for getALUFunctionBits"""
	#TODO
	return instNameToALUFunctionMap.get(instName, "00000") 


def getBits(instName, op1, op2, op3):
	"""docstring for getBits"""
	IRWord = ""
	instructionType = getInstType(instName)
	if (instructionType == REGISTER):
		instructionSubType = getInstSubType(instName)
		if instructionSubType == ALU:
			IRWord += "000000" # 6 bits
		else:
			IRWord += getOpcodeBits(instName) # 6 bits
		IRWord += " "
		IRWord += getRegisterBits(op1) #5 bits
		IRWord += " "
		IRWord += getRegisterBits(op2) #5 bits
		IRWord += " "
		IRWord += getRegisterBits(op3) #5 bits
		IRWord += " "
		IRWord += "00000" # shamt bits which are all zeros
		IRWord += " "
		if(instructionSubType == ALU):
			IRWord += getALUFunctionBits(instName) # 5 bits
		else:
			IRWord += "00000" # 5 bits
		IRWord += " "
		print IRWord
	elif instructionType == IMMEDIATE:
		print "Not implemented yet"
	elif instructionType == JUMP:
		print "Not implemented yet"
	else: 
		print "UNKNOWN Instruction!!!"

if __name__ == '__main__':
	instString = "add $1, $2, $3"
	#instString = "ori $1, $2, %AB"
	tokens =  [term for term in  re.split("[, ]", instString) if term]
	print getBits(tokens[0], tokens[1], tokens[2], tokens[3])
