library ieee;
use ieee.std_logic_1164.all;
package full_adder_1_bit_def is
	component full_adder_1_bit
		port (
			a : in std_logic; 
			b : in std_logic; 
			cin : in std_logic; 
			sum : out std_logic; 
			cout : out std_logic
		);
	end component full_adder_1_bit;
end package full_adder_1_bit_def; 
