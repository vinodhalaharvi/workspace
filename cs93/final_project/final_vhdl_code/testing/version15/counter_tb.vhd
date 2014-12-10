library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  counter_tb is
end entity counter_tb;

architecture counter_tb_arch of counter_tb  is
	signal clk : std_logic := '0';
	signal reset : std_logic := '0';
	signal count : std_logic_vector(7 downto 0) := X"00";
begin
	counter_test: entity counter port map (clk => clk, reset => reset, count => count);       
	process is
	begin
		for i in 1 to 50 loop
			wait for 1 ms;
			clk <= '1';
			wait for 1 ms;
			clk <= '0';
		end loop;
		wait;
	end process;
end architecture counter_tb_arch;
