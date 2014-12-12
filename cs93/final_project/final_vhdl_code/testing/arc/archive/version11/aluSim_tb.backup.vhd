library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  aluSim_tb is
end entity aluSim_tb;

architecture aluSim_tb_arch of aluSim_tb  is
	signal sysclk1 : std_logic := '0';

	signal IR : std_logic_vector(31 downto 0); 
	alias IR31_26 is IR(31 downto 26);
	alias IR25_21 is IR(25 downto 21);
	alias IR20_16 is IR(20 downto 16);
	alias IR15_11 is IR(15 downto 11);
	alias IR10_6 is IR(10 downto 6);
	alias IR5_0 is IR(5 downto 0);


	-- for debugging only	
	signal ALU_result : std_logic_vector(31 downto 0); 
	signal t0 : std_logic_vector(31 downto 0); 
	signal t1 : std_logic_vector(31 downto 0); 
	signal t2 : std_logic_vector(31 downto 0); 
	signal t3 : std_logic_vector(31 downto 0); 

	signal ALU_Z : std_logic ; 
	signal ALU_C : std_logic; 
	signal GPR_left_operand : std_logic_vector(31 downto 0); 
	signal GPR_right_operand : std_logic_vector(31 downto  0); 
	signal fsmStateCode : std_logic_vector(5 downto 0); 
	type states is (init, fetch_state, increment_pc, decode_state, write_back_state); 
	signal reset : std_logic := '0';
	type memory_array is array(0 to 255) of std_logic_vector(31 downto 0);
	signal pc : std_logic_vector(7 downto 0) := X"00"; 
	signal currentState : states := init; 
	signal memory : memory_array := (
		X"0C000002", 
		X"20080002", 
		X"20090003", 
		X"01285020", 
		others => (others => 'X')
	);
begin
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
					currentState <= increment_pc; 
				when increment_pc =>
					pc <= std_logic_vector(unsigned(pc) + 1); 
					currentState <= decode_state; 
				when decode_state =>
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
			GPR(8) := std_logic_vector(unsigned(GPR(8)) + 1);
			GPR(9) := std_logic_vector(unsigned(GPR(9)) + 1);
			GPR(10) := std_logic_vector(unsigned(GPR(10)) + 1);
			GPR(11) := std_logic_vector(unsigned(GPR(11)) + 1);
			if currentState = write_back_state and unsigned(IR15_11) /= 0 then
				GPR(to_integer(unsigned(IR15_11))) := ALU_result;
			elsif currentState = decode_state then
				GPR_left_operand <= GPR(to_integer(unsigned(IR25_21)));
				GPR_right_operand <= GPR(to_integer(unsigned(IR20_16)));
			end if;
		end if;
	end process GPR_mem;


	gen_clk: process is
	begin
		--give me 10 clock cycles
		for i in 1 to 20 loop 
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
	       "000010" when increment_pc,
	       "000011" when decode_state,
	       "000100" when write_back_state,
	       "111111" when others;
end architecture aluSim_tb_arch;
