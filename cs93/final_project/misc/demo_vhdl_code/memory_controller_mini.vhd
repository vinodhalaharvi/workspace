-- synthesis library cscie93
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library cscie93;

entity memory_controller is
    port (
	     clk50mhz : in std_logic;

	     mem_addr : in std_logic_vector(20 downto 0);
	     mem_data_write : in std_logic_vector(31 downto 0);
	     mem_rw : in std_logic;
	     mem_sixteenbit : in std_logic;
	     mem_thirtytwobit : in std_logic;
	     mem_addressready : in std_logic;
	     mem_reset : in std_logic;
	     clock_hold : in std_logic;
	     clock_step : in std_logic;
	     clock_divide_limit : in std_logic_vector(19 downto 0) := (others => '0');
	     mem_suspend : in std_logic;

	     mem_data_read : out std_logic_vector(31 downto 0);
	     mem_dataready_inv : out std_logic;
	     mem_ready : out std_logic;

	     sysclk1 : out std_logic;
	     sysclk2 : out std_logic;

		--diagnostics
	     fsmStateCode : out std_logic_vector(5 downto 0);
);
end;

architecture a of memory_controller is
    constant CHARIO_CONTROL_PORT : std_logic_vector(20 downto 0) := "00000" & X"FF00";
    constant SERIAL_CHARIO_DATA_PORT : std_logic_vector(20 downto 0) := "00000" & X"FF04";
    constant PS2_LCD_CHARIO_DATA_PORT : std_logic_vector(20 downto 0) := "00000" & X"FF08";
    signal mem_rw_internal : std_logic;
    signal mem_16bit_internal : std_logic := '0';
    signal mem_32bit_internal : std_logic := '0';
    signal mem_addr_internal : std_logic_vector(20 downto 0);
    signal mem_data_read_internal : std_logic_vector(31 downto 0);
    signal mem_data_write_internal : std_logic_vector(31 downto 0);
    signal byte_enable : std_logic_vector(1 downto 0);
    signal mem_q : std_logic_vector(15 downto 0);
    signal mem_clkenable : std_logic;
	-- raw clocks not gated by clock_run/clock_suspend
    signal clk1raw : std_logic;
    signal clk2raw : std_logic;
	-- cooked clocks are gated by clock_run/clock_suspend
    signal clk1 : std_logic;
    signal clk2 : std_logic;
    type States is (Init, WaitForAddrReady, LatchControlInputs, 

    ClockRamRead, LatchReadOutputs, 
    ClockRamRead32, LatchReadOutputs32, ReadDataReady, 
    WaitForWriteSignal, ClockRamWrite, ClockRamWrite32,
);


signal currentState : States := Init;

begin
    sysclk1 <= clk1;
    sysclk2 <= clk2;

    byte_enable(0) <= '0' when mem_32bit_internal='0' and mem_16bit_internal='0' 
		      and mem_addr_internal(0) = '1'
		      else '1';
    byte_enable(1) <= '0' when mem_32bit_internal='0' and mem_16bit_internal='0' 
		      and mem_addr_internal(0) = '0'
		      else '1';
    mem_data_write_internal <= 	
			       mem_data_write when mem_32bit_internal='1' 
			   else mem_data_write(7 downto 0) & X"00" & mem_data_write(7 downto 0) & X"00" 
			   when mem_32bit_internal='0' and mem_16bit_internal='0' 
			   and mem_addr_internal(0) = '1'
		       else mem_data_write(15 downto 0) & mem_data_write(15 downto 0);


    mem_data_read <= mem_data_read_internal when mem_32bit_internal = '1' 
		     else X"0000" & mem_data_read_internal(15 downto 0) when mem_16bit_internal='1' 
		     else X"000000" & mem_data_read_internal(7 downto 0) when mem_16bit_internal='0' 
			 and mem_addr_internal(0)='0'
		     else X"000000" & mem_data_read_internal(15 downto 8);


    with currentState select
	mem_clkenable <= 	'1' when ClockRamRead | ClockRamRead32 
			  | ClockRamWrite | ClockRamWrite32,
			  '0' when others;

    with currentState select
	mem_dataready_inv <=	'0' when ReadDataReady 
			     | WaitForWriteSignal | ClockRamWrite 
			     | ClockRamWrite32
			     '1' when others;

    with currentState select
	mem_ready <= 	'1' when WaitForAddrReady,
		      '0' when others;

    FSM :
    process(clk1, mem_reset) is
    begin
	if mem_reset = '1' then
	    currentState <= Init;
	elsif rising_edge(clk1) then
	    case currentState is
		when Init =>
		    if pll_locked='1' then
			currentState <= WaitForAddrReady;
		    end if;
		when WaitForAddrReady =>
		    if mem_addressready = '1' and mem_suspend='0' then
			currentState <= LatchControlInputs;
		    end if;
		when LatchControlInputs =>
		    mem_rw_internal <= mem_rw;
		    mem_16bit_internal <= mem_sixteenbit;
		    mem_32bit_internal <= mem_thirtytwobit;
		    mem_addr_internal <= mem_addr;
		    if mem_rw = '0' then
			currentState <=  ClockRamRead;
		    else
			currentState <= WaitForWriteSignal;
		    end if;
		when ClockRamRead =>
		    currentState <= LatchReadOutputs;
		when LatchReadOutputs =>
		    mem_data_read_internal(15 downto 0) <= mem_q;
		    if mem_32bit_internal = '0' then
			currentState <= ReadDataReady;
		    else
			currentState <= ClockRamRead32;
			mem_addr_internal <= std_logic_vector(unsigned(mem_addr_internal) + 2);
		    end if;
		-- finish a 32-bit read from FPGA RAM
		when ClockRamRead32 =>
		    currentState <= LatchReadOutputs32;
		when LatchReadOutputs32 =>
		    mem_data_read_internal(31 downto 16) <= mem_q;
		    currentState <= ReadDataReady;
		when ReadDataReady =>
		    if mem_addressready='0' then
			currentState <= WaitForAddrReady;
		    end if;
		when WaitForWriteSignal =>
		    if mem_addressready = '0' then
			currentState <= ClockRamWrite;
		    end if;
		when ClockRamWrite =>
		    if mem_32bit_internal='0' then
			currentState <= WaitForAddrReady;
		    else
			currentState <= ClockRamWrite32;
			mem_addr_internal <= std_logic_vector(unsigned(mem_addr_internal) + 2);
		    end if;
		when ClockRamWrite32 =>
		    currentState <= WaitForAddrReady;
		when others =>
		    if mem_addressready = '0' then
			currentState <= WaitForAddrReady;
		    end if;
	    end case;
	end if;
    end process;

    with currentState select
	fsmStateCode <= 
	 "000000" when Init,
	 "000001" when  WaitForAddrReady,
	 "000010" when  LatchControlInputs,
	 "000011" when  ClockRamRead,
	 "000100" when  LatchReadOutputs,
	 "000101" when  ReadDataReady,
	 "000110" when  WaitForWriteSignal,
	 "000111" when  ClockRamWrite,
	 "111111" when others;
end;

