library ieee;
use ieee.std_logic_1164.all;
package bcd_to_7_segment_def is  
        component bcd_to_7_segment
        port (
                bcd : in std_logic_vector (3 downto 0); 
                sevenseg : out std_logic_vector (6 downto 0)
        );  
        end component bcd_to_7_segment;
end package bcd_to_7_segment_def;