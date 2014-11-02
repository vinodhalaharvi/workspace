library ieee;
use ieee.std_logic_1164.all;

entity bit_counter_8_new is
  port ( reset, count: in std_logic;
         --counter: buffer integer range 0 to 16#FFFF#
			counter : buffer std_logic_vector (7 downto 0)
			);
end entity bit_counter_8_new;

architecture bit_counter_8_new_arch of bit_counter_8_new is
	signal internal_count : std_logic_vector (7 downto 0)  := "00000000";
	signal next_count : std_logic_vector (7 downto 0);
	signal one : std_logic_vector (7 downto 0) := "00000001";
	signal zero : std_logic := '0';
	signal ignore : std_logic ;

begin
  incr: work.full_adder_8_bit port map(a=>internal_count, b=> one, cin=> zero, sum=>counter, cout=>ignore);
  upDownCounterBehav: process(reset, coun)
  begin
    if reset = '0' then
      counter <= "00000000";
    else
      if count'event and count = '0' then
			counter <= counter;
      end if;
    end if;
  end process upDownCounterBehav;
end architecture bit_counter_8_new_arch;