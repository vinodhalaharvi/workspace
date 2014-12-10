library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
use mycpu_defs.all;

entity  mycpu is
	port (
		     sysclk1 : in std_logic; 
		     reset : in std_logic; 
		     mem_reset : buffer std_logic;
		     mem_data_read : in std_logic_vector(31 downto 0);
		     mem_dataready_inv : in std_logic;
		     mem_ready : in std_logic;
		     mem_addr : out std_logic_vector(20 downto 0);
		     mem_data_write : buffer std_logic_vector(31 downto 0);
		     mem_rw : buffer std_logic;
		     mem_sixteenbit : buffer std_logic;
		     mem_thirtytwobit : buffer std_logic;
		     mem_addressready : buffer std_logic;

		     --debug related, these are exported to main entity
		     ALU_result : buffer std_logic_vector(31 downto 0); 
		     --destination_register : buffer std_logic_vector(31 downto 0); 
		     IR : buffer std_logic_vector(31 downto 0); 
		     PC :  buffer std_logic_vector(19 downto 0) := X"00000";
		     fsmStateCode : out std_logic_vector(3 downto 0); 
		     displayOutput : out std_logic_vector(31 downto 0); 
		     displaySwitches : in std_logic_vector(4 downto 0)
	     ); 
end entity mycpu;

architecture mycpu_arch of mycpu  is
	signal mem_data_read_internal : std_logic_vector(31 downto 0) := X"00000000";
	type states is (
	Init, 
	WaitForMemDataReadyInvHigh, 
	WaitForMemDataReadyInvLow,	
	SetControlAndDataInputs,
	ReadInputData, 
	decode_state, 
	execute_state, 
	write_back_state, 
	pc_increment);
	signal currentState : states := Init; 
	--signal PC :  std_logic_vector(19 downto 0) := X"00000";
	signal mem_addr_internal :  std_logic_vector(20 downto 0);

	--deleteme later
	signal GPR_left_operand : std_logic_vector(31 downto 0); 
	signal GPR_right_operand : std_logic_vector(31 downto 0); 
	signal ALU_C : std_logic; 
	signal ALU_Z : std_logic; 
	signal ALU_result_internal : std_logic_vector(31 downto 0); 

	--signal PC : IMem_addr;
	alias IR_alu_reg_fn : alu_fn_code is IR(5 downto 0);
	alias IR25_21 : reg_addr is unsigned(IR(25 downto 21));
	alias IR20_16 : reg_addr is unsigned(IR(20 downto 16));
	alias IR10_6 : reg_addr is unsigned(IR(10 downto 6));
	alias IR15_11 : reg_addr is unsigned(IR(15 downto 11));
	alias IR_immed : immed is unsigned(IR(15 downto 0));
	alias IR_count : shift_count is unsigned(IR(10 downto 6));
	alias IR_offset : disp is unsigned(IR(15 downto 0));
	alias IR_jumpaddr : unsigned(IR(25 downto 0));

	signal IR_decode_alu_immed,
	IR_decode_mem, IR_decode_shift,
	IR_decode_alu_reg,
	IR_decode_jump,
	IR_decode_branch,
	IR_decode_misc : std_logic := '0';
	signal D_state : std_logic;
	signal cc_Z : std_logic;
	signal cc_C : std_logic;
	signal D : unsigned_byte;
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
	IR_decode_sw : std_logic := '0';
begin
	IR_decode_add <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "100000") else '0';
	IR_decode_sub <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "100010") else '0';
	IR_decode_sll <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000000") else '0';
	IR_decode_srl <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000010") else '0';
	IR_decode_sllv <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "000100") else '0';
	IR_decode_srav <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "100000") else '0';
	IR_decode_slt <= '1' when (IR(31 downto 26) = "000000") and (IR(5 downto 0) = "101010") else '0';
	IR_decode_jr <= '1' when (IR(31 downto 26) = "000000" ) and (IR(5 downto 0) = "001000" ) else '0';
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
	IR_decode_sb <= '1' when (IR(31 downto 26) = "101000") else '0';
	IR_decode_sw <= '1' when (IR(31 downto 26) = "101010") else '0';
	IR_decode_alu_reg <=   IR_decode_add or IR_decode_sub; 
	IR_decode_alu_immed <= IR_decode_addi or IR_decode_slti or IR_decode_andi 
			       or IR_decode_ori or IR_decode_lui; 

	IR <= mem_data_read_internal; 
	ALU_result <= ALU_result_internal;

	ALU_Inst : process (all)
	begin
		if  rising_edge(sysclk1) then
			if IR_decode_add then
				ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
						       + unsigned(GPR_right_operand));
			elsif IR_decode_sub then
				ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
						       - unsigned(GPR_right_operand));
			elsif IR_decode_sll then
				ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
						       sll to_integer(IR_count));
			elsif IR_decode_srl then
				ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
						       srl to_integer(IR_count));
			elsif IR_decode_sllv then 
				ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
						       sll to_integer(unsigned(GPR_left_operand))); 
			elsif IR_decode_srav then 
				ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
						       srl to_integer(unsigned(GPR_left_operand))); 
			elsif IR_decode_slt then 
				if to_integer(unsigned(GPR_left_operand)) < to_integer(unsigned(GPR_right_operand)) 
				then
					ALU_result_internal <=  X"00000001";
				else 
					ALU_result_internal <=  X"00000000";
				end if; 
			elsif IR_decode_beq then 
				if to_integer(unsigned(GPR_left_operand)) = to_integer(unsigned(GPR_right_operand)) 
				then
					ALU_Z <= '1' ;
				else 
					ALU_Z <= '0'; 
				end if;
			elsif IR_decode_bne then 
				if to_integer(unsigned(GPR_left_operand)) /= to_integer(unsigned(GPR_right_operand)) 
				then
					ALU_Z <= '1' ;
				else 
					ALU_Z <= '0'; 
				end if;
			elsif IR_decode_addi then 
				ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
						       +  unsigned(X"0000" & std_logic_vector(IR_immed)));
			elsif IR_decode_slti then 
				if (unsigned(GPR_left_operand) < unsigned(IR_immed))  then 
					ALU_result_internal <=  X"00000001";
				else 
					ALU_result_internal <= X"00000000";
				end if;
			elsif IR_decode_andi then 
				ALU_result_internal <= GPR_left_operand and (X"0000" & std_logic_vector(IR_immed)); 
			elsif IR_decode_ori then 
				ALU_result_internal <= GPR_left_operand or (X"0000" & std_logic_vector(IR_immed)); 
			elsif IR_decode_lui then 
				ALU_result_internal <= std_logic_vector(unsigned(X"0000" & std_logic_vector(IR_immed)) sll 16); 
			elsif IR_decode_lw then 
				ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
						       + unsigned(X"0000" & std_logic_vector(IR_offset))); 
			elsif IR_decode_sb then 
				ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
						       + unsigned(X"0000" & std_logic_vector(IR_offset))); 
			elsif IR_decode_sw then 
				ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
						       + unsigned(X"0000" & std_logic_vector(IR_offset))); 
			else
				ALU_result_internal <= X"00000AAA";
			end if;
		end if; 
		if ALU_result_internal = X"00000000" then 
			ALU_Z <= '1';
		end if; 
	end process ALU_Inst;


	--add register file process here
	GPR_mem : process (sysclk1, reset)
		subtype reg_index is natural range 0 to 31;
		variable r2_addr : reg_addr;
		--variable write_data : unsigned_byte;
		--variable write_data: std_logic_vector(31 downto 0); 
		subtype double_word is std_logic_vector(31 downto 0); 
		type std_logic_vector_array is array (reg_index) of double_word;
		variable GPR : std_logic_vector_array := (others => X"00000000");
	begin
		displayOutput <= GPR(to_integer(unsigned(displaySwitches))); 
		if reset = '0' then
			--GPR := (others => (others => '0'));
			GPR := (others => X"00000000"); 
		elsif rising_edge(sysclk1) then
			--GPR(7) := std_logic_vector((unsigned(GPR(7)) + 1));
			if currentState = write_back_state and IR15_11 /= 0 then
				if IR_decode_alu_reg or IR_decode_alu_immed or IR_decode_shift
				then 
					GPR(to_integer(IR15_11)) := ALU_result_internal;
				end if;
			--destination_register <= GPR(to_integer(IR15_11)); 
			end if;
			if currentState = decode_state then
				--r2_addr := IR20_16;
				GPR_left_operand <= GPR(to_integer(IR25_21));
				GPR_right_operand <= GPR(to_integer(IR20_16));
			end if;
		----displayOutput(4 downto 0) <= displaySwitches;
		end if;
	end process GPR_mem;

	FSM : process(sysclk1, reset, mem_data_read, mem_dataready_inv, mem_ready) is
	begin
		if reset = '0' then
			PC <= X"00000";
			currentState <= Init;
			mem_reset <= not reset; 
		elsif rising_edge(sysclk1) then
			case currentState is
				when Init =>
					currentState <= WaitForMemDataReadyInvHigh;
				when WaitForMemDataReadyInvHigh =>
					if mem_dataready_inv = '1'  then 
						currentState <= SetControlAndDataInputs; 
					end if;
				when SetControlAndDataInputs =>
					if mem_rw = '1' then 
						mem_addr <= '0' & PC;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						mem_data_write <= mem_data_read_internal;
						currentState <= WaitForMemDataReadyInvLow; 
					else
						mem_addr <= '0' & PC;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						currentState <= WaitForMemDataReadyInvLow; 
					end if;
				when WaitForMemDataReadyInvLow =>
					if mem_dataready_inv = '0' then 
						if mem_rw = '0' then 
							currentState <= ReadInputData; 
						else
							mem_addressready <=  '0'; 
							currentState <= pc_increment; 
						end if;
					end if; 
				when ReadInputData =>
					mem_data_read_internal <= mem_data_read;
					mem_addressready <=  '0'; 
					currentState <= decode_state; 
				when decode_state =>
					currentState <= execute_state; 
				when execute_state =>
					currentState <= write_back_state; 
				when write_back_state =>
					currentState <= pc_increment; 
				when pc_increment =>
					PC <= std_logic_vector(unsigned(PC) + 2); 
					currentState <= Init;
				when others => 
					currentState <= Init; 
			end case;
		end if;
	end process;


	--debugging related
	with currentState select
		fsmStateCode <=
	       "0000" when Init,
	       "0001" when WaitForMemDataReadyInvHigh,
	       "0010" when SetControlAndDataInputs,
	       "0011" when WaitForMemDataReadyInvLow,
	       "0100" when ReadInputData,
	       "0101" when decode_state,
	       "0110" when execute_state,
	       "0111" when write_back_state,
	       "1000" when pc_increment,
	       "1001" when others;
end architecture mycpu_arch;
