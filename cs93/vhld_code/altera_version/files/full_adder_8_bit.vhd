library ieee;
use ieee.std_logic_1164.all;

entity full_adder_8_bit is
	port (
		a : in std_logic_vector(7 downto 0); 
		b : in std_logic_vector(7 downto 0); 
		cin : in std_logic; 
		sum : out std_logic_vector(7 downto 0); 
		cout : out std_logic
	);
end entity full_adder_8_bit;


architecture full_adder_8_bit_arch of full_adder_8_bit is
	component  full_adder_1_bit
		port (
			a : in std_logic; 
			b : in std_logic; 
			cin : in std_logic; 
			sum : out std_logic; 
			cout : out std_logic
		);
	end component;
	signal temp: std_logic_vector(7 downto 0) := (others => '0');
begin
	BIT0: full_adder_1_bit port map( a => a(0), b => b(0), cin => cin, sum => sum(0), cout => temp(0) );
	BIT1: full_adder_1_bit port map( a => a(1), b => b(1), cin => temp(0), sum => sum(1), cout => temp(1) );
	BIT2: full_adder_1_bit port map( a => a(2), b => b(2), cin => temp(1), sum => sum(2), cout => temp(2));
	BIT3: full_adder_1_bit port map( a => a(3), b => b(3), cin => temp(2), sum => sum(3), cout => temp(3) );
	BIT4: full_adder_1_bit port map( a => a(4), b => b(4), cin => temp(3), sum => sum(4), cout => temp(4) );
	BIT5: full_adder_1_bit port map( a => a(5), b => b(5), cin => temp(4), sum => sum(5), cout => temp(5) );
	BIT6: full_adder_1_bit port map( a => a(6), b => b(6), cin => temp(5), sum => sum(6), cout => temp(6) );
	BIT7: full_adder_1_bit port map( a => a(7), b => b(7), cin => temp(6), sum => sum(7), cout => cout );
end architecture full_adder_8_bit_arch;
