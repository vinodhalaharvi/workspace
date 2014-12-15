library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity multiplySim is
	port (
		 sysclk1 : in std_logic;
		 start :  in std_logic; 
		 A :  in std_logic_vector(31 downto 0) :=  X"00000007";
		 B :  in std_logic_vector(31 downto 0) :=  X"00000008";
		 done : out  std_logic; 
		 result : out  std_logic_vector(63 downto 0) := (others => '0')
	); 
end entity multiplySim;

architecture multiplySim_arch of multiplySim  is
	type states is (init_state, done_state); 
	signal currentState : states := init_state; 
	signal fsmStateCode : std_logic_vector(2 downto 0);
begin
	mul : process is 
		variable result_internal :  std_logic_vector(63 downto 0) :=  (others => '0');
	begin
		wait until rising_edge(sysclk1); 
		case currentState is
			when init_state =>
				if start = '1' then
					done <= '0'; 
					--result_internal :=  (others => '0'); 
					for i in A'range loop
						wait until rising_edge(sysclk1);
						if A(i) = '1' then 
							result_internal(A'length downto 0) := 
								std_logic_vector(unsigned(result_internal(31 downto 0) & '0') + unsigned(B)); 
						else 
							result_internal(A'length downto 0) := (result_internal(31 downto 0) & '0'); 
						end if; 
					end loop;
					done <= '1';
					currentState <= done_state; 
					result  <= result_internal; 
				end if;
			when done_state =>
				currentState <= done_state; 
		end case;
	end process mul;

	with currentState select
		fsmStateCode <=
		       "000" when init_state,
		       "001" when done_state,
		       "111" when others;
end architecture multiplySim_arch;
