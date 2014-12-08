library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  aluSim_tb is
end entity aluSim_tb;

architecture aluSim_tb_arch of aluSim_tb  is
	signal sysclk1 : std_logic := '0';
	signal fsmStateCode : std_logic_vector(5 downto 0); 
	type states is (init, fetch_state, decode_state, execute_state, write_back_state); 
	signal reset : std_logic := '0';
	type memory_array is array(0 to 32768) of std_logic_vector(15 downto 0);
	signal pc : std_logic_vector(20 downto 0) := '0' & X"00000"; 


	signal ALU_Z : std_logic ; 
	signal ALU_C : std_logic; 
	signal GPR_left_operand : std_logic_vector(31 downto 0); 
	signal GPR_right_operand : std_logic_vector(31 downto  0); 
	signal dest_addr : std_logic_vector(4 downto 0);
	signal ALU_result : std_logic_vector(31 downto 0); 

	-- just for testing
	signal t0 : std_logic_vector(31 downto 0); 
	signal t1 : std_logic_vector(31 downto 0); 
	signal t2 : std_logic_vector(31 downto 0); 
	signal t3 : std_logic_vector(31 downto 0); 


	signal IR : std_logic_vector(31 downto 0); 
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
	signal memory : memory_array := (
		--branch testing 
		-- 10 10 10 0  is the output  or t0, t1, t2, t3
		X"0002",
		X"0C00",
		X"000A",
		X"2008",
		X"0005",
		X"2009",
		X"0002",
		X"200B",
		X"5022",
		X"0109",
		X"0005",
		X"2009",
		X"48C0",
		X"0008",
		X"0016",
		X"1000",
		X"5004",
		X"0168",
		X"5004",
		X"0168",
		X"000A",
		X"2949",
		X"5004",
		X"0168",
		X"4807",
		X"016A",
		X"4942",
		X"0008",
		X"4807",
		X"016A",
		others => (others => 'X')); 

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
	IR_decode_sb <= '1' when (IR(31 downto 26) = "101000") else '0';
	IR_decode_sw <= '1' when (IR(31 downto 26) = "101010") else '0';


	IR_decode_shift <= '1' when (IR_decode_sll or IR_decode_srl or IR_decode_sllv or IR_decode_srav) else '0';
	IR_decode_alu_reg <= '1' when (IR_decode_add or IR_decode_sub) else '0'; 
	IR_decode_misc <= '1' when IR_decode_slt else '0';
	IR_decode_jump <= '1' when (IR_decode_j or IR_decode_jal) else '0';
	IR_decode_branch<= '1' when (IR_decode_beq or IR_decode_bne) else '0';
	IR_decode_alu_immed<= '1' when (IR_decode_addi or IR_decode_slti  
			      or IR_decode_andi or IR_decode_ori or IR_decode_lui) else '0';
	IR_decode_mem<= '1' when (IR_decode_lw or IR_decode_sb or IR_decode_sw) else '0';


	aluSim_test: entity aluSim 
	port map (
		  GPR_left_operand => GPR_left_operand, 
		  GPR_right_operand => GPR_right_operand, 
		  IR => IR, 
		  ALU_C => ALU_C,
		  ALU_Z => ALU_Z,
		  ALU_result => ALU_result
	  );       

	branch_taken <= ALU_Z when IR_decode_beq = '1' else
			not ALU_Z when IR_decode_bne = '1' else 
			'0'; 


	fsm : process(sysclk1, reset) is
	begin
		if reset = '1' then
			currentState <= init;
		elsif rising_edge(sysclk1) then
			case currentState is
				when init => 
					pc <= '0' & X"00000"; 
					currentState <= fetch_state; 
				when fetch_state =>
					IR(15 downto 0) <= memory(to_integer(unsigned(pc))); 
					IR(31 downto 16) <= memory(to_integer(unsigned(pc) + 1)); 
					pc <= std_logic_vector(unsigned(pc) + 2); 
					currentState <= decode_state; 
				when decode_state =>
					currentState <= execute_state;
				when execute_state =>
					if IR_decode_branch = '1' and branch_taken = '1' then
						pc <= '0' & X"0" & IR_offset;
						currentState <= fetch_state;
					elsif IR_decode_jump  = '1' then
						pc <= '0' & X"0" & IR_jumpaddr(15 downto 0);
						currentState <= fetch_state;
					else
						currentState <= write_back_state;
					end if; 
				when write_back_state =>
					currentState <= fetch_state; 
			end case;
		end if;
	end process;

	GPR_mem : process (sysclk1, reset)
		subtype reg_index is natural range 0 to 31;
		subtype double_word is std_logic_vector(31 downto 0); 
		type std_logic_vector_array is array (reg_index) of double_word;
		variable GPR : std_logic_vector_array := (others => X"00000000");
	begin
		if reset = '1' then
			GPR := (others => X"00000000"); 
		elsif rising_edge(sysclk1) then
			t0 <= GPR(8);
			t1 <= GPR(9); 
			t2 <= GPR(10); 
			t3 <= GPR(11); 
			if currentState = decode_state then
				GPR_left_operand <= GPR(to_integer(unsigned(IR25_21)));
				GPR_right_operand <= GPR(to_integer(unsigned(IR20_16)));
				dest_addr <= IR15_11 when (IR_decode_alu_reg or IR_decode_shift)
					     else IR20_16 when  (IR_decode_branch or IR_decode_alu_immed 
						     or  IR_decode_mem);
			elsif currentState = write_back_state and unsigned(dest_addr) /= 0 then
				if IR_decode_alu_reg or IR_decode_alu_immed or IR_decode_shift
				then 
					GPR(to_integer(unsigned(dest_addr))) := ALU_result;
				end if;
			end if;
		end if;
	end process GPR_mem;


	gen_clk: process is
	begin
		for i in 1 to 400 loop 
			wait for 1 ms;
			sysclk1 <= '1';
			wait for 1 ms;
			sysclk1 <= '0';
		end loop;
		wait;
	end process gen_clk;

	with currentState select
		fsmStateCode <=
	       "000000" when init,
	       "000001" when fetch_state,
	       "000010" when decode_state,
	       "000011" when execute_state,
	       "000100" when write_back_state,
	       "111111" when others;
end architecture aluSim_tb_arch;
