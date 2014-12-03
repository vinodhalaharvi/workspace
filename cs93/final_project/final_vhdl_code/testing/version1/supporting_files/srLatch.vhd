--Vinod Halaharvi
library ieee;
use ieee.std_logic_1164.all;

entity  srLatch is
	port (
		s, r  : in std_logic;
		q, qN  : buffer std_logic
	); 
end entity srLatch;

architecture srLatch_arch of srLatch  is
	attribute chip_pin : string;
	attribute chip_pin of s, r : signal is "AB28", "AC28";
	attribute chip_pin of q, qN : signal is "G19", "F19"; 
begin
	q <= n nor qN; 
	qN <= s nor q; 
end architecture srLatch_arch;
