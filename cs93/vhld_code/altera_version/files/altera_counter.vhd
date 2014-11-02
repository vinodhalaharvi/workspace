library ieee;
use ieee.std_logic_1164.all;
LIBRARY WORK;
USE WORK.altera_counter_def.ALL;

entity altera_counter is
	port(
		clk : in std_logic;
		reset : in std_logic;
		count : out std_logic_vector(7 downto 0)
	);
end;

architecture arch of altera_counter is
	signal next_count : std_logic_vector(7 downto 0);
	signal count_internal : std_logic_vector(7 downto 0) := "00000000"; -- init to 0
	signal ignore : std_logic := '0'; -- init to 0
begin

	count <= count_internal;
	incrCounter: altera_f_add8 port map (x_in => count_internal, 
							y_in => "00000001", c_in => '0', sum => next_count, c_out => ignore);	
	process(clk, reset) is
	begin
		if reset = '0' then
			count_internal <= "00000000";
		elsif clk'event and clk = '0' then
		--elsif falling_edge(clk) then
			count_internal <= next_count;
		end if;
	end process;

end;


							
