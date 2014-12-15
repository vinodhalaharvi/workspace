library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity  memorySim is
	port (
		     mem_dataready_inv : out std_logic; 
		     mem_data_read : out std_logic_vector(31 downto 0); 
		     mem_data_write : in std_logic_vector(31 downto 0);
		     mem_ready : out std_logic;
		     mem_addressready : in std_logic; 
		     mem_addr : in std_logic_vector(20 downto 0);
		     mem_reset : in std_logic;
		     mem_rw : in std_logic;
		     mem_sixteenbit : in std_logic;
		     mem_thirtytwobit : in std_logic;
		     sysclk1 : in std_logic 
	     ); 
end entity memorySim;

architecture memorySim_arch of memorySim  is
	type memory_array is array(0 to 32768) of std_logic_vector(15 downto 0);
	signal memory : memory_array := (
	X"0007",
	X"2008",
	X"0008",
	X"2009",
	X"0018",
	X"0128",
	X"0000",
	X"202A",
	others => (others => 'X')); 
begin

	FSM :
	process(mem_addressready) is
	begin
		if mem_addressready = '1' then 
			if mem_rw = '0' then 
				if mem_thirtytwobit = '1' then  
					mem_data_read(15 downto 0) 
						<= memory(to_integer(unsigned(mem_addr))); 
					mem_data_read(31 downto 16) 
						<= memory(to_integer(unsigned(mem_addr) + 1)); 
				else 
					mem_data_read(15 downto 0) 
						<= memory(to_integer(unsigned(mem_addr))); 
					mem_data_read(31 downto 16)  <= (others => '0'); 
				end if;
			else
				if mem_thirtytwobit = '1'  then 
					memory(to_integer(unsigned(mem_addr))) 
						<= mem_data_write(15 downto 0); 
					memory(to_integer(unsigned(mem_addr) + 1)) 
						<= mem_data_write(31 downto 16); 
				 else 
					memory(to_integer(unsigned(mem_addr))) 
						<= mem_data_write(15 downto 0); 
				 end if;
			end if;
			mem_dataready_inv <= '0';
		else
			mem_dataready_inv <= '1';
		end if;
	end process;
end architecture memorySim_arch;
