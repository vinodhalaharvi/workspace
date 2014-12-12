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
alias IR_rd : reg_addr is IR(13 downto 11);
alias IR_rs : reg_addr is IR(10 downto 8);
alias IR_r2 : reg_addr is IR(7 downto 5);
alias IR_immed : immed is IR(7 downto 0);
alias IR_count : shift_count is IR(7 downto 5);
alias IR_offset : disp is IR(7 downto 0);
alias IR_disp : disp is IR(7 downto 0);
alias IR_addr : IMem_addr is IR(11 downto 0);
signal IR_decode_alu_immed,
	IR_decode_mem, IR_decode_shift,
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
708 Chapter 22 — Case Study: System Design Using the Gumnut Core
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
