LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

PACKAGE altera_counter_def IS
   COMPONENT altera_f_add8 
    PORT(
        x_in    :    IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        y_in    :    IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        c_in    :    IN STD_LOGIC;
        sum     :    OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
        c_out   :    OUT STD_LOGIC);
   END COMPONENT;
END altera_counter_def;
