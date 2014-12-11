library ieee;
use ieee.std_logic_1164.all;
library cscie93;
use work.all; 
use mycpu_defs.all;



-- This file should be used for the DE2-115 board ONLY
--                                  ^^^^^^^
entity de2_115_shell is
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

		--my debugging output
		seg0 : out std_logic_vector (6 downto 0); 
		seg1 : out std_logic_vector (6 downto 0); 
		seg2 : out std_logic_vector (6 downto 0); 
		seg3 : out std_logic_vector (6 downto 0); 
		seg4 : out std_logic_vector (6 downto 0); 
		seg5 : out std_logic_vector (6 downto 0); 
		seg6 : out std_logic_vector (6 downto 0); 
		seg7 : out std_logic_vector (6 downto 0);
		--ALU_result : buffer std_logic_vector(31 downto 0);
		displaySwitches : in std_logic_vector(4 downto 0); 
		displayOutput : buffer std_logic_vector(31 downto 0);
		clock_step : in std_logic;
		reset : in std_logic
	     );

end;

architecture MyDefault of de2_115_shell is
	attribute chip_pin : string;

	attribute chip_pin of clk50mhz : signal is "Y2";

	attribute chip_pin of ps2_clk : signal is "G6";
	attribute chip_pin of ps2_data : signal is "H5";

	attribute chip_pin of lcd_on : signal is "L5";
	attribute chip_pin of lcd_en : signal is "L4";
	attribute chip_pin of lcd_rw : signal is "M1";
	attribute chip_pin of lcd_rs : signal is "M2";
	attribute chip_pin of lcd_db : signal is "M5,M3,K2,K1,K7,L2,L1,L3";

	attribute chip_pin of rs232_rxd : signal is "G12";
	attribute chip_pin of rs232_txd : signal is "G9";
	attribute chip_pin of rs232_cts : signal is "G14";

	attribute chip_pin of sram_dq : signal is "AG3,AF3,AE4,AE3,AE1,AE2,AD2,AD1,AF7,AH6,AG6,AF6,AH4,AG4,AF4,AH3";
	attribute chip_pin of sram_addr : signal is "T8,AB8,AB9,AC11,AB11,AA4,AC3,AB4, AD3, AF2, T7, AF5, AC5, AB5, AE6, AB6, AC7, AE7, AD7, AB7";
	attribute chip_pin of sram_ce_N : signal is "AF8";
	attribute chip_pin of sram_oe_N : signal is "AD5";
	attribute chip_pin of sram_we_N : signal is "AE8";
	attribute chip_pin of sram_ub_N : signal is "AC4";
	attribute chip_pin of sram_lb_N : signal is "AD4";	
	attribute chip_pin of displaySwitches : signal is "AB28, AC28, AC27, AD27, AB27"; 

	--signal displayOutput : std_logic_vector(31 downto 0); 
	--signal displaySwitches : std_logic_vector(4 downto 0); 
	signal mem_data_read :  std_logic_vector(31 downto 0);
	signal mem_dataready_inv :  std_logic;
	signal mem_ready :  std_logic;

	signal mem_addr :  std_logic_vector(20 downto 0);
	signal mem_data_write :  std_logic_vector(31 downto 0);
	signal mem_rw :  std_logic;
	signal mem_sixteenbit :  std_logic;
	signal mem_thirtytwobit :  std_logic;
	signal mem_addressready :  std_logic;
	--signal mem_reset :  std_logic := '0' ;
	signal clock_hold :  std_logic := '1' ;
	--signal clock_step :  std_logic := '1';
	signal sysclk1 : std_logic;
	signal sysclk2 : std_logic;
	
	signal clock_divide_limit :  std_logic_vector(19 downto 0) := (others => '0');
	signal mem_suspend :  std_logic := '0' ;
	signal serial_character_ready :  std_logic := '0' ;
	signal ps2_character_ready :  std_logic := '0' ;

	-- seven segment
	attribute chip_pin of seg0 : signal is "G18, F22, E17, L26, L25, J22, H22";
	attribute chip_pin of seg1 : signal is "M24, Y22, W21, W22, W25, U23, U24";
	attribute chip_pin of seg2 : signal is "AA25, AA26, Y25, W26, Y26, W27, W28";
	attribute chip_pin of seg3 : signal is "V21, U21, AB20, AA21, AD24, AF23, Y19";
	attribute chip_pin of seg4 : signal is "AB19, AA19, AG21, AH21, AE19, AF19, AE18";
	attribute chip_pin of seg5 : signal is "AD18, AC18, AB18, AH19, AG19, AF18, AH18";
	attribute chip_pin of seg6 : signal is "AA17, AB16, AA16, AB17, AB15, AA15, AC17";
	attribute chip_pin of seg7 : signal is "AD17, AE17, AG17, AH17, AF17, AG18, AA14";
	attribute chip_pin of clock_step : signal is "M23";
	attribute chip_pin of reset : signal is "M21";

	--signal ALU_result_internal : std_logic_vector(31 downto 0);
	signal IR :  std_logic_vector(31 downto 0); 
	signal pc :  std_logic_vector(20 downto 0);
	signal not_reset : std_logic := '0';
	signal destination_register : std_logic_vector(31 downto 0);
	signal fsmStateCode :  std_logic_vector(3 downto 0);
	
begin
	--ALU_result <= ALU_result_internal; 
	mem : cscie93.memory_controller port map (
		 clk50mhz => clk50mhz,
		 mem_addr => mem_addr, 
		 mem_data_write => mem_data_write, 
		 mem_rw => mem_rw, 
		 mem_sixteenbit => mem_sixteenbit, 
		 mem_thirtytwobit => mem_thirtytwobit, 
		 mem_addressready => mem_addressready, 
		 mem_reset => not reset, 
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


	 
	mpcpu_inst : entity  mycpu port map (
			sysclk1  => sysclk1, 
			reset => reset,
			mem_reset => not_reset, 
			mem_data_read =>  mem_data_read, 
			mem_dataready_inv =>  mem_dataready_inv, 
			mem_ready =>  mem_ready, 
			mem_addr =>  mem_addr, 
			mem_data_write =>  mem_data_write, 
			mem_rw =>  mem_rw, 
			mem_sixteenbit =>  mem_sixteenbit, 
			mem_thirtytwobit =>  mem_thirtytwobit, 
			mem_addressready =>  mem_addressready, 

			-- for debugging only
			--ALU_result => ALU_result_internal, 
			displayOutput => displayOutput, 
			displaySwitches => displaySwitches, 
			--destination_register => destination_register, 
			IR =>  IR, 
			pc => pc,
			fsmStateCode =>  fsmStateCode
		); 
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
			 bcd => displayOutput(3 downto 0), 
			 seg => seg4 
		 ); 
	sevenSegTesting5: entity sevenSegTesting 
	port map (
			 bcd => displayOutput(7 downto 4), 
			 seg => seg5 
		 ); 
		 
	sevenSegTesting6: entity sevenSegTesting 
	port map (
			 bcd => pc(3 downto 0), 
			 seg => seg6 
		 ); 
	sevenSegTesting7: entity sevenSegTesting 
	port map (
			 bcd => fsmStateCode, 
			 seg => seg7 
		 ); 
end;
