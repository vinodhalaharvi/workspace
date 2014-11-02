library ieee;
use ieee.std_logic_1164.all;

entity full_adder_1_bit is
	port (
		a : in std_logic; 
		b : in std_logic; 
		cin : in std_logic; 
		sum : out std_logic; 
		cout : out std_logic
	);
end entity full_adder_1_bit;

architecture full_adder_1_bit_arch of full_adder_1_bit is
begin
	sum <= a xor b xor cin; 
	cout <= ((a and b) or (cin and (a or b)));
end architecture full_adder_1_bit_arch;
