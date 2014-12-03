--Vinod Halaharvi
library ieee; 
use ieee.std_logic_1164.all; 

entity fsmTesting  is 
	port  (
		start, heat, timer, cancel : in std_logic; 
		clk : in std_logic; 
		burner, beep : out std_logic
      ); 
end  entity fsmTesting; 

architecture fsmTesting_arch of fsmTesting is 
	type states is (waitstart, heaton , heatoff, done); 
	signal state : in states := waitstart ; 
	signal next_state : states; 
begin
	-- calculate what the next state should be 
	-- based on the current state and the current inputs
	calcnext : process(start, heat, timer, cancel) is
	begin
		next_state <= state; 

		case state is 
			when waitstart =>
				if start = '1'  then
					if heat = '1'
						next_state <= heaton; 
					else 
						next_state <= heatoff; 
					end if; 
			when heaton =>
				if canel = '1'  then 
					next_state <= waitstart;
				elsif timer  =  '1' then 
					next_state <= done; 
				elsif  heat = '0' then 
					next_state <= heatoff;
				end if; 
			when heatoff =>
				if canel = '1'  then 
					next_state <= waitstart;
				elsif timer  =  '1' then 
					next_state <= done; 
				elsif  heat = '1' then 
					next_state <= heaton;
				end if; 
			when done =>
				if cancel = '1' then 
					next_state <= waitstart; 
				end if; 
		end case; 
	end process calcnext;

	-- at each clk cycle transition to next state
	update : process(clk) is begin 
		if falling_edge(clk) then 
			state <= next_state;
		end if; 
	end process update; 

	--assign outputs 
	with state select 
		burner <= '1' when heaton '0' when others;  

	with state select 
		beep <= '1' when done '0'   when others;
end architecture fsmTesting_arch; 
