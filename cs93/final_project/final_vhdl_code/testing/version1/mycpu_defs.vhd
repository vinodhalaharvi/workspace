library ieee;
use ieee.std_logic_1164.all, ieee.numeric_std.all;
package mycpu_defs is
	constant IMem_addr_width : positive := 20;
	constant IMem_size : positive := 2**IMem_addr_width;
	subtype IMem_addr is unsigned(IMem_addr_width - 1 downto 0);
	subtype instruction is unsigned(31 downto 0);
	subtype unsigned_byte is unsigned(7 downto 0);
	subtype signed_byte is signed(7 downto 0);
	subtype reg_addr is unsigned(4 downto 0);
	subtype immed is unsigned(15 downto 0);
	subtype offset is unsigned(15 downto 0);
	subtype shift_count is unsigned(4 downto 0);

	--type instruction_array is array (natural range <>) of instruction;
	--subtype IMem_array is instruction_array(0 to IMem_size - 1);
	--type unsigned_byte_array is array (natural range <>) of unsigned_byte;
	--type signed_byte_array is array (natural range <>) of signed_byte;
	--alu codes
	subtype alu_fn_code is unsigned(5 downto 0);	
	constant alu_fn_add : alu_fn_code := "100000";
	constant alu_fn_sub : alu_fn_code := "100010";
	constant alu_fn_and : alu_fn_code := "100100";
	constant alu_fn_sll : alu_fn_code := "000000";
	constant alu_fn_srl : alu_fn_code := "000010";
	constant alu_fn_or  : alu_fn_code := "100101";

	   --op codes
	constant op_fn_special  : op_fn_code := "000000";
	constant op_fn_jr   : op_fn_code := "000000";
	constant op_fn_j    : op_fn_code := "000010";
	constant op_fn_jal  : op_fn_code := "000011";
	constant op_fn_beq  : op_fn_code := "000100";
	constant op_fn_bne  : op_fn_code := "000101";
	constant op_fn_addi : op_fn_code := "001000";

	constant op_fn_slti : op_fn_code := "001010";
	constant op_fn_andi : op_fn_code := "001100";
	constant op_fn_ori  : op_fn_code := "001101";
	constant op_fn_lui  : op_fn_code := "001111";

	constant op_fn_lw   : op_fn_code := "100011";
	constant op_fn_sb   : op_fn_code := "101000";
	constant op_fn_sw   : op_fn_code := "101010";

end package mycpu_defs;