library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
entity  shell is
        port (
                     clk : in std_logic;
							mem_reset : in std_logic; 
                     fsmStateCodeSeg1 : out std_logic_vector(6 downto 0);
                     fsmStateCodeSeg2 : out std_logic_vector(6 downto 0)
             );
end entity shell;
architecture shell_arch of shell  is  
        signal mem_addressready : std_logic := '0';
        signal mem_dataready_inv : std_logic := '0';
        attribute chip_pin : string;
        attribute chip_pin of clk : signal is "M23";
		  attribute chip_pin of mem_reset : signal is "M21";
		  attribute chip_pin of fsmStateCodeSeg1 : signal is " G18, F22, E17, L26, L25, J22, H22";
		  attribute chip_pin of fsmStateCodeSeg2 : signal is " M24, Y22, W21, W22, W25, U23, U24";
begin         
        flop_inst : entity  flop port map (
                        clk  => clk, 
                        mem_reset => mem_reset, 
                        mem_dataready_inv => mem_dataready_inv, 
                        mem_addressready => mem_addressready, 
                        fsmStateCodeSeg => fsmStateCodeSeg1
                );  

        flip_inst : entity  flip port map ( 
                        clk  => clk,
                        mem_reset => mem_reset,
                        mem_dataready_inv => mem_dataready_inv,
                        mem_addressready => mem_addressready,
                        fsmStateCodeSeg => fsmStateCodeSeg2
                );
end architecture shell_arch;
