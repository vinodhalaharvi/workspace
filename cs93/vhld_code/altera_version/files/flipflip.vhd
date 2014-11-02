library ieee; 
use ieee.std_logic_1164.all; 

entity d_flipflop is 
port (
	d : in std_logic; 
	q : out std_logic;
	qN : out std_logic;
	clk : in std_logic 
);
end entity flipflop; 

architecture arch for flipflop is 
begin
	--sensitivity list
	process (clk) is 
	begin
		--if clk is '1' and clk'event then
		-- if clk is '0' and clk'event then
		-- if falling_edge(clk) then 
		if rising_edge(clk) then
			q <= d;
			qN <= not d;
		end if; 
			
	
	end process; 

end architecture arch; 
