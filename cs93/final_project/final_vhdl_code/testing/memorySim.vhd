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
	X"0000",
	X"0000",
	X"0004",
	X"0C00",
	X"0008",
	X"2008",
	X"0020",
	X"0800",
	X"0004",
	X"2009",
	X"0003",
	X"200B",
	X"4020",
	X"016A",
	X"5020",
	X"016A",
	X"4820",
	X"000A",
	X"4020",
	X"014A",
	X"5022",
	X"0109",
	X"5020",
	X"016A",
	X"4820",
	X"000A",
	X"4020",
	X"014A",
	X"0005",
	X"2009",
	X"0000",
	X"0000",
	X"48C0",
	X"0008",
	X"5004",
	X"0168",
	X"5004",
	X"0168",
	X"000A",
	X"2949",
	X"5004",
	X"0168",
	X"4807",
	X"016A",
	X"4942",
	X"0008",
	X"4807",
	X"016A",
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
