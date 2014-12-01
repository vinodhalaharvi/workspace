--still working
entity  GPRTesting is
	port (

	); 
end entity GPRTesting;

architecture GPRTesting_arch of GPRTesting  is
begin
	GPR_mem : process (clk_i)
		subtype reg_index is natural range 0 to 7;
		variable r2_addr : reg_addr;
		variable write_data : unsigned_byte;
		variable GPR : unsigned_byte_array(reg_index)
		:= (others => X"00");
	begin
		if rising_edge(clk_i) then
			if rst_i then
				GPR := (others => (others => '0'));
			else
				if state = write_back_state and IR_rd /= 0 then
					if IR_decode_alu_reg or IR_decode_alu_immed
					or IR_decode_shift then
						write_data := ALU_out;
					elsif IR_decode_mem
					and (IR_mem_fn ?= mem_fn_ldm
					or IR_mem_fn ?= mem_fn_inp) then
						write_data := D;
					end if;
					GPR(to_integer(IR_rd)) := write_data;
				end if;
				if state = decode_state then
					if IR_decode_mem
					and (IR_mem_fn ?= mem_fn_stm
					or IR_mem_fn ?= mem_fn_out) then
						r2_addr := IR_rd;
					else
						r2_addr := IR_r2;
					end if;
					GPR_rs <= GPR(to_integer(IR_rs));
					GPR_r2 <= GPR(to_integer(r2_addr));
				end if;
			end if;
		end if;
	end process GPR_mem;
end architecture GPRTesting_arch;
