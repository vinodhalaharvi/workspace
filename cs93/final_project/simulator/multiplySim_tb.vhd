library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  multiplySim_tb is
end entity multiplySim_tb;

architecture multiplySim_tb_arch of multiplySim_tb  is
	signal sysclk1 :  std_logic;
	signal start :  std_logic; 
	signal A :  std_logic_vector(31 downto 0) :=  X"00000007";
	signal B :  std_logic_vector(31 downto 0) :=  X"00000008";
	signal done :  std_logic; 

	signal result :  std_logic_vector(63 downto 0) :=  ( others => '0');
	type states is (init_state, mul_state, done_state); 
	signal currentState : states := init_state; 
	signal fsmStateCode : std_logic_vector(2 downto 0); 
begin

	multiplySim_inst : entity  multiplySim 
		port map (
			sysclk1 => sysclk1,
			start => start,
			A => A,
			B => B,
			done => done,
			result => result
		); 

	FSM :
	process(sysclk1) is
	begin
		if rising_edge(sysclk1) then
			case currentState is
				when init_state =>
					start <= '1';
					currentState <= mul_state; 
				when mul_state =>
					if done = '1' then 
						currentState <= done_state; 
					end if;
				when done_state =>
					currentState <= done_state; 
			end case;
		end if;
	end process;

	gen_clk: process is
	begin
		for i in 1 to 40 loop 
			wait for 1 ms;
			sysclk1 <= '1';
			wait for 1 ms;
			sysclk1 <= '0';
		end loop;
		wait;
	end process gen_clk;

	with currentState select
		fsmStateCode <=
	       "000" when init_state,
	       "001" when mul_state,
	       "010" when done_state,
	       "111" when others;

end architecture multiplySim_tb_arch;
