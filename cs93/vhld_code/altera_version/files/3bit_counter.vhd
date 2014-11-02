library ieee; 
use ieee.std_logic_1164.all; 

entity bit_counter_3 is 
port (
	clk : in std_logic;
	reset : in std_logic; 
	count : out std_logic_vector (2 downto 0)
	);
end entity bit_counter_3; 

architecture arch of bit_counter_3 is 
	signal internal_count : std_logic_vector (2 downto 0);
	signal next_count : std_logic_vector (2 downto 0) := "00";
begin
	count <= internal_count; 
	
	with internal_count select
	next_count <= "001" when "000", 
	"010" when "001", 
	"011" when "010", 
	"100" when "011",
	"101" when "100", 
	"110" when "101", 
	"111" when "110",
	"000" when "111";

	process (clk, reset) is 
	begin
		if reset = '1' then
			internal_count <= "000";
		elsif rising_edge(clk) then
				internal_count <= next_count; 
		end if; 
	end process; 
end architecture arch; 
