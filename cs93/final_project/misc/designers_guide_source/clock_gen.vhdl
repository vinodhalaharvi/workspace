library ieee;  use ieee.std_logic_1164.all;

entity clock_gen is

  generic ( Tpw : delay_length;
      	    Tps : delay_length );

  port ( phi1, phi2 : out std_logic;
      	 reset : out std_logic );

end entity clock_gen;
