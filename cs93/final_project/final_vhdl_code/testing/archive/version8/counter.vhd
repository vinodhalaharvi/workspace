library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity  counter is
	port (
		clk : in std_logic ;
		reset : in std_logic ; 
		count : out std_logic_vector(7 downto 0)
	); 
end entity counter;

architecture counter_arch of counter  is
	signal count_internal : std_logic_vector(7 downto 0) := X"00";

begin
	count <= count_internal; 
	update : process (clk) is
	begin
		if reset = '1' then 
			count_internal <= X"00";
		elsif rising_edge(clk) then
			 count_internal <= std_logic_vector(unsigned(count_internal) + 1);
		end if;
	end process update;
end architecture counter_arch;




