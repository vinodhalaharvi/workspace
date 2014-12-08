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
	type memory_array is array(0 to 255) of std_logic_vector(31 downto 0);
	signal pc : std_logic_vector(7 downto 0) := X"00"; 

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

	signal currentState : states := init; 
	signal memory : memory_array := (
		--simple
		--X"0C000002", 
		--X"20080002", 
		--X"20090003", 
		--X"01285020", 

		--check all instructions	
		--X"0C000002",
		--X"012A4020",
		--X"2084000A",
		--X"3109000A",
		--X"10090008",
		--X"14080008",
		--X"08000008",
		--X"0C000008",
		--X"03E00008",
		--X"3C040000",
		--X"34845500",
		--X"8D28000C",
		--X"A128000C",
		--X"000849C0",
		--X"01285004",
		--X"0100482A",
		--X"2949000A",
		--X"016A4807",
		--X"00084802",
		--X"01004822",
		--X"A928000C",
	
		--comparsion with spim 
		--10 0 40 2
		--X"0C000002",
		--X"2008000A",
		--X"20090005",
		--X"200B0002",
		--X"01095022",
		--X"000848C0",
		--X"01685004",
		--X"2949000A",
		--X"016A4807",
		--X"00084942",

		--10 10 40 2
		X"0C000002",
		X"2008000A",
		X"20090005",
		X"200B0002",
		X"01095022",
		X"20090005",
		X"000848C0",
		X"01685004",
		X"01685004",
		X"2949000A",
		X"01685004",
		X"016A4807",
		X"00084942",
		X"016A4807",
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


	IR_decode_shift <= IR_decode_sll or IR_decode_srl or IR_decode_sllv or IR_decode_srav;
	IR_decode_alu_reg <= IR_decode_add or IR_decode_sub; 
	IR_decode_misc <= IR_decode_slt;
	IR_decode_jump <= IR_decode_jr or IR_decode_j or IR_decode_jal;
	IR_decode_branch<= IR_decode_beq or IR_decode_bne;
	IR_decode_alu_immed<= IR_decode_addi or IR_decode_slti or IR_decode_andi or IR_decode_ori or IR_decode_lui;
	IR_decode_mem<= IR_decode_lw or IR_decode_sb or IR_decode_sw;

	aluSim_test: entity aluSim 
	port map (
		  GPR_left_operand => GPR_left_operand, 
		  GPR_right_operand => GPR_right_operand, 
		  IR => IR, 
		  ALU_C => ALU_C,
		  ALU_Z => ALU_Z,
		  ALU_result => ALU_result
	  );       


	fsm : process(sysclk1, reset) is
	begin
		if reset = '1' then
			currentState <= init;
		elsif rising_edge(sysclk1) then
			case currentState is
				when init => 
					pc <= X"00"; 
					currentState <= fetch_state; 
				when fetch_state =>
					IR <= memory(to_integer(unsigned(pc))); 
					pc <= std_logic_vector(unsigned(pc) + 1); 
					currentState <= decode_state; 
				when decode_state =>
					currentState <= execute_state;
				when execute_state =>
					currentState <= write_back_state;
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
					     else IR20_16 when  (IR_decode_branch or IR_decode_alu_immed or  IR_decode_mem);
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
