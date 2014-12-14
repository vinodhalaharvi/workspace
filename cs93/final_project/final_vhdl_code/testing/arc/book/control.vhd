control : process (all)
begin
	case state is
		when fetch_state =>
			if not inst_ack_i then
				next_state <= fetch_state;
			else
				next_state <= decode_state;
			end if;
		when decode_state =>
			if IR_decode_branch or IR_decode_jump or IR_decode_misc then
				if IR_decode_misc
				and (IR_misc_fn ?= misc_fn_wait
				or IR_misc_fn ?= misc_fn_stby)
				and not (int_en and int_req) then
					next_state <= decode_state;
				elsif int_en and int_req then
					next_state <= int_state;
				else
					next_state <= fetch_state;
				end if;
			else
				next_state <= execute_state;
			end if;
		when execute_state =>
			if IR_decode_mem then
				if (IR_mem_fn ?= mem_fn_ldm or IR_mem_fn ?= mem_fn_stm)
				and not data_ack_i then
					next_state <= mem_state;
				elsif (IR_mem_fn ?= mem_fn_inp or IR_mem_fn ?= mem_fn_out)
				and not port_ack_i then
					next_state <= mem_state;
				elsif IR_mem_fn ?= mem_fn_ldm
				or IR_mem_fn ?= mem_fn_inp then
					next_state <= write_back_state;
				else
					if int_en and int_req then
						next_state <= int_state;
					else
						next_state <= fetch_state;
					end if;
				end if;
			else
				next_state <= write_back_state;
			end if;
		when mem_state =>
			if (IR_mem_fn ?= mem_fn_ldm or IR_mem_fn ?= mem_fn_stm)
			and not data_ack_i then
				next_state <= mem_state;
			elsif (IR_mem_fn ?= mem_fn_inp or IR_mem_fn ?= mem_fn_out)
			and not port_ack_i then
				next_state <= mem_state;
			elsif IR_mem_fn ?= mem_fn_ldm
			or IR_mem_fn ?= mem_fn_inp then
				next_state <= write_back_state;
			else
				if int_en and int_req then
					next_state <= int_state;
				else
					next_state <= fetch_state;
				end if;
			end if;
		when write_back_state =>
			if int_en and int_req then
				next_state <= int_state;
			else
				next_state <= fetch_state;
			end if;
		when int_state =>
			next_state <= fetch_state;
	end case;
end process control;
state_reg : process (clk_i)
begin
	if rising_edge(clk_i) then
		if rst_i then
			state <= fetch_state;
		else
			state <= next_state;
		end if;
	end if;
end process state_reg;

with IR_branch_fn select
	branch_taken <= cc_Z when branch_fn_bz,
			not cc_Z when branch_fn_bnz,
			cc_C when branch_fn_bc,
			not cc_C when branch_fn_bnc,
			'X' when others;


PC_reg : process (clk_i)
begin
	if rising_edge(clk_i) then
		if rst_i then
			PC <= (others => '0');
		elsif state = fetch_state and inst_ack_i = '1' then
			PC <= PC + 1;
		elsif state = decode_state then
			if IR_decode_branch and branch_taken then
				PC <= unsigned(signed(PC) + signed(IR_disp));
			elsif IR_decode_jump then
				PC <= IR_addr;
			elsif IR_decode_misc and IR_misc_fn ?= misc_fn_ret then
				PC <= stack_top;
			elsif IR_decode_misc and IR_misc_fn ?= misc_fn_reti then
				PC <= int_PC;
			end if;
		elsif state = int_state then
			PC <= to_unsigned(1, PC'length);
		end if;
	end if;
end process PC_reg;


