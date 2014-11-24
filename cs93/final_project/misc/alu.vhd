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

