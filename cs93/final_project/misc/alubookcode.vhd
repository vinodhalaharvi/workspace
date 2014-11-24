procedure addu ( a, b : in word32;
		 sum : out word32;
		 overflow : out bit ) is
		 variable carry : bit := '0';
begin
	for index in sum'reverse_range loop
		sum(index) := a(index) xor b(index) xor carry;
		carry := ( a(index) and b(index) )
		or ( carry and ( a(index) xor b(index) ) );
	end loop;
	overflow := carry;
end procedure addu;
--variable PC, next_PC : word32;
--variable overflow_flag : bit;
--addu ( PC, X"0000_0004", next_PC, overflow_flag);

procedure negate ( a : inout word32 ) is
		   variable carry_in : bit := '1';
variable carry_out : bit;
begin
	a := not a;
	for index in a'reverse_range loop
		carry_out := a(index) and carry_in;
		a(index) := a(index) xor carry_in;
		carry_in := carry_out;
	end loop;
end procedure negate;



procedure increment ( a : inout word32;
		      by : in word32 := X"0000_0001" ) is
			      variable sum : word32;
			      variable carry : bit := '0';
begin
	for index in a'reverse_range loop
		sum(index) := a(index) xor by(index) xor carry;
		carry := ( a(index) and by(index) )
		or ( carry and ( a(index) xor by(index) ) );
	end loop;
	a := sum;
end procedure increment;
--increment(count, X"0000_0004");
--increment(count); 
--increment(count, by => open);


procedure bv_lt ( bv1, bv2 : in bit_vector;
		  result : out boolean ) is
	  variable tmp1 : bit_vector(bv1'range) := bv1;
	  variable tmp2 : bit_vector(bv2'range) := bv2;
begin
	tmp1(tmp1'left) := not tmp1(tmp1'left);
	tmp2(tmp2'left) := not tmp2(tmp2'left);
	result := tmp1 < tmp2;
end procedure bv_lt;


procedure perform_alu_op ( fn : in alu_fn_code;
			a, b : in unsigned_byte;
			C_in : in std_ulogic;
			result : out unsigned_byte;
			Z_out, C_out : out std_ulogic ) is
begin
	case fn is
		when alu_fn_add =>
			(C_out, result) := ('0' & a) + ('0' & b);
		when alu_fn_addc =>
			(C_out, result) := ('0' & a) + ('0' & b) + C_in;
		when alu_fn_sub =>
			(C_out, result) := ('0' & a) - ('0' & b);
		when alu_fn_subc =>
			(C_out, result) := ('0' & a) - ('0' & b) - C_in;
		when alu_fn_and =>
			(C_out, result) := ('0' & a) and ('0' & b);
		when alu_fn_or =>
			(C_out, result) := ('0' & a) or ('0' & b);
		when alu_fn_xor =>
			(C_out, result) := ('0' & a) xor ('0' & b);
		when alu_fn_mask =>
			(C_out, result) := ('0' & a) and not ('0' & b);
		when others =>
			report "Program logic error in interpreter"
			severity failure;
	end case;
	Z_out := result ?= X"00";
end procedure perform_alu_op;


procedure perform_shift_op ( fn : in shift_fn_code;
			     a : in unsigned_byte;
			     count : in shift_count;
			     result : out unsigned_byte;
			Z_out, C_out : out std_ulogic ) is
begin
	case fn is
		when shift_fn_shl =>
			(C_out, result) := ('0' & a) sll to_integer(count);
		when shift_fn_shr =>
			(result, C_out) := (a & '0') srl to_integer(count);
		when shift_fn_rol =>
			result := a rol to_integer(count);
			C_out := result(unsigned_byte'right);
		when shift_fn_ror =>
			result := a ror to_integer(count);
			C_out := result(unsigned_byte'left);
		when others =>
			report "Program logic error in interpreter"
			severity failure;
	end case;
	Z_out := result ?= X"00";
end procedure perform_shift_op;



library ieee;
use ieee.std_logic_1164.all; 
use ieee.numeric_std.all;
package body alu_defs is
end package body alu_defs;

-- Arithmetic/Logical Immediate
perform_alu_op(fn => IR_alu_immed_fn,
		a => GPR(to_integer(IR_rs)),
		b => IR_immed,
		C_in => cc_C,
		result => ALU_result,
		Z_out => cc_Z, C_out => cc_C); 
		if IR_rd /= 0 then
			GPR(to_integer(IR_rd)) := ALU_result;
		end if;
