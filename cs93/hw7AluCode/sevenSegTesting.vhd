--Vinod Halaharvi
library ieee;
use ieee.std_logic_1164.all;

entity  sevenSegTesting is
        port ( 
                bcd  : in std_logic_vector(3 downto 0);
                seg  : out std_logic_vector(6 downto 0)
        );
end entity sevenSegTesting;


architecture sevenSegTesting_arch of sevenSegTesting  is
        attribute chip_pin : string;
        attribute chip_pin of bcd : signal is "AB28, AC28, AC27, AD27";
        attribute chip_pin of seg : signal is "G18, F22, E17, L26, L25, J22, H22"; 
begin
        with bcd select
                seg <= 
                        "0000001" when "0000", 
                        "1001111" when "0001", 
                        "0010010" when "0010", 
                        "0000110" when "0011", 
                        "1001100" when "0100", 
                        "0100100" when "0101", 
                        "0100000" when "0110",
							   "0001111" when "0111",
                        "0000000" when "1000", 
                        "0000100" when "1001", 
                        "0001000" when "1010", 
                        "1100000" when "1011", 
                        "0110001" when "1100", 
                        "1000010" when "1101", 
                        "0110000" when "1110", 
                        "0111000" when "1111", 
                        "1111111" when others;
end architecture sevenSegTesting_arch;