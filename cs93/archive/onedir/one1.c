sll	000000	00000	rt	rd	sa	000000 
(
	(get(num,31,26)==0)&&	
	(get(num,25,21)==0)&&
	(get(num,5,0)==0) &&
	(res = sll(get(num, 16, 20),  get(num, 11, 15),  get(num, 6, 10)))
) return "sll"; 


srl	000000	00000	rt	rd	sa	000010
(
	(get (num, 31, 26) == 0 ) &&	
	(get (num, 25, 21) == 0 ) &&
	(get (num, 5, 0) == 2 )
	(res = srl(get(num, 16, 20),  get(num, 11, 15),  get(num, 6, 10)))
)  

sra	000000	00000	rt	rd	sa	000011
(
	(get (num, 31, 26) == 0 ) &&	
	(get (num, 25, 21) == 0 ) &&
	(get (num, 5, 0) == 3 )
	(res = sra(get(num, 16, 20),  get(num, 11, 15),  get(num, 6, 10)))
)

sllv	000000	rs	rt	rd	00000	000100
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = sllv(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

srlv	000000	rs	rt	rd	00000	000110
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = srlv(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)


srav	000000	rs	rt	rd	00000	000111
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = srav(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

jr	000000	rs	000000000000000	001000

jalr	000000	rs	00000	rd	00000	001001
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 20, 16) == 0 ) &&
	(get (num, 20, 16) == 0 ) &&
	(res = jalr(get(num, 21, 25), get(num, 11, 15)))
)

add	000000	rs	rt	rd	00000	100000
(
	(get (num, 20, 16) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = add(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))

)

addu	000000	rs	rt	rd	00000	100001
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = addu(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

sub	000000	rs	rt	rd	00000	100010
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = sub(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

subu	000000	rs	rt	rd	00000	100011
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = subu(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

and	000000	rs	rt	rd	00000	100100
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = and(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

or	000000	rs	rt	rd	00000	100101
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = or(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

xor	000000	rs	rt	rd	00000	100110
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = xor(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

nor	000000	rs	rt	rd	00000	100111
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = nor(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

slt	000000	rs	rt	rd	00000	101010
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = slt(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

sltu	000000	rs	rt	rd	00000	101011
(
	(get (num, 31, 26) == 0 ) &&
	(get (num, 10, 6) == 0 ) &&
	(res = sltu(get(num, 21, 25),  get(num, 16, 20),  get(num, 11, 15)))
)

j	000010	inst_index
(
	(get (num, 31, 26) == 0 ) &&
	(res = sltu(get(num, 25, 0)))
)

jal	000011	inst_index
(
	(get (num, 31, 26) == 3 ) && 
	(res = jal(get(num, 25, 0)))
)

beq	000100	rs	rt	offset
(
	(get (num, 31, 26) == 4 ) && 
)

bne	000101	rs	rt	offset	
(
	(get (num, 31, 26) == 5 ) && 
)


blez	000110	rs	00000	offset	
(
	(get (num, 31, 26) == 6 ) && 
	(get (num, 20, 16) == 0 ) &&
)

bgtz	000111	rs	00000	offset	
(
	(get (num, 31, 26) == 7 ) && 
	(get (num, 20, 16) == 0 ) &&
)

addi	001000	rs	rt	imm
(
	(get (num, 31, 26) == 8 ) && 
)

addiu	001001	rs	rt	imm
(
	(get (num, 31, 26) == 9 ) && 
)

slti	001010	rs	rt	imm
(
	(get (num, 31, 26) == 10 ) && 
)


sltiu	001011	rs	rt	imm
(
	(get (num, 31, 26) == 11 ) && 
)

andi	001100	rs	rt	imm
(
	(get (num, 31, 26) == 12 ) && 
)

ori	001101	rs	rt	imm
(
	(get (num, 31, 26) == 13 ) && 
)

xori	001110	rs	rt	imm
(
	(get (num, 31, 26) == 14 ) && 
)

lui	001111	00000	rt	imm
(
	(get (num, 31, 26) == 15 ) && 
)


lb	100000	base	rt	offset	
(
	(get (num, 31, 26) == 32 ) && 
)

lh	100001	base	rt	offset	
(
	(get (num, 31, 26) == 33 ) && 
)

lwl	100010	base	rt	offset	
(
	(get (num, 31, 26) == 34 ) && 
)


lw	100011	base	rt	offset	
(
	(get (num, 31, 26) == 35 ) && 
)

lbu	100100	base	rt	offset	
(
	(get (num, 31, 26) == 36 ) && 
)

lhu	100101	base	rt	offset	
(
	(get (num, 31, 26) == 37 ) && 
)

lwr	100110	base	rt	offset	
(
	(get (num, 31, 26) == 38 ) && 
)

sb	101000	base	rt	offset	
(
	(get (num, 31, 26) == 40 ) && 
)

sh	101001	base	rt	offset	
(
	(get (num, 31, 26) == 41 ) && 
)

sw	101010	base	rt	offset	
(
	(get (num, 31, 26) == 42 ) && 
)

swl	101011	base	rt	offset	
(
	(get (num, 31, 26) == 43 ) && 
)

swr	101110	base	rt	offset	
(
	(get (num, 31, 26) == 46 ) && 
)

bgez	000001	rs	00001	offset	
(
	(get (num, 31, 26) == 1 ) &&
	(get (num, 20, 16) == 1 ) && 
)

bgezal	000001	rs	10001	offset	
(
	(get (num, 31, 26) == 1 ) &&
	(get (num, 20, 16) == 17 ) && 
)

bltz	000001	rs	00000	offset	
(
	(get (num, 31, 26) == 1 ) &&
	(get (num, 20, 16) == 0 ) && 
)

bltzal	000001	rs	10000	offset	
(
	(get (num, 31, 26) == 1 ) &&
	(get (num, 20, 16) == 16 ) &&
)

