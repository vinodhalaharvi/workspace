signal PC : IMem_addr;
alias IR_alu_reg_fn : alu_fn_code is IR(5 downto 0);
alias IR_rd : reg_addr is IR(15 downto 11);
alias IR_rs : reg_addr is IR(25 downto 21);
alias IR_r2 : reg_addr is IR(20 downto 16);
alias IR_immed : immed is IR(15 downto 0);
alias IR_count : shift_count is IR(10 downto 6);
alias IR_offset : disp is IR(15 downto 0);
signal IR_decode_alu_immed,
	IR_decode_mem, IR_decode_shift,
	IR_decode_alu_reg,
	IR_decode_jump,
	IR_decode_branch,
	IR_decode_misc : std_ulogic;
signal D_state : std_ulogic;
signal cc_Z : std_ulogic;
signal cc_C : std_ulogic;
signal D : unsigned_byte;
begin
	signal IR_decode_sll,
	IR_decode_srl,
	IR_decode_sllv,
	IR_decode_srav,
	IR_decode_add,
	IR_decode_sub,
	IR_decode_slt,
	IR_decode_jr,
	IR_decode_j,
	IR_decode_jal,
	IR_decode_beq,
	IR_decode_bne,
	IR_decode_addi,
	IR_decode_slti,
	IR_decode_andi,
	IR_decode_ori,
	IR_decode_lui,
	IR_decode_lw,
	IR_decode_sb,
	IR_decode_sw : std_ulogic;
	IR_decode_add <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100000"; 
	IR_decode_sub <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100010"; 
	IR_decode_sll <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000000"; 
	IR_decode_srl <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000010"; 
	IR_decode_sllv <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000100"; 
	IR_decode_srav <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100000"; 
	IR_decode_slt <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "101010"; 
	IR_decode_jr <= IR(31 downto 26) ?= "000000"  and IR(5 downto 0) ?= "001000" ;
	IR_decode_j <= IR(31 downto 26) ?= "000010";
	IR_decode_jal <= IR(31 downto 26) ?= "000011";
	IR_decode_beq <= IR(31 downto 26) ?= "000100";
	IR_decode_bne <= IR(31 downto 26) ?= "000101";
	IR_decode_addi <= IR(31 downto 26) ?= "001000";
	IR_decode_slti <= IR(31 downto 26) ?= "001010";
	IR_decode_andi <= IR(31 downto 26) ?= "001100";
	IR_decode_ori <= IR(31 downto 26) ?= "001101";
	IR_decode_lui <= IR(31 downto 26) ?= "001111";
	IR_decode_lw <= IR(31 downto 26) ?= "100011";
	IR_decode_sb <= IR(31 downto 26) ?= "101000";
	IR_decode_sw <= IR(31 downto 26) ?= "101010";
	IR_decode_alu_reg <=   IR_decode_add | IR_decode_sub; 
end architecture rtl_unpipelined;
