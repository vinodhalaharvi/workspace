library ieee;
use ieee.std_logic_1164.all;

library cscie93;

-- This file should be used for the DE2-115 board ONLY
--                                  ^^^^^^^

entity YOUR_TOP_LEVEL_ENTITY_FOR_DE2_115 is
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
		sram_lb_N : out std_logic
	);
end;

architecture default of YOUR_TOP_LEVEL_ENTITY is
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
	
begin

	mem : cscie93.memory_controller port map (
					clk50mhz => clk50mhz,
					mem_addr => your-signal-here,
					mem_data_write => your-signal-here,
					mem_rw => your-signal-here,
					mem_sixteenbit => your-signal-here,
					mem_thirtytwobit => your-signal-here,
					mem_addressready => your-signal-here,
					mem_reset => your-signal-here,
					ps2_clk => ps2_clk,
					ps2_data => ps2_data,
					clock_hold => your-signal-here,
					clock_step => your-signal-here,
					clock_divide_limit => your-signal-here,
					mem_suspend => your-signal-here,
					lcd_en => lcd_en,
					lcd_on => lcd_on,
					lcd_rs => lcd_rs,
					lcd_rw => lcd_rw,
					lcd_db => lcd_db,
					mem_data_read => your-signal-here,
					mem_dataready_inv => your-signal-here,
					sysclk1 => your-signal-here,
					sysclk2 => your-signal-here,
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
					serial_character_ready => your-signal-here,
					ps2_character_ready => your-signal-here,
				);

-- Instantiate your CPU entity here!
cpu : entity work.your_cpu port map (
		. . .
		);

end;
