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
--signal branch_taken : std_ulogic;
--signal IR : instruction;
--alias IR_alu_immed_fn : alu_fn_code is IR(16 downto 14);
--alias IR_shift_fn : shift_fn_code is IR(1 downto 0);
--alias IR_mem_fn : mem_fn_code is IR(15 downto 14);
--alias IR_branch_fn : branch_fn_code is IR(11 downto 10);
--alias IR_jump_fn : jump_fn_code is IR(12 downto 12);
--alias IR_misc_fn : misc_fn_code is IR(10 downto 8);
--alias IR_disp : disp is IR(7 downto 0);
--alias IR_addr : IMem_addr is IR(11 downto 0);
--signal int_PC : IMem_addr;
--signal int_Z : std_ulogic;
--signal int_C : std_ulogic;
--signal int_en : std_ulogic;
--constant SP_length : positive := 3;
--signal SP : unsigned(SP_length - 1 downto 0);
--signal stack_top : IMem_addr;
--signal GPR_rs : unsigned_byte;
--signal GPR_r2 : unsigned_byte;
--signal ALU_result : unsigned_byte;
--signal ALU_Z : std_ulogic;
--type control_state is (fetch_state,
--	decode_state,
--	execute_state,
--	mem_state,
--	write_back_state,
--	int_state);
--signal state, next_state : control_state;
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
	--IR_decode_alu_immed <= IR(17) ?= '0';
	--IR_decode_mem <= IR(17 downto 16) ?= "10";
	--IR_decode_shift <= IR(17 downto 15) ?= "110";
	--IR_decode_jump <= IR(17 downto 13) ?= "11110";
	--IR_decode_branch <= IR(17 downto 12) ?= "111110";
	--IR_decode_misc <= IR(17 downto 11) ?= "1111110";
end architecture rtl_unpipelined;
