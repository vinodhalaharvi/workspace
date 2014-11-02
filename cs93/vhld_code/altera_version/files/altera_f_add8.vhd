LIBRARY altera;
USE altera.maxplus2.carry;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

LIBRARY WORK;
USE WORK.altera_user_def.ALL;

ENTITY altera_f_add8 IS    
    PORT(
        x_in    :    IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        y_in    :    IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        c_in    :    IN STD_LOGIC;
        sum     :    OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
        c_out   :    OUT STD_LOGIC);
END altera_f_add8;

ARCHITECTURE struct OF altera_f_add8 IS
SIGNAL im  :    STD_LOGIC_VECTOR(6 DOWNTO 0);
SIGNAL imi :    STD_LOGIC_VECTOR(6 DOWNTO 0);
BEGIN
    c0   : altera_full_add 
           PORT MAP (x_in(0),y_in(0),c_in,sum(0),im(0));
    c01  : carry 
           PORT MAP (im(0),imi(0));
    c    : FOR i IN 1 TO 6 GENERATE
            c1to6:  altera_full_add PORT MAP (x_in(i),y_in(i),
            imi(i-1),sum(i),im(i));
            c11to16: carry PORT MAP (im(i),imi(i));
           END GENERATE;
    c7   : altera_full_add PORT MAP (x_in(7),y_in(7),
           imi(6),sum(7),c_out);
END struct;
