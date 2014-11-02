library ieee; 
use ieee.std_logic_1164.all; 

entity srlatch is 
	port (
		s, r : in std_logic; 
		q, qN: buffer std_logic
	);
	end; 
	
	
architecture arch of srlatch is  
begin
	q <= r nor qN; 
	qN <= s nor q; 
end; 