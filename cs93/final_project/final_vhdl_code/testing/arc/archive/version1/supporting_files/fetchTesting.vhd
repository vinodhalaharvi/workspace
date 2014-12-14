--Vinod Halaharvi
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
library cscie93;
use work.all; 

entity  fetchStateTesting is
	port (
		     -- CLOCK
		     clk50mhz : in std_logic;
		     -- PS/2 PORT
		     ps2_clk : in std_logic;
		     ps2_data : in std_logic;
		     -- LCD		
		     lcd_en : out std_logic;
		     lcd_on : out std_logic;
		     lcd_rs : out std_logic;
		     lcd_rw : out std_logic;
		     lcd_db : inout std_logic_vector(7 downto 0);	
		     -- RS232		
		     rs232_rxd : in std_logic;
		     rs232_txd : out std_logic;
		     rs232_cts : out std_logic;
		     -- SSRAM interface
		     sram_dq : inout std_logic_vector (15 downto 0);
		     sram_addr : out std_logic_vector(19 downto 0);
		     sram_ce_N : out std_logic;
		     sram_oe_N : out std_logic;
		     sram_we_N : out std_logic;
		     sram_ub_N : out std_logic;
		     sram_lb_N : out std_logic;

		     fsmStateCode : buffer std_logic_vector(5 downto 0); 
		     IR : buffer std_logic_vector(31 downto 0) := X"00000000"; 
		     clock_step : in std_logic; 
		     reset : in std_logic; 

		     --testing display
		     seg0 : out std_logic_vector (6 downto 0); 
		     seg1 : out std_logic_vector (6 downto 0); 
		     seg2 : out std_logic_vector (6 downto 0); 
		     seg3 : out std_logic_vector (6 downto 0); 
		     seg4 : out std_logic_vector (6 downto 0); 
		     seg5 : out std_logic_vector (6 downto 0); 
		     seg6 : out std_logic_vector (6 downto 0); 
		     seg7 : out std_logic_vector (6 downto 0)
	     ); 
end entity fetchStateTesting;

architecture fetchStateTesting_arch of fetchStateTesting  is
	attribute chip_pin : string;
	attribute chip_pin of seg0 : signal is "G18, F22, E17, L26, L25, J22, H22";
	attribute chip_pin of seg1 : signal is "M24, Y22, W21, W22, W25, U23, U24";
	attribute chip_pin of seg2 : signal is "AA25, AA26, Y25, W26, Y26, W27, W28";
	attribute chip_pin of seg3 : signal is "V21, U21, AB20, AA21, AD24, AF23, Y19";
	attribute chip_pin of seg4 : signal is "AB19, AA19, AG21, AH21, AE19, AF19, AE18";
	attribute chip_pin of seg5 : signal is "AD18, AC18, AB18, AH19, AG19, AF18, AH18";
	attribute chip_pin of seg6 : signal is "AA17, AB16, AA16, AB17, AB15, AA15, AC17";
	attribute chip_pin of seg7 : signal is "AD17, AE17, AG17, AH17, AF17, AG18, AA14";
	attribute chip_pin of clock_step : signal is "M23"; 

	-- for memory
	signal mem_data_read :  std_logic_vector(31 downto 0);
	signal mem_dataready_inv :  std_logic;
	signal mem_ready :  std_logic;
	signal mem_addr :  std_logic_vector(20 downto 0);
	signal PC : std_logic_vector(20 downto 0) := '0' & X"00000";
	signal mem_data_write :  std_logic_vector(31 downto 0);
	signal mem_rw :  std_logic;
	signal mem_sixteenbit :  std_logic;
	signal mem_thirtytwobit :  std_logic;
	signal mem_addressready :  std_logic;
	signal mem_reset :  std_logic := '0' ;
	signal clock_hold :  std_logic := '1' ;
	--signal clock_step :  std_logic := '1';
	signal sysclk1 : std_logic;
	signal sysclk2 : std_logic;
	signal clock_divide_limit :  std_logic_vector(19 downto 0) := (others => '0');
	signal mem_suspend :  std_logic := '0' ;
	signal serial_character_ready :  std_logic := '0' ;
	signal ps2_character_ready :  std_logic := '0' ;
	signal mem_en : std_logic :='0' ;

	--fsm states
	type states is (pc_increment, fetch_state, decode_state, execute_state, mem_wait); 

	signal currentState : states := fetch_state; 
begin
	--this inside the entity declaration
	--this inside the architecture
	sevenSegTesting0_inst: entity sevenSegTesting 

	port map (
			 bcd => IR(3 downto 0), 
			 seg => seg0 
		 ); 
	sevenSegTesting1: entity sevenSegTesting 
	port map (
			 bcd => IR(7 downto 4), 
			 seg => seg1 
		 ); 
	sevenSegTesting2: entity sevenSegTesting 
	port map (
			 bcd => IR(11 downto 8), 
			 seg => seg2 
		 ); 
	sevenSegTesting3: entity sevenSegTesting 
	port map (
			 bcd => IR(15 downto 12), 
			 seg => seg3 
		 ); 
	sevenSegTesting4: entity sevenSegTesting 
	port map (
			 bcd => IR(19 downto 16), 
			 seg => seg4 
		 ); 
	sevenSegTesting5: entity sevenSegTesting 
	port map (
			 bcd => IR(23 downto 20), 
			 seg => seg5 
		 ); 
		 
	sevenSegTesting6: entity sevenSegTesting 
	port map (
			 bcd => fsmStateCode(3 downto 0), 
			 seg => seg6 
		 ); 
	sevenSegTesting7: entity sevenSegTesting 
	port map (
			 bcd => "00" & fsmStateCode(5 downto 4), 
			 seg => seg7 
		 ); 


	memory_inst : entity  memory is
	port  map (
		clk => clk,
		mem_en => mem_en,
		mem_dataready_inv => mem_dataready_inv,
		mem_ready => mem_ready,
		mem_data_write => mem_data_write,
		mem_data_read => mem_data_read,
		mem_rw => mem_rw,
		mem_sixteenbit => mem_sixteenbit,
		mem_thirtytwobit => mem_thirtytwobit,
		mem_addressready => mem_addressready
	     ); 

	--memory interface
	mem : cscie93.memory_controller 
	port map (
			 clk50mhz => clk50mhz,
			 mem_addr => mem_addr, 
			 mem_data_write => mem_data_write, 
			 mem_rw => mem_rw, 
			 mem_sixteenbit => mem_sixteenbit, 
			 mem_thirtytwobit => mem_thirtytwobit, 
			 mem_addressready => mem_addressready, 
			 mem_reset => mem_reset, 
			 ps2_clk => ps2_clk,
			 ps2_data => ps2_data,
			 clock_hold => clock_hold, 
			 clock_step => clock_step, 
			 --clock_divide_limit => clock_divide_limit, 
			 mem_suspend => mem_suspend,
			 lcd_en => lcd_en,
			 lcd_on => lcd_on,
			 lcd_rs => lcd_rs,
			 lcd_rw => lcd_rw,
			 lcd_db => lcd_db,
			 mem_data_read => mem_data_read, 
			 mem_dataready_inv => mem_dataready_inv, 
			 sysclk1 => sysclk1, 
			 sysclk2 => sysclk2, 
			 rs232_rxd => rs232_rxd,
			 rs232_txd => rs232_txd,
			 rs232_cts => rs232_cts,
			 sram_dq => sram_dq,
			 sram_addr => sram_addr,
			 sram_ce_N => sram_ce_N,
			 sram_oe_N => sram_oe_N,
			 sram_we_N => sram_we_N,
			 sram_ub_N => sram_ub_N,
			 sram_lb_N => sram_lb_N,
			 serial_character_ready => serial_character_ready, 
			 ps2_character_ready => ps2_character_ready
		 );

	IR(15 downto 0) <= mem_data_read(15 downto 0);

	FSM :
	--process(sysclk1, reset) is
	process(sysclk1, mem_data_read, mem_dataready_inv, mem_ready) is
	begin
		if reset = '1' then
			currentState <= fetch_state;
		elsif rising_edge(sysclk1) then  
			case currentState is
				when pc_increment =>
					if mem_dataready_inv = '0' then 
						mem_addressready <=  '0'; 
						currentState <= fetch_state;
						PC <= std_logic_vector(unsigned(PC) + 2); 
					end if;


				when fetch_state =>
					mem_en <= '1';
					if mem_dataready_inv = '1' then 
						mem_rw <= '0'; 
						mem_addr <= PC; 
						mem_sixteenbit <= '1';
						mem_thirtytwobit <= '0';
						mem_addressready <= '1';
						currentState <= pc_increment;
					end if;
					when others =>
						currentState <= fetch_state;
			end case;
		end if;
	end process;

	with currentState select
		fsmStateCode <=
	       "000000" when pc_increment,
	       "000001" when fetch_state,
	       "000010" when decode_state,
	       "000011" when execute_state,
	       "000100" when mem_wait,
	       "111111" when others;
end architecture fetchStateTesting_arch;


