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
	X"05DC",
	X"23BD",
	X"003E",
	X"0C00",
	X"FFC4",
	X"23BD",
	X"0018",
	X"ABB0",
	X"001C",
	X"ABB1",
	X"602A",
	X"0080",
	X"0010",
	X"100C",
	X"2022",
	X"0004",
	X"682A",
	X"00A0",
	X"0016",
	X"100D",
	X"2822",
	X"0005",
	X"4020",
	X"0000",
	X"0000",
	X"2002",
	X"4807",
	X"0105",
	X"0001",
	X"312A",
	X"0001",
	X"2009",
	X"0038",
	X"112A",
	X"0001",
	X"2108",
	X"0020",
	X"2918",
	X"001A",
	X"1418",
	X"002C",
	X"100C",
	X"1022",
	X"0002",
	X"0030",
	X"100D",
	X"1022",
	X"0002",
	X"0018",
	X"8FB0",
	X"001C",
	X"8FB1",
	X"003C",
	X"23BD",
	X"0008",
	X"03E0",
	X"5804",
	X"0104",
	X"1020",
	X"004B",
	X"0022",
	X"0800",
	X"0009",
	X"2004",
	X"000C",
	X"2005",
	X"0004",
	X"0C00",
	X"4020",
	X"0040",
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
