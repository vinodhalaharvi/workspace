library ieee;
use ieee.std_logic_1164.all;

entity Counter is
  port ( reset, count, downUp: in std_logic;
         counter: buffer integer range 0 to 16#FFFF#);
end entity Counter;

-- The pushbuttons are active-low (i.e., the signals are normally high and
--      become low when the pushbuttons are pressed).  They *are* debounced.

-- The slide switches assert low in the down position and assert high in the
--      up position.  They are *not* debounced.

-- The segments of the seven-segment LEDs are illuminated when driven with a
--      low signal.

-- Assign pins as follows:
--      Signal        Pin       Device
--      count         PIN_U30   KEY2 second to leftmost pushbutton
--      counter[15]   PIN_G2    HEX7_DP leftmost digit, decimal point
--      counter[14]   PIN_G1    HEX7_D[6] leftmost digit, segment 6
--      counter[13]   PIN_H3    HEX7_D[5] leftmost digit, segment 5
--      counter[12]   PIN_H2    HEX7_D[4] leftmost digit, segment 4
--      counter[11]   PIN_H1    HEX7_D[3] leftmost digit, segment 3
--      counter[10]   PIN_J2    HEX7_D[2] leftmost digit, segment 2
--      counter[9]    PIN_J1    HEX7_D[1] leftmost digit, segment 1
--      counter[8]    PIN_K3    HEX7_D[0] leftmost digit, segment 0
--      counter[7]    PIN_K2    HEX6_DP second digit, decimal point
--      counter[6]    PIN_E4    HEX6_D[6] second digit, segment 6
--      counter[5]    PIN_F4    HEX6_D[5] second digit, segment 5
--      counter[4]    PIN_G4    HEX6_D[4] second digit, segment 4
--      counter[3]    PIN_H8    HEX6_D[3] second digit, segment 3
--      counter[2]    PIN_H7    HEX6_D[2] second digit, segment 2
--      counter[1]    PIN_H4    HEX6_D[1] second digit, segment 1
--      counter[0]    PIN_H6    HEX6_D[0] second digit, segment 0
--      downUp        PIN_L8    SW17 Leftmost slide switch
--      reset         PIN_U29   KEY3 leftmost pushbutton

-- Segment map
--
--         0
--       -----
--      |     |
--    5 |     | 1
--      |  6  |
--       -----
--      |     |
--    4 |     | 2
--      |     |
--       -----   O DP
--         3
--

architecture behavioral of Counter is
begin
  upDownCounterBehav: process(reset, count, downUp, counter)
  begin
    if reset = '0' then
      counter <= 0;
    else
      if count'event and count = '0' then
        if downUp = '0' then
          counter <= counter-1;
        else
          counter <= counter+1;
        end if;
      end if;
    end if;
  end process upDownCounterBehav;
end architecture behavioral;