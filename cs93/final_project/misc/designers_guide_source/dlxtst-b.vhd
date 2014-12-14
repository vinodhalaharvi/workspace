library ieee;  use ieee.std_logic_1164.all;

architecture bench of dlx_test is

  use work.dlx_types.all;

  component clock_gen is
    port ( phi1, phi2 : out std_logic;
      	   reset : out std_logic );
  end component clock_gen;

  component memory is
    port ( phi1, phi2 : in std_logic;
      	   a : in dlx_address;
	   d : inout dlx_word;
	   width : in dlx_mem_width;
	   write_enable : in std_logic;
           burst : in std_logic := '0';
	   mem_enable : in std_logic;
	   ready : out std_logic );
  end component memory;

  component dlx is
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
  end component dlx;

  signal phi1, phi2, reset : std_logic;
  signal a : dlx_address;
  signal d : dlx_word;
  signal halt : std_logic;
  signal width : dlx_mem_width;
  signal write_enable, mem_enable, ifetch, ready : std_logic;

begin

  cg : component clock_gen
    port map ( phi1 => phi1, phi2 => phi2, reset => reset );

  mem : component memory
    port map ( phi1 => phi1, phi2 => phi2,
	       a => a, d => d,
	       width => width, write_enable => write_enable, burst => open,
	       mem_enable => mem_enable, ready => ready );

  proc : component dlx
    port map ( phi1 => phi1, phi2 => phi2, reset => reset, halt => halt,
      	       a => a, d => d,
	       width => width, write_enable => write_enable, ifetch => ifetch,
	       mem_enable => mem_enable, ready => ready );

end architecture bench;
