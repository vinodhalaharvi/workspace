library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  aluSim_tb is
end entity aluSim_tb;

architecture aluSim_tb_arch of aluSim_tb  is
	signal IR : std_logic_vector(31 downto 0); 
	signal ALU_result : std_logic_vector(31 downto 0); 
	signal ALU_Z : std_logic ; 
	signal ALU_C : std_logic; 
begin
	aluSim_test: entity aluSim 
	port map (
		  IR => IR, 
		  ALU_C => ALU_C,
		  ALU_Z => ALU_Z,
		  ALU_result => ALU_result
	  );       

	
	operation_1: process 
	begin 
		wait for 0  ns; IR <= "0000"; 
		wait for 10 ns; IR <= "0001"; 
		wait for 10 ns; IR <= "0010"; 
		wait for 10 ns; IR <= "0011"; 
		wait for 10 ns; IR <= "0100"; 
		wait for 10 ns; IR <= "0101"; 
		wait for 10 ns; IR <= "0110"; 
		wait for 10 ns; IR <= "0111"; 
		wait for 10 ns; IR <= "1000"; 
		wait for 10 ns; IR <= "1001"; 
		wait for 10 ns; IR <= "1010"; 
		wait for 10 ns; IR <= "1011"; 
		wait for 10 ns; IR <= "1100"; 
		wait for 10 ns; IR <= "1101"; 
		wait for 10 ns; IR <= "1110"; 
		wait for 10 ns; IR <= "1111"; 
		wait; 
	end process operation_1; 

end architecture aluSim_tb_arch;
