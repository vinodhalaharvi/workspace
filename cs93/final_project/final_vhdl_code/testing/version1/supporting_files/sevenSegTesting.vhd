library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
entity  mycpu is
	port (
		     clk : in std_logic; 
		     mem_data_read : in std_logic_vector(31 downto 0);
		     mem_dataready_inv : in std_logic;
		     mem_ready : in std_logic;


		     mem_addr : buffer std_logic_vector(20 downto 0);
		     mem_data_write : buffer std_logic_vector(31 downto 0);
		     mem_rw : buffer std_logic;
		     mem_sixteenbit : buffer std_logic;
		     mem_thirtytwobit : buffer std_logic;
		     mem_addressready : buffer std_logic;


		     outputData : out std_logic_vector(31 downto 0); 
		     fsmStateCode : out std_logic_vector(3 downto 0)
	     ); 
end entity mycpu;

architecture mycpu_arch of mycpu  is
	signal mem_data_read_internal : std_logic_vector(31 downto 0) := X"00000000";
	type states is (
	Init, WaitForMemDataReadyInvHigh, 
	WaitForMemDataReadyInvLow,	
	SetControlAndDataInputs,
	ReadInputData);
	signal currentState : states := Init; 
begin
	FSM :
	process(clk, mem_data_read, mem_dataready_inv, mem_ready) is
	begin
		if rising_edge(clk) then
			case currentState is
				when Init =>
					currentState <= WaitForMemDataReadyInvHigh;
					if mem_rw = '0' then
						mem_rw <= '1';
					else 
						mem_rw <= '0';
					end if;
				when WaitForMemDataReadyInvHigh =>
					if mem_dataready_inv = '1'  then 
						currentState <= SetControlAndDataInputs; 
					end if;
				when SetControlAndDataInputs =>
					if mem_rw = '1' then 
							--mem_addr <= '0' & X"0D1CE"; 
						mem_addr <= '0' & X"00010";
						mem_sixteenbit <= '1';
						mem_thirtytwobit <= '0';
						mem_addressready <= '1';
						mem_data_write(15 downto 0) <= mem_data_read_internal(15 downto 0);
						currentState <= WaitForMemDataReadyInvLow; 
					else
							--mem_addr <= '0' & X"0D1CE"; 
						mem_addr <= '0' & X"00000";
						mem_sixteenbit <= '1';
						mem_thirtytwobit <= '0';
						mem_addressready <= '1';
						currentState <= WaitForMemDataReadyInvLow; 
					end if;
				when WaitForMemDataReadyInvLow =>
					if mem_dataready_inv = '0' then 
						if mem_rw = '0' then 
							currentState <= ReadInputData; 
						else
							mem_addressready <=  '0'; 
							currentState <= Init; 
						end if;
					end if; 
				when ReadInputData =>
					mem_data_read_internal(15 downto 0) <= mem_data_read(15 downto 0);
					mem_addressready <=  '0'; 
					currentState <= Init; 
			end case;
		end if;
	end process;

	outputData <= mem_data_read_internal; 
	with currentState select
		fsmStateCode <=
	       "0000" when Init,
	       "0001" when WaitForMemDataReadyInvHigh,
	       "0010" when SetControlAndDataInputs,
	       "0011" when WaitForMemDataReadyInvLow,
	       "0100" when ReadInputData,
	       "1111" when others;

end architecture mycpu_arch;




