LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
PACKAGE altera_user_def IS
   COMPONENT altera_full_add 
      PORT(
          a      : IN STD_LOGIC;
          b      : IN STD_LOGIC;
          c_in   : IN STD_LOGIC;
          sum    : OUT STD_LOGIC;
          c_out  : OUT STD_LOGIC);
   END COMPONENT;
END altera_user_def;





