-- synthesis library cscie93
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library cscie93;

entity alu is
	port (
		input : in std_logic;
		output : out std_logic_vector(7 downto 0)
	);
end;
architecture entity_name_arch of entity_name is
	type states is ( typea, typeb );
	signal current_state : states := init;
        signal signal1 : std_logic := '0';
        component comp
	generic (
		attr1	=> 'something1'
	);
	port (
                attr2 => 'something2'
	);
	end component;

begin
	entity1 : entity cscie93.entity1 port map (
					binding1 => binding1, 
					binding2 => binding2
                                );
        comp_inst : component comp
	generic (
		attr1	=> 'attr1'
	);
	port (
                attr2 => 'attr2'
	);
	end component comp;
        
        -- comment
	process_inst : process(clk2, reset) is
	begin
		if reset='1' then
			signal1 <= '0';
			input <= '0';
		elsif rising_edge(clk2) then
			signal1 <= ps2_rcv_ok_ungated;
			output <=  signal1;
		end if;
	end process process_inst;
end architecture entity_name_arch;
