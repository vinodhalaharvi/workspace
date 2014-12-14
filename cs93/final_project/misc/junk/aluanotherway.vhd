library ieee;
use ieee.std_logic_1164.all; 
use ieee.numeric_std.all;
package body alu_defs is
	procedure add ( a, b : in word32;
			 sum : out word32;
			 overflow : out bit ) is
			 variable carry : bit := '0';
	begin
		for index in sum'reverse_range loop
			sum(index) := a(index) xor b(index) xor carry;
			carry := ( a(index) and b(index) )
			or ( carry and ( a(index) xor b(index) ) );
		end loop;
		overflow := carry;
	end procedure add;
end package body alu_defs;

