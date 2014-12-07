--Vinod Halaharvi
library ieee; use ieee.std_logic_1164.all;
library work; use work.all; 
use ieee.numeric_std.all;

entity  simpleUpCounterTesting is
        port (
                reset  : in std_logic;
                clk  : in std_logic;
                seg1  : out std_logic_vector(6 downto 0);
                seg2  : out std_logic_vector(6 downto 0)
        );
end entity simpleUpCounterTesting;

architecture simpleUpCounterTesting_arch of simpleUpCounterTesting  is
        signal count  : std_logic_vector(7 downto 0) := X"00";
        attribute chip_pin : string;
        attribute chip_pin of clk : signal is "M23";
        attribute chip_pin of seg1 : signal is "G18, F22, E17, L26, L25, J22, H22";
        attribute chip_pin of seg2 : signal is "M24, Y22, W21, W22, W25, U23, U24";
        attribute chip_pin of reset : signal is "AB28"; 
begin
        sevenSegTesting0_inst: entity sevenSegTesting port map (
                        bcd => count(7 downto 4),
                        seg => seg2
                );
                                         
        sevenSegTesting1_inst: entity sevenSegTesting port map (
                        bcd => count(3 downto 0),
                        seg => seg1
                );
        update : process (clk, reset) is
        begin
                if reset = '1' then 
                        count <= X"00";
                elsif rising_edge(clk) then
                        count <= std_logic_vector(unsigned(count) + 1); 
                end if; 
                if rising_edge(clk) then
                        count <= std_logic_vector(unsigned(count) + 1);
                end if;
        end process update;
end architecture simpleUpCounterTesting_arch;
