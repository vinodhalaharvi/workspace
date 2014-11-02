library ieee; 
use ieee.std_logic_1164.all;  


entity bit_counter_8 is 
port (
	clk : in std_logic;
	reset : in std_logic; 
	counter : out std_logic_vector (7 downto 0)
	);
end entity bit_counter_8; 

architecture arch of bit_counter_8 is 
	signal internal_count : std_logic_vector (7 downto 0)  := "11111111";
	signal next_count : std_logic_vector (7 downto 0) := "00000000";
	signal one : std_logic_vector (7 downto 0) := "00000001";
	signal zero : std_logic := '0';
	signal ignore : std_logic ;

	
	component full_adder_8_bit 
		port (
		a : in std_logic_vector(7 downto 0); 
		b : in std_logic_vector(7 downto 0); 
		cin : in std_logic; 
		sum : out std_logic_vector(7 downto 0); 
		cout : out std_logic
	);
	end component full_adder_8_bit; 
	
begin
	counter <= internal_count; 
	
	 add:  full_adder_8_bit port map(a=>internal_count, b=> one, cin=> zero, sum=>next_count, cout=>ignore);
	 --next_count <= "00000001"; 
	
	--with internal_count select
	--next_count <= "001" when "000", 
	--"010" when "001", 
	--"011" when "010", 
	--"100" when "011",
	--"101" when "100", 
	--"110" when "101", 
	--"111" when "110",
	--"000" when "111";

	incrementCounter: process (clk, reset) is 
	begin
		if reset = '1' then
			internal_count <= "00000000";
		elsif rising_edge(clk) then
				internal_count <= next_count; 
		end if; 
	end process incrementCounter; 
end architecture arch; 
