library ieee; 
use ieee.std_logic_1164.all; 

entity mux is 
port (
	input : in std_logic_vector(3 downto 0);
	sel : in std_logic_vector(1 downto 0);
	y : out std_logic
);
end entity mux;

architecture arch of mux is 
begin
	--y <= input(0) when sel is "00" else
		--	input(1) when sel is "01" else
		--	input(2) when sel is "01" else
		--	input(4) when sel is "11"; 
			
	with sel select
	y <= input(0) when "00", 
	input(1) when "01", 
	input(2) when "10", 
	input(3) when "11"; 
end; 