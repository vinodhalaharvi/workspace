library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
use mycpu_defs.all;

entity  mycpu is
	port (
		     sysclk1 : in std_logic; 
		     reset : in std_logic; 
		     mem_reset : in std_logic;
		     mem_data_read : in std_logic_vector(31 downto 0);
		     mem_dataready_inv : in std_logic;
		     mem_ready : in std_logic;
		     mem_addr : out std_logic_vector(20 downto 0);
		     mem_data_write : out std_logic_vector(31 downto 0);
		     mem_rw : out std_logic;
		     mem_sixteenbit : out std_logic;
		     mem_thirtytwobit : out std_logic;
		     mem_addressready : out std_logic;
		     --debug related, these are exported to main entity
		     --ALU_result : buffer std_logic_vector(31 downto 0); 
		     --destination_register : buffer std_logic_vector(31 downto 0); 
		     IR : buffer std_logic_vector(31 downto 0); 
		     pc :  buffer std_logic_vector(20 downto 0) := '0' & X"00000";
		     fsmStateCode : out std_logic_vector(3 downto 0); 
		     displayOutput : out std_logic_vector(31 downto 0); 
		     displaySwitches : in std_logic_vector(4 downto 0)
	     ); 
end entity mycpu;

architecture mycpu_arch of mycpu  is
	type states is (init, fetch_state, decode_state, execute_state, write_back_state, mem_state); 
	--signal reset : std_logic := '0';
	--signal pc : std_logic_vector(20 downto 0) := '0' & X"00000"; 
	signal ALU_Z : std_logic ; 
	signal ALU_C : std_logic; 
	signal GPR_left_operand : std_logic_vector(31 downto 0); 
	signal GPR_right_operand : std_logic_vector(31 downto  0); 
	signal dest_addr : std_logic_vector(4 downto 0);
	signal jr_addr : std_logic_vector(20 downto 0); 
	signal ALU_result : std_logic_vector(31 downto 0); 
	-- just for testing
	signal t0 : std_logic_vector(31 downto 0); 
	signal t1 : std_logic_vector(31 downto 0); 
	signal t2 : std_logic_vector(31 downto 0); 
	signal t3 : std_logic_vector(31 downto 0); 
	--signal IR : std_logic_vector(31 downto 0); 
	alias IR31_26 is IR(31 downto 26);
	alias IR25_21 is IR(25 downto 21);
	alias IR20_16 is IR(20 downto 16);
	alias IR15_11 is IR(15 downto 11);
	alias IR10_6 is IR(10 downto 6);
	alias IR5_0 is IR(5 downto 0);
	alias IR_jumpaddr is IR(25 downto 0);
	signal branch_taken : std_logic := '0';
	alias IR_offset is IR(15 downto 0); 
	signal currentState : states := init; 
	signal previousState : states := init; 
	signal IR_decode_alu_immed,
	IR_decode_mem, 
	IR_decode_shift,
	IR_decode_alu_reg,
	IR_decode_jump,
	IR_decode_branch,
	IR_decode_misc : std_logic := '0';
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
	IR_decode_lb,
	IR_decode_sb,
	IR_decode_sw : std_logic := '0';
begin
	IR_decode_add <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "100000") else '0';
	IR_decode_sub <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "100010") else '0';
	IR_decode_sll <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000000") else '0';
	IR_decode_srl <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000010") else '0';
	IR_decode_sllv <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000100") else '0';
	IR_decode_srav <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000111") else '0';
	IR_decode_slt <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "101010") else '0';
	IR_decode_jr <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "001000" ) else '0';
	IR_decode_j <= '1' when (IR(31 downto 26) = "000010") else '0';
	IR_decode_jal <= '1' when (IR(31 downto 26) = "000011") else '0';
	IR_decode_beq <= '1' when (IR(31 downto 26) = "000100") else '0';
	IR_decode_bne <= '1' when (IR(31 downto 26) = "000101") else '0';
	IR_decode_addi <= '1' when (IR(31 downto 26) = "001000") else '0';
	IR_decode_slti <= '1' when (IR(31 downto 26) = "001010") else '0';
	IR_decode_andi <= '1' when (IR(31 downto 26) = "001100") else '0';
	IR_decode_ori <= '1' when (IR(31 downto 26) = "001101") else '0';
	IR_decode_lui <= '1' when (IR(31 downto 26) = "001111") else '0';
	IR_decode_lw <= '1' when (IR(31 downto 26) = "100011") else '0';
	IR_decode_lb <= '1' when (IR(31 downto 26) = "100000") else '0';
	IR_decode_sb <= '1' when (IR(31 downto 26) = "101000") else '0';
	IR_decode_sw <= '1' when (IR(31 downto 26) = "101010") else '0';
	IR_decode_shift <= '1' when (IR_decode_sll or IR_decode_srl or IR_decode_sllv or IR_decode_srav) else '0';
	IR_decode_alu_reg <= '1' when (IR_decode_add or IR_decode_sub) else '0'; 
	IR_decode_misc <= '1' when IR_decode_slt else '0';
	IR_decode_jump <= '1' when (IR_decode_j or IR_decode_jal or IR_decode_jr) else '0';
	IR_decode_branch<= '1' when (IR_decode_beq or IR_decode_bne) else '0';
	IR_decode_alu_immed<= '1' when (IR_decode_addi or IR_decode_slti  
			      or IR_decode_andi or IR_decode_ori or IR_decode_lui) else '0';
	IR_decode_mem<= '1' when (IR_decode_lw or IR_decode_lb or IR_decode_sb or IR_decode_sw) else '0';
	aluSim_test: entity aluSim 
	port map (
			 GPR_left_operand => GPR_left_operand, 
			 GPR_right_operand => GPR_right_operand, 
			 IR => IR, 
			 ALU_C => ALU_C,
			 ALU_Z => ALU_Z,
			 ALU_result => ALU_result
		 );       

	branch_taken <= ALU_Z when (IR_decode_beq = '1' or IR_decode_bne = '1' ) else '0';
	--branch_taken <= ALU_Z when IR_decode_beq = '1' else '0'; 
	fsm : process(sysclk1, reset, mem_data_read, mem_dataready_inv, mem_ready) is
		subtype reg_index is natural range 0 to 31;
		subtype double_word is std_logic_vector(31 downto 0); 
		type std_logic_vector_array is array (reg_index) of double_word;
		variable GPR : std_logic_vector_array := (others => (others => '0')); 
	begin
		displayOutput <= GPR(to_integer(unsigned(displaySwitches))); 
		if reset = '0' then
			currentState <= init;
		elsif rising_edge(sysclk1) then
			t0 <= GPR(8);
			t1 <= GPR(9); 
			t2 <= GPR(10); 
			t3 <= GPR(11); 
			case currentState is
				when init => 
					pc <= '0' & X"00000"; 
					currentState <= fetch_state; 
				when fetch_state =>
					if mem_dataready_inv = '1' and previousState /= fetch_state  then 
						mem_rw <= '0';
						mem_addr <= pc;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						previousState <= fetch_state; 
						currentState <= mem_state; 
					else
						pc <= std_logic_vector(unsigned(pc) + 4); 
						IR <= mem_data_read; 
						currentState <= decode_state;
						previousState <= init;
						mem_addressready <= '0';
					end if; 
				when mem_state =>
					if mem_dataready_inv = '0' then 
						currentState <= previousState;
					end if;
				when decode_state =>
					if IR_decode_jal then
						GPR(31) := X"00" & "000" & pc;
					elsif IR_decode_jr then 
						jr_addr <= GPR(31)(20 downto 0); 
					end if; 
					GPR_left_operand <= GPR(to_integer(unsigned(IR25_21)));
					GPR_right_operand <= GPR(to_integer(unsigned(IR20_16)));
					if IR_decode_alu_reg or IR_decode_shift then 
						dest_addr <= IR15_11; 
					else 
						dest_addr <= IR20_16; 
					end if; 
					currentState <= execute_state;
				when execute_state =>
					--if IR_decode_branch = '1' and branch_taken = '1' then
					if IR_decode_branch = '1' then 
						if branch_taken = '1' then
							pc <= "00000" & IR_offset;
							currentState <= fetch_state;
						else 
							currentState <= fetch_state;
						end if;
					elsif IR_decode_jump  = '1' then
						if IR_decode_j or IR_decode_jal then  
							pc <= "00000" & IR_jumpaddr(15 downto 0);
							currentState <= fetch_state;
						elsif IR_decode_jr then 
							pc <= jr_addr; 
							currentState <= fetch_state;
						end if; 
					else
						currentState <= write_back_state;
					end if; 
				when write_back_state =>
					if IR_decode_alu_reg or IR_decode_alu_immed or IR_decode_shift or IR_decode_slt
					then 
						GPR(to_integer(unsigned(dest_addr))) := ALU_result;
						currentState <= fetch_state; 
					elsif IR_decode_mem then 
						if IR_decode_lb then 
							if mem_dataready_inv = '1' and previousState /= write_back_state  then 
								mem_rw <= '0';
								mem_addr <= ALU_result(20 downto 0);
								mem_sixteenbit <= '1';
								mem_thirtytwobit <= '0';
								currentState <= mem_state; 
								mem_addressready <= '1';
								previousState <= write_back_state; 
							else
								GPR(to_integer(unsigned(dest_addr)))(7 downto 0) 
									:= mem_data_read(7 downto 0); 
								GPR(to_integer(unsigned(dest_addr)))(31 downto 8) 
									:=  X"000000";
								mem_addressready <= '0';
								previousState <= init;
								currentState <= fetch_state; 
							end if; 
						elsif IR_decode_sb then 
							if mem_dataready_inv = '1' and previousState /= write_back_state then 
								mem_rw <= '1';
								mem_addr <= ALU_result(20 downto 0); 
								mem_sixteenbit <= '1';
								mem_thirtytwobit <= '0';
								mem_data_write(7 downto 0) <= GPR(to_integer(unsigned(dest_addr)))(7 downto 0); 
								mem_data_write(31 downto 8) <= X"000000";
								currentState <= mem_state; 
								mem_addressready <= '1';
								previousState <= write_back_state; 
							else
								mem_addressready <= '0';
								previousState <= init;
								currentState <= fetch_state; 
							end if;
						elsif IR_decode_lw then 
							if mem_dataready_inv = '1' and previousState /= write_back_state  then 
								mem_rw <= '0';
								mem_addr <= ALU_result(20 downto 0); 
								mem_sixteenbit <= '0';
								mem_thirtytwobit <= '1';
								currentState <= mem_state; 
								mem_addressready <= '1';
								previousState <= write_back_state; 
							else
								GPR(to_integer(unsigned(dest_addr)))(15 downto 0) 
									:= mem_data_read(15 downto 0); 
								GPR(to_integer(unsigned(dest_addr)))(31 downto 16) 
									:=  X"0000";
								mem_addressready <= '0';
								previousState <= init; 
								currentState <= fetch_state; 
							end if; 
						elsif IR_decode_sw then 
							if mem_dataready_inv = '1' and previousState /= write_back_state then 
								mem_rw <= '1';
								mem_addr <= ALU_result(20 downto 0); 
								mem_sixteenbit <= '1';
								mem_thirtytwobit <= '0';
								mem_data_write(15 downto 0) <= GPR(to_integer(unsigned(dest_addr)))(15 downto 0); 
								mem_data_write(31 downto 16) <= X"0000";
								--currentState <= mem_state; 
								mem_addressready <= '1';
								--previousState <= write_back_state; 
								--else 
								--previousState <= init;
								--mem_addressready <= '0';
								currentState <= fetch_state; 
							end if; 
						end if;
					end if;
			end case;
		end if;
	end process;

	with currentState select
		fsmStateCode <=
	       "0000" when init,
	       "0001" when fetch_state,
	       "0010" when decode_state,
	       "0011" when execute_state,
	       "0100" when mem_state,
	       "0101" when write_back_state,
	       "1111" when others;
end architecture mycpu_arch;
