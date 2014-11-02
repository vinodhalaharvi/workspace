library ieee;
use ieee.std_logic_1164.all;
library work;
use work.full_adder_8_bit_def.all;
use work.bcd_to_7_segment_def.all; 

entity counter_8_bit is
	port(
		clk : in std_logic;
		reset : in std_logic;
		count : out std_logic_vector(7 downto 0);
		seven_seg_count_7 : out std_logic_vector(6 downto 0) := "0000000";
		seven_seg_count_6 : out std_logic_vector(6 downto 0) := "0000000"
	);
end;

architecture arch of counter_8_bit is
	signal next_count : std_logic_vector(7 downto 0);
	signal count_internal : std_logic_vector(7 downto 0) := "00000000"; -- init to "00000000"
	signal ignore : std_logic := '0'; -- init to 0
begin
	count <= count_internal;
	bcdToSevenSeg_7: bcd_to_7_segment port map (bcd => count_internal(7 downto 4), sevenseg => seven_seg_count_7);
	bcdToSevenSeg_6: bcd_to_7_segment port map (bcd => count_internal(3 downto 0), sevenseg => seven_seg_count_6);

	incrCounter: full_adder_8_bit port map (a => count_internal, 
		b => "00000001", cin => '0', sum => next_count, cout => ignore);	
	
	process(clk, reset) is
	begin
		if reset = '0' then
			count_internal <= "00000000";
		elsif clk'event and clk = '0' then
			count_internal <= next_count;
		end if;
	end process;
end;


							
