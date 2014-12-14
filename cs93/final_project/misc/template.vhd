--device name EP4CE115F29C7

library ieee;
use ieee.std_logic_1164.all;
entity mux4to1 is
	port (
		     inputs : in std_logic_vector(3 downto 0);
		     sel : in std_logic_vector (1 downto 0);
		     output : out std_logic
	     );
end;
architecture explicit_comb of mux4to1 is
begin
	-- explicit combinational logic
	output <= ( inputs(0) and not sel(1) and not sel(0)) or
		  ( inputs(1) and not sel(1) and sel(0)) or
		  ( inputs(2) and sel(1) and not sel(0)) or
		  ( inputs(3) and sel(1) and sel(0));
end;
architecture explicit_conditional of mux4to1 is
begin
	-- conditional assignment
	-- conditions are prioritized 
	-- conditions can be arbitrarily complex expressions
	--  of any number of varialbes
	output <= inputs(0) when sel = "00" else
		  inputs(1) when sel = "01" else
		  inputs(2) when sel="10" else
		  inputs(3) when sel="11";
end;
architecture selected of mux4to1 is
begin
	-- selected signal assignment
	-- specifies output for mutually exclusive values
	-- of a single input value
	with sel select
		output <= inputs(0) when "00",
			  inputs(1) when "01",
			  inputs(2) when "10",
			  inputs(3) when "11",
			  inputs(3) when others;
end;

library ieee;
use ieee.std_logic_1164.all;
entity d_flipflop is
	port (
		     d : in std_logic;
		     clk : in std_logic;
		     q : out std_logic;
		     qN : out std_logic
	     );
end;
architecture sequential of d_flipflop is
begin
	-- sequential (edge-triggered) logic can only
	-- be represented in a process statement
	process(clk) is
	begin
		if clk = '1' and clk'event then
			q <= d;
			qN <= not d;
		end if;
	end process;
end;

library ieee;
use ieee.std_logic_1164.all;
entity mux4to1clocked is
	port (
		     inputs : in std_logic_vector(3 downto 0);
		     sel : in std_logic_vector (1 downto 0);
		     clk : in std_logic;
		     output : out std_logic
	     );
end;
architecture sequential of mux4to1clocked is
	signal next_output : std_logic;
begin
	-- combinationally compute the output that would apply
	-- if we get clocked
	with sel select
		next_output <= inputs(0) when "00",
			       inputs(1) when "01",
			       inputs(2) when "10",
			       inputs(3) when "11",
			       inputs(3) when others;
	-- synchronous logic to assign the new output on a 
	-- rising clock edge
	process(clk) is
	begin
		-- equivalent to "clk='1' and clk'event", 
		--  i.f.f. you have the use "ieee.std_logic_1164.all" clause above
		if rising_edge(clk) then
			output <= next_output;
		end if;
	end process;
end;
architecture sequential2 of mux4to1clocked is
	signal next_output : std_logic;
begin
	-- process statements can also be used to represent purely 
	-- combinational logic; but *be careful* not to infer
	-- storage where none is intended (i.e. all signals should be 
	-- assigned in all possible paths through the process
	combinational : process(inputs, sel) is
	begin
		case sel is
			when "00" => 
				-- note: multiple statements (conditional, etc.) and assignments allowed in each case
				next_output <= inputs(0);
			when "01" => 
				next_output <= inputs(1);
			when "10" => 
				next_output <= inputs(2);
			when "11" => 
				next_output <= inputs(3);
			when others => 
				next_output <= inputs(3);
		end case;
	end process;
	-- synchronous logic to assign the new output on a 
	-- rising clock edge
	process(clk) is
	begin
		-- equivalent to "clk='1' and clk'event", 
		--  i.f.f. you have the use "ieee.std_logic_1164.all" clause above
		if rising_edge(clk) then
			output <= next_output;
		end if;
	end process;
end;

library ieee;
use ieee.std_logic_1164.all;
entity gray2count is
	port(
		    clk : in std_logic;
		    reset : in std_logic;
		    count : out std_logic_vector(1 downto 0)
	    );
end;
architecture arch of gray2count is
	signal next_count : std_logic_vector(1 downto 0);
	signal count_internal : std_logic_vector(1 downto 0) := "00"; -- init to 0
begin
	count <= count_internal;
	-- next value logic
	with count_internal select
		next_count <= "01" when "00",
			      "11" when "01",
			      "10" when "11",
			      "00" when "10",
			      "00" when others;
	-- synchronous assignment
	process(clk, reset) is
	begin
		if reset = '1' then
			count_internal <= "00";
		elsif rising_edge(clk) then
			count_internal <= next_count;
		end if;
	end process;
end;

library ieee;
use ieee.std_logic_1164.all;
entity shiftreg_cell is
	port (
		     l : in std_logic;
		     r : in std_logic;
		     shiftleft : in std_logic;
		     set : in std_logic := '0';
		     clr : in std_logic := '0';
		     clk : in std_logic;
		     q : out std_logic
	     );
end;
architecture arch of shiftreg_cell is
begin
	process(clk, set, clr) is
	begin
		if set = '1' then
			q <= '1';
		elsif clr = '1' then
			q <= '0';
		elsif rising_edge(clk) then
			if shiftleft = '1' then
				q <= r;
			else
				q <= l;
			end if;
		end if;
	end process;
end;

library ieee;
use ieee.std_logic_1164.all;
entity shiftreg4 is
	port(
		    clk : in std_logic;
		    shiftleft : in std_logic;
		    reset : in std_logic; -- resets to 0001
		    q : out std_logic_vector(3 downto 0)
	    );
end;
architecture simple of shiftreg4 is
	signal q_internal : std_logic_vector(3 downto 0);
begin
	q <= q_internal;
	process(clk, reset) is
	begin 
		if reset='1' then
			q_internal <= "0001";
		elsif rising_edge(clk) then
			if shiftleft='1' then
				q_internal <= q_internal(2 downto 0) & '0';
			else
				q_internal <= '0' & q_internal(3 downto 1);
			end if;
		end if;
	end process;
end;
architecture structural of shiftreg4 is
	signal q_internal : std_logic_vector(3 downto 0);
begin
	q <= q_internal;
	BIT0 : entity work.shiftreg_cell port map(l => q_internal(1), r => '0', shiftleft => shiftleft, set => reset, clr =>'0', clk => clk, q => q_internal(0));
	BIT1 : entity work.shiftreg_cell port map(l => q_internal(2), r => q_internal(0), shiftleft => shiftleft, set => '0', clr =>reset, clk => clk, q=>q_internal(1));
	BIT2 : entity work.shiftreg_cell port map(q_internal(3), q_internal(1), shiftleft, '0', reset, clk, q_internal(2));
	BIT3 : entity work.shiftreg_cell port map(l => '0', r => q_internal(2), shiftleft => shiftleft, set => '0', clr =>reset, clk => clk, q=>q_internal(3));
end;
architecture generated of shiftreg4 is
	signal q_internal : std_logic_vector(5 downto 0);
	signal sets : std_logic_vector(4 downto 1);
	signal clrs : std_logic_vector(4 downto 1);
begin
	q <= q_internal (4 downto 1);
	q_internal(0) <= '0';
	q_internal(5) <= '0';
	-- on reset, set bit0, clr other bits
	sets <= "000" & reset;
	clrs <= reset & reset & reset & '0';
	GenerateBits: 
	for i in 1 to 4 generate
		BITn : entity work.shiftreg_cell port map(l => q_internal(i+1), r => q_internal(i-1), shiftleft => shiftleft, set => sets(i), clr =>clrs(i), clk => clk, q => q_internal(i));
	end generate;
end;

library ieee;
use ieee.std_logic_1164.all;
entity srlatch is
	port(
	s, r : in std_logic;
	q, qN : out std_logic
);
end;
architecture crosscoupled of srlatch is
	signal qint, qNint : std_logic;
begin
	q <= qint;
	qN <= qnint;
	qint <= r nor qNint;
	qNint <= s nor qint;
end;

library ieee;
use ieee.std_logic_1164.all;
entity oven_fsm is
	port (
	start, heat, timer, cancel : in std_logic;
	clk : in std_logic;
	burner, beep : out std_logic
);
end;
architecture a of oven_fsm is
	type states is (waitstart, heaton, heatoff, done);
	signal state : states := waitstart;
	signal nextstate : states;
begin
	calcnext : process(start, heat, timer, cancel, state) is
	begin
		-- Default assignment is to leave it unchanged
		-- This is a combinational process so it should assign to nextstate in all cases
		nextstate <= state;
		case state is
			when waitstart =>
				if start='1' then
					if heat = '1' then
						nextstate <= heaton;
					else 
						nextstate <= heatoff;
					end if;
				end if;
			when heaton =>
				if cancel = '1' then
					nextstate <= waitstart;
				elsif timer='1' then
					nextstate <= done;
				elsif heat='0' then
					nextstate <= heatoff;
				end if;
			when heatoff =>
				if cancel = '1' then
					nextstate <= waitstart;
				elsif timer='1' then
					nextstate <= done;
				elsif heat='1' then
					nextstate <= heaton;
				end if;
			when done =>
				if cancel = '1' then
					nextstate <= waitstart;
				end if;
		end case;
	end process;
	update : process (clk) is
	begin
		if rising_edge(clk) then
			state <= nextstate;
		end if;
	end process;
	-- Moore FSM, outputs are pure functions of current state
	with state select
		burner <= 	'1' when heaton,
			   '0' when others;
	with state select
		beep <= 	'1' when done,
			 '0' when others;
end;

library ieee;
use ieee.std_logic_1164.all;
entity FSMwithVar is
	port ( 
		     clk : in std_logic;
		     reset : in std_logic;
		     done : out std_logic
	     );
end;
architecture fsm of FSMwithVar is
	type State is (S1, S2, S3, S4);
	signal currentState : State := S1;
	signal nextState : State;
begin
	fsm:
	process(reset, clk) is
		variable counter : integer := 0;
	begin
		if reset='1' then
			currentState <= S1;
		elsif rising_edge(clk) then
			currentState <= currentState;
			-- If we're in S2, sit there for 3 extra clock cycles
			-- Rather than define extra state, we can use a VHDL variable as a counter
			if currentState = S2 then
				if counter = 3 then
					counter := 0;
					currentState <=  nextState;
				else
					counter := counter + 1;   
				end if;
			else
				currentState <= nextState;
			end if;
		end if;
	end process;
	process(currentState) is
	begin
		case currentState is
			when S1 => 
				nextState <= S2;
			when S2 =>
				nextState <= S3;
			when S3 | S4 => 
				nextState <= S4;
			when others =>
				nextState <= S1;
		end case;
	end process;
	with currentState select	
		done <=	'1' when S4,
			'0' when others;
end;

library ieee;
use ieee.std_logic_1164.all;
entity AdderWithVar is
	port (
	a, b : in std_logic_vector(7 downto 0);
	Cin : in std_logic;
	s : out std_logic_vector(7 downto 0);
	Cout : out std_logic
);
end;
architecture seq of AdderWithVar is
begin
	process(a,b,Cin) is
		variable carries : std_logic_vector(8 downto 0);
		variable sum : std_logic_vector(7 downto 0);
	begin
		carries(0) := Cin;
		for i in 0 to 7 loop
			sum(i) := a(i) xor b(i) xor carries(i);
			carries(i+1) := (a(i) and b(i)) or (b(i) and carries(i)) or (a(i) and carries(i));
		end loop;
		s <= sum;
		Cout <= carries(8);
	end process;  
end;

library ieee;
use ieee.std_logic_1164.all;
entity AdderN is
	generic (NUMBITS : integer := 8); -- default is 8 bits; defaults are optional
	port (
	a, b : in std_logic_vector(NUMBITS-1 downto 0);
	Cin : in std_logic := '0';
	sum : out std_logic_vector(NUMBITS-1 downto 0);
	Cout : out std_logic
);
end;
architecture structural of AdderN is
	signal carries : std_logic_vector(NUMBITS downto 0);
begin
	carries(0) <= Cin;
	Cout <= carries(NUMBITS);
	CELLS: 
	for i in 0 to NUMBITS-1 generate
		CELLn : entity work.FullAdder 
		port map (a => a(i), b=>b(i), Cin => carries(i), s=>sum(i), Cout=>carries(i+1));
	end generate;
end;

library ieee;
use ieee.std_logic_1164.all;
entity Adder8 is
	port (
	a, b : in std_logic_vector(7 downto 0);
	Cin : in std_logic;
	sum : out std_logic_vector(7 downto 0);
	Cout : out std_logic
);
end;
architecture structural of Adder8 is
	signal carries : std_logic_vector(8 downto 0);
begin
	carries(0) <= Cin;
	Cout <= carries(8);
	CELLS: 
	for i in 0 to 7 generate
		CELLn : entity work.FullAdder 
		port map (a => a(i), b=>b(i), Cin => carries(i), s=>sum(i), Cout=>carries(i+1));
	end generate;
end;

library ieee;
use ieee.std_logic_1164.all;
entity FullAdder is
	port (
	a, b, Cin : in std_logic;
	s, Cout : out std_logic
);
end;
architecture comb of FullAdder is
begin
	s <= a xor b xor Cin;
	Cout <= (a and b) or (b and Cin) or (a and Cin);
end;

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

library ieee;
use ieee.std_logic_1164.all;
entity testbench is
	end ;
architecture test1 of testbench is
	signal clk : std_logic := '0';
begin
  -- This process generates 20 cycles of a clock with a 20ms period and 50% duty cycle, then stops.
	process is
	begin
		for i in 1 to 20 loop
			wait for 10 ms;
			clk <= '1';
			wait for 10 ms;
			clk <= '0';
		end loop;
		wait;
	end process;
	fsm: entity work.FSMWithVar port map (clk => clk, reset => '0');
end;

--attribute chip_pin : string;
--attribute chip_pin of clk50mhz : signal is "Y2";
--attribute chip_pin of ps2_clk : signal is "G6";

-- slide switches
-- switches 0 - 17
attribute chip_pin : string;
attribute chip_pin of ${1:variable} : signal is 
"AB28",
"AC28",
"AC27",
"AD27",
"AB27",
"AC26",
"AD26",
"AB26",
"AC25",
"AB25",
"AC24",
"AB24",
"AB23",
"AA24",
"AA23",
"AA22",
"Y24",
"Y23"; 


-- push buttons
-- push buttons 0 - 3
attribute chip_pin : string;
attribute chip_pin of ${1:variable} : signal is 
"M23",
"M21",
"N21",
"R24";


-- seven segment
attribute chip_pin : string;
attribute chip_pin of ${1:variable} : signal is 
HEX0 (0 - 6)
"G18",
"F22",
"E17",
"L26",
"L25",
"J22",
"H22",

HEX1 (0 - 6)
"M24",
"Y22",
"W21",
"W22",
"W25",
"U23",
"U24",

HEX2 (0 - 6)
"AA25",
"AA26",
"Y25",
"W26",
"Y26",
"W27",
"W28",

HEX3 (0 - 6)
"V21",
"U21",
"AB20",
"AA21",
"AD24",
"AF23",
"Y19",

HEX4 (0 - 6)
"AB19",
"AA19",
"AG21",
"AH21",
"AE19",
"AF19",
"AE18",

HEX5 (0 - 6)
"AD18",
"AC18",
"AB18",
"AH19",
"AG19",
"AF18",
"AH18",

HEX6 (0 - 6)
"AA17",
"AB16",
"AA16",
"AB17",
"AB15",
"AA15",
"AC17",
"AD17",
"AE17",







-Signal Name FPGA Pin No. Description I/O Standard
SW[0] PIN_AB28 Slide Switch[0] Depending on JP7
SW[1] PIN_AC28 Slide Switch[1] Depending on JP7
SW[2] PIN_AC27 Slide Switch[2] Depending on JP7
SW[3] PIN_AD27 Slide Switch[3] Depending on JP7
SW[4] PIN_AB27 Slide Switch[4] Depending on JP7
SW[5] PIN_AC26 Slide Switch[5] Depending on JP7
SW[6] PIN_AD26 Slide Switch[6] Depending on JP7
SW[7] PIN_AB26 Slide Switch[7] Depending on JP7
SW[8] PIN_AC25 Slide Switch[8] Depending on JP7
SW[9] PIN_AB25 Slide Switch[9] Depending on JP7
SW[10] PIN_AC24 Slide Switch[10] Depending on JP7
SW[11] PIN_AB24 Slide Switch[11] Depending on JP7
SW[12] PIN_AB23 Slide Switch[12] Depending on JP7
SW[13] PIN_AA24 Slide Switch[13] Depending on JP7
SW[14] PIN_AA23 Slide Switch[14] Depending on JP7
SW[15] PIN_AA22 Slide Switch[15] Depending on JP7
SW[16] PIN_Y24 Slide Switch[16] Depending on JP7
SW[17] PIN_Y23 Slide Switch[17] Depending on JP7

-- push buttons
KEY[0] PIN_M23 Push-button[0] Depending on JP7
KEY[1] PIN_M21 Push-button[1] Depending on JP7
KEY[2] PIN_N21 Push-button[2] Depending on JP7
KEY[3] PIN_R24 Push-button[3] Depending on JP7

-- 7 segment display
--Signal Name FPGA Pin No. Description I/O Standard
HEX0[0] PIN_G18      Seven Segment Digit 0[0] 2.5V
HEX0[1] PIN_F22      Seven Segment Digit 0[1] 2.5V
HEX0[2] PIN_E17      Seven Segment Digit 0[2] 2.5V
HEX0[3] PIN_L26      Seven Segment Digit 0[3] Depending on JP7
HEX0[4] PIN_L25      Seven Segment Digit 0[4] Depending on JP7
HEX0[5] PIN_J22      Seven Segment Digit 0[5] Depending on JP7
HEX0[6] PIN_H22      Seven Segment Digit 0[6] Depending on JP7

HEX1[0] PIN_M24      Seven Segment Digit 1[0] Depending on JP7
HEX1[1] PIN_Y22      Seven Segment Digit 1[1] Depending on JP7
HEX1[2] PIN_W21      Seven Segment Digit 1[2] Depending on JP7
HEX1[3] PIN_W22      Seven Segment Digit 1[3] Depending on JP7
HEX1[4] PIN_W25      Seven Segment Digit 1[4] Depending on JP7
HEX1[5] PIN_U23      Seven Segment Digit 1[5] Depending on JP7
HEX1[6] PIN_U24      Seven Segment Digit 1[6] Depending on JP7

HEX2[0] PIN_AA25      Seven Segment Digit 2[0] Depending on JP7
HEX2[1] PIN_AA26      Seven Segment Digit 2[1] Depending on JP7
HEX2[2] PIN_Y25      Seven Segment Digit 2[2] Depending on JP7
HEX2[3] PIN_W26      Seven Segment Digit 2[3] Depending on JP7
HEX2[4] PIN_Y26      Seven Segment Digit 2[4] Depending on JP7
HEX2[5] PIN_W27      Seven Segment Digit 2[5] Depending on JP7
HEX2[6] PIN_W28      Seven Segment Digit 2[6] Depending on JP7

HEX3[0] PIN_V21      Seven Segment Digit 3[0] Depending on JP7
HEX3[1] PIN_U21      Seven Segment Digit 3[1] Depending on JP7
HEX3[2] PIN_AB20      Seven Segment Digit 3[2] Depending on JP6
HEX3[3] PIN_AA21      Seven Segment Digit 3[3] Depending on JP6
HEX3[4] PIN_AD24      Seven Segment Digit 3[4] Depending on JP6
HEX3[5] PIN_AF23      Seven Segment Digit 3[5] Depending on JP6
HEX3[6] PIN_Y19      Seven Segment Digit 3[6] Depending on JP6

HEX4[0] PIN_AB19      Seven Segment Digit 4[0] Depending on JP6
HEX4[1] PIN_AA19      Seven Segment Digit 4[1] Depending on JP6
HEX4[2] PIN_AG21      Seven Segment Digit 4[2] Depending on JP6
HEX4[3] PIN_AH21      Seven Segment Digit 4[3] Depending on JP6
HEX4[4] PIN_AE19      Seven Segment Digit 4[4] Depending on JP6
HEX4[5] PIN_AF19      Seven Segment Digit 4[5] Depending on JP6
HEX4[6] PIN_AE18      Seven Segment Digit 4[6] Depending on JP6

HEX5[0] PIN_AD18      Seven Segment Digit 5[0] Depending on JP6
HEX5[1] PIN_AC18      Seven Segment Digit 5[1] Depending on JP6
HEX5[2] PIN_AB18      Seven Segment Digit 5[2] Depending on JP6
HEX5[3] PIN_AH19      Seven Segment Digit 5[3] Depending on JP6
HEX5[4] PIN_AG19      Seven Segment Digit 5[4] Depending on JP6
HEX5[5] PIN_AF18      Seven Segment Digit 5[5] Depending on JP6
HEX5[6] PIN_AH18      Seven Segment Digit 5[6] Depending on JP6

HEX6[0] PIN_AA17      Seven Segment Digit 6[0] Depending on JP6
HEX6[1] PIN_AB16      Seven Segment Digit 6[1] Depending on JP6
HEX6[2] PIN_AA16      Seven Segment Digit 6[2] Depending on JP6
HEX6[3] PIN_AB17      Seven Segment Digit 6[3] Depending on JP6
HEX6[4] PIN_AB15      Seven Segment Digit 6[4] Depending on JP6
HEX6[5] PIN_AA15      Seven Segment Digit 6[5] Depending on JP6
HEX6[6] PIN_AC17      Seven Segment Digit 6[6] Depending on JP6
HEX7[0] PIN_AD17      Seven Segment Digit 7[0] Depending on JP6
HEX7[1] PIN_AE17      Seven Segment Digit 7[1] Depending on JP6

--LEDR (0 - 14)
"G19",
"F19",
"E19",
"F21",
"F18",
"E18",
"J19",
"H19",
"J17",
"G17",
"J15",
"H16",
"J16",
"H17",
"F15",

Signal Name FPGA Pin No. Description I/O Standard
LEDR[0] PIN_G19 LED Red[0] 2.5V
LEDR[1] PIN_F19 LED Red[1] 2.5V
LEDR[2] PIN_E19 LED Red[2] 2.5V
LEDR[3] PIN_F21 LED Red[3] 2.5V
LEDR[4] PIN_F18 LED Red[4] 2.5V
LEDR[5] PIN_E18 LED Red[5] 2.5V
LEDR[6] PIN_J19 LED Red[6] 2.5V
LEDR[7] PIN_H19 LED Red[7] 2.5V
LEDR[8] PIN_J17 LED Red[8] 2.5V
LEDR[9] PIN_G17 LED Red[9] 2.5V
LEDR[10] PIN_J15 LED Red[10] 2.5V
LEDR[11] PIN_H16 LED Red[11] 2.5V
LEDR[12] PIN_J16 LED Red[12] 2.5V
LEDR[13] PIN_H17 LED Red[13] 2.5V
LEDR[14] PIN_F15 LED Red[14] 2.5V
