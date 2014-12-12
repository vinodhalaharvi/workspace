library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  flop is
        port (
                clk : in std_logic; 
                mem_reset : in std_logic; 
                mem_addressready : in std_logic; 
                mem_dataready_inv : out std_logic; 
                fsmStateCodeSeg : out std_logic_vector(6 downto 0) 
        );
end entity flop;

architecture flop_arch of flop  is
        type states is (Init, WaitForMemAddrReadyHigh, SetMemDataReadyInvHigh
                        , WaitForMemAddrReadyLow, SetMemDataReadyInvLow); 
        signal fsmStateCode : std_logic_vector(3 downto 0); 
        signal currentState : states := Init; 
begin
        FSM :
        process(clk, mem_reset, mem_addressready) is
        begin
                if mem_reset = '0' then
                        currentState <= Init;
					 elsif falling_edge(clk) then
                        case currentState is
                                when Init =>
                                        currentState <= WaitForMemAddrReadyHigh; 
                                when WaitForMemAddrReadyHigh =>
                                        if mem_addressready = '1' then 
                                                 currentState <= SetMemDataReadyInvHigh; 
                                        end if; 
                                when SetMemDataReadyInvHigh =>
                                        mem_dataready_inv <= '1'; 
                                        currentState <= WaitForMemAddrReadyLow; 
                                when WaitForMemAddrReadyLow =>
                                        currentState <= SetMemDataReadyInvLow; 
                                when SetMemDataReadyInvLow =>
                                        mem_dataready_inv <= '0'; 
                                        currentState <= Init; 
                        end case;
                end if;
        end process;

        sevenSegTesting0_inst: entity sevenSegTesting port map (
                        bcd => fsmStateCode, 
                        seg => fsmStateCodeSeg
                );
        with currentState select
                fsmStateCode <=
               "0000" when Init,
               "0001" when WaitForMemAddrReadyHigh,
               "0010" when SetMemDataReadyInvHigh,
               "0011" when WaitForMemAddrReadyLow,
               "0100" when SetMemDataReadyInvLow,
               "1111" when others;
end architecture flop_arch;
