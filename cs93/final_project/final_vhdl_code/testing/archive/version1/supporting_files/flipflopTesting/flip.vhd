library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity  flip is
        port (
                clk : in std_logic; 
                mem_reset : in std_logic; 
                mem_dataready_inv : in std_logic; 
                mem_addressready : out std_logic; 
                fsmStateCodeSeg : out std_logic_vector(6 downto 0) 
        );
end entity flip;

architecture flip_arch of flip  is
        type states is (Init, WaitForMemDataReadyInvHigh, SetMemAddrReadyHigh
                        , WaitForMemDataReadyInvLow, SetMemAddrReadyLow); 
        signal fsmStateCode : std_logic_vector(3 downto 0); 
        signal currentState : states := Init; 
begin
        FSM :
        process(clk, mem_reset, mem_dataready_inv) is
        begin
                if mem_reset = '0' then
                        currentState <= Init;
                elsif falling_edge(clk) then
                        case currentState is
                                when Init =>
													 mem_addressready <= '1';
                                        currentState <= WaitForMemDataReadyInvHigh; 
                                when WaitForMemDataReadyInvHigh =>
                                        if mem_dataready_inv = '1' then 
                                                 currentState <= SetMemAddrReadyHigh; 
                                        end if; 
                                when SetMemAddrReadyHigh =>
                                        mem_addressready <= '1'; 
                                        currentState <= WaitForMemDataReadyInvLow; 
                                when WaitForMemDataReadyInvLow =>
                                        currentState <= SetMemAddrReadyLow; 
                                when SetMemAddrReadyLow =>
                                        mem_addressready <= '0'; 
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
               "0001" when WaitForMemDataReadyInvHigh,
               "0010" when SetMemAddrReadyHigh,
               "0011" when WaitForMemDataReadyInvLow,
               "0100" when SetMemAddrReadyLow,
               "1111" when others;
end architecture flip_arch;

