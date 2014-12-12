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
	op1: process 
	begin 
		wait for 1  ms; 
		IR <= X"0C000002"; 
		wait for 1 ms; 
		IR <= X"20080001"; 
		wait for 1  ms; 
		wait; 
	end process op1; 


end architecture aluSim_tb_arch;
