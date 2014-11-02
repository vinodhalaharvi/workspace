library ieee;
use ieee.std_logic_1164.all;
package full_adder_8_bit_def is 
	component full_adder_8_bit
	port (
		a : in std_logic_vector(7 downto 0); 
		b : in std_logic_vector(7 downto 0); 
		cin : in std_logic; 
		sum : out std_logic_vector(7 downto 0); 
		cout : out std_logic
	);
	end component full_adder_8_bit; 
end package full_adder_8_bit_def;
