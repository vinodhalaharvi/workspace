library ieee;  use ieee.std_logic_1164.all;
use work.dlx_types.all;

entity dlx is

  generic ( Tpd_clk_out : delay_length;
            debug : dlx_debug_control := none );

  port ( phi1, phi2 : in std_logic;
         reset : in std_logic;
         halt : out std_logic;
         a : out dlx_address;
         d : inout dlx_word;
         width : out dlx_mem_width;
         write_enable : out std_logic;
         ifetch : out std_logic;
         mem_enable : out std_logic;
         ready : in std_logic );

end entity dlx;
