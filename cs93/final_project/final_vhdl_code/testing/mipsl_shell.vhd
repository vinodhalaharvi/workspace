library ieee; 
use ieee.std_logic_1164.all, ieee.numeric_std.all;
use work.gumnut_defs.all;

entity  mipsl is
	port (
	vars : type datatype
); 
end entity mipsl;


architecture rtl_mipsl of mipsl is
	signal PC : IMem_addr;
	signal branch_taken : std_ulogic;
	signal IR : instruction;
	alias IR_alu_reg_fn : alu_fn_code is IR(2 downto 0);
	alias IR_alu_immed_fn : alu_fn_code is IR(16 downto 14);
	alias IR_shift_fn : shift_fn_code is IR(1 downto 0);
	alias IR_mem_fn : mem_fn_code is IR(15 downto 14);
	alias IR_branch_fn : branch_fn_code is IR(11 downto 10);
	alias IR_jump_fn : jump_fn_code is IR(12 downto 12);
	alias IR_misc_fn : misc_fn_code is IR(10 downto 8);
	alias IR_rd : reg_addr is IR(15 downto 11);
	alias IR_rs : reg_addr is IR(25 downto 21);
	alias IR_r2 : reg_addr is IR(20 downto 16);
	alias IR_immed : immed is IR(16 downto 0);
	alias IR_count : shift_amount is IR(5 downto 0);
	alias IR_offset : disp is IR(15 downto 0);
	--alias IR_disp : disp is IR(7 downto 0);
	alias IR_addr : IMem_addr is IR(25 downto 21);
	signal IR_decode_alu_immed,
		IR_decode_mem,
		IR_decode_shift,
		IR_decode_alu_reg,
		IR_decode_jump,
		IR_decode_branch,
		IR_decode_misc : std_ulogic;
	signal D_state : std_ulogic;
	signal int_PC : IMem_addr;
	signal int_Z : std_ulogic;
	signal int_C : std_ulogic;
	signal int_en : std_ulogic;
	constant SP_length : positive := 3;
	signal SP : unsigned(SP_length - 1 downto 0);
	signal stack_top : IMem_addr;
	signal GPR_rs : unsigned_byte;
	signal GPR_r2 : unsigned_byte;
	signal ALU_result : unsigned_byte;
	signal ALU_Z : std_ulogic;
	signal ALU_C : std_ulogic;
	signal ALU_out : unsigned_byte;
	signal cc_Z : std_ulogic;
	signal cc_C : std_ulogic;
	signal D : unsigned_byte;
	type control_state is (fetch_state,
		decode_state,
		execute_state,
		mem_state,
		write_back_state,
		int_state);
	signal state, next_state : control_state;
begin
	IR_decode_alu_immed <= IR(17) ?= '0';
	IR_decode_mem <= IR(17 downto 16) ?= "10";
	IR_decode_shift <= IR(17 downto 15) ?= "110";
	IR_decode_alu_reg <= IR(17 downto 14) ?= "1110";
	IR_decode_jump <= IR(17 downto 13) ?= "11110";
	IR_decode_branch <= IR(17 downto 12) ?= "111110";
	IR_decode_misc <= IR(17 downto 11) ?= "1111110";
end architecture rtl_mipsl;
