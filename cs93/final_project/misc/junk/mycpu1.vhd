library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity  mycpu is
	port (
		clk : in std_logic; 
		mem_data_read : in std_logic_vector(31 downto 0);
		mem_dataready_inv : in std_logic;
		mem_ready : in std_logic;
		mem_addr : out std_logic_vector(20 downto 0);
		mem_data_write : out std_logic_vector(31 downto 0);
		mem_rw : out std_logic;
		mem_sixteenbit : out std_logic;
		mem_thirtytwobit : out std_logic;
		mem_addressready : out std_logic;
		mem_reset : out std_logic;
		clock_hold : out std_logic;
		clock_step : out std_logic;
		clock_divide_limit : out std_logic_vector(19 downto 0) := (others => '0');
		mem_suspend : out std_logic;
		outputData : out std_logic_vector(31 downto 0); 
		fsmStateCode : out std_logic_vector(5 downto 0)

	); 
end entity mycpu;

architecture mycpu_arch of mycpu  is
	signal mem_data_read_internal : std_logic_vector(31 downto 0) := X"00000000";
	type states is (
			Init, WaitForMemDataReadyInvHigh, 
			SetReadControlAndDataInputs, 
			WaitForMemDataReadyInvLow, ReadInputData, 
			SetMemAddrReadyLow, 
			WaitForMemDataReadyInvHigh);
	signal currentState : states := Init; 
begin
	FSM :
	process(clk, mem_reset) is
	begin
		if mem_reset = '1' then
			currentState <= Init;
		elsif rising_edge(clk) then
			case currentState is
				when Init =>
					currentState <= WaitForMemDataReadyInvHigh; 
				when WaitForMemDataReadyInvHigh =>
					if mem_dataready_inv = '1'  then 
						 currentState <= SetReadControlAndDataInputs;
					 end if;
				when SetReadControlAndDataInputs =>
					mem_addr <= '0' & X"0D1CE"; 
					mem_rw <= '0';
					mem_sixteenbit <= '1';
					mem_thirtytwobit <= '0';
					mem_addressready <= '1';
					currentState <= WaitForMemDataReadyInvLow; 
				when WaitForMemDataReadyInvLow =>
					if mem_dataready_inv = '0' then 
						 currentState <= ReadInputData; 
					end if; 
				when ReadInputData =>
					mem_data_read_internal(15 downto 0) <= 
						mem_data_read(15 downto 0);
					currentState <= SetMemAddrReadyLow; 
				when SetMemAddrReadyLow =>
					mem_addressready <=  '0'; 
					currentState <= WaitForMemDataReadyInvHigh; 
				--when WaitForMemDataReadyInvHigh =>
				--when SetWriteControlAndDataOutputs =>
				--when WaitForMemDataReadyInvLow =>
				--when WriteOutputData =>
				--when SetMemAddrReadyLow =>
				--when WaitForMemDataReadyInvHigh =>
			end case;
		end if;
	end process;

	outputData <= mem_data_read_internal; 
	with currentState select
		fsmStateCode <=
	       "000000" when Init,
	       "000001" when WaitForMemDataReadyInvHigh,
	       "000010" when SetReadControlAndDataInputs,
	       "000011" when WaitForMemDataReadyInvLow,
	       "000100" when ReadInputData,
	       "000101" when SetMemAddrReadyLow,
	        --"000110" when WaitForMemDataReadyInvHigh,
		--"000111--" when SetWriteControlAndDataOutputs,
		--"001000--" when WaitForMemDataReadyInvLow,
		--"001001--" when WriteOutputData,
		--"001010--" when SetMemAddrReadyLow,
		--"001011--" when WaitForMemDataReadyInvHigh,
	       "111111" when others;

	       --with currentState select
		       --mem_addr <= when Init
				   --'0' when others;
	       --with currentState select
		       --mem_data <= when Init
				   --'0' when others;
	       --with currentState select
		       --mem_rw <= when Init
				 --'0' when others;
	       --with currentState select
		       --mem_sixteenbit <= when Init
					 --'0' when others;
	       --with currentState select
		       --mem_thirtytwobit <= when Init
					   --'0' when others;
	       --with currentState select
		       --mem_addressready <= when Init
					   --'0' when others;
	       --with currentState select
		       --mem_reset <= when Init
				    --'0' when others;
end architecture mycpu_arch;
