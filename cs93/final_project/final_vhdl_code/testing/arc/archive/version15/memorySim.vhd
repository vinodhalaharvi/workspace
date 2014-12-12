entity  memSim is
	port (
		     mem_data_read : out std_logic_vector(31 downto 0);
		     mem_dataready_inv : out std_logic;
		     mem_ready : out std_logic;

		     sysclk1 : in std_logic; 
		     reset : in std_logic; 
		     mem_addr : in std_logic_vector(20 downto 0);
		     mem_reset : in std_logic;
		     mem_data_write : in std_logic_vector(31 downto 0);
		     mem_rw : in std_logic;
		     mem_sixteenbit : in std_logic;
		     mem_thirtytwobit : in std_logic;
		     mem_addressready : in std_logic;
	); 
end entity memSim;

architecture memSim_arch of memSim  is
	type memory_array is array(0 to 32768) of std_logic_vector(15 downto 0);
	signal memory : memory_array := (
	X"0002",
	X"0C00",
	X"000B",
	X"2004",
	X"000C",
	X"2005",
	X"602A",
	X"0080",
	X"2022",
	X"0004",
	X"682A",
	X"00A0",
	X"0010",
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
	X"002A",
	X"112A",
	X"0001",
	X"2108",
	X"0020",
	X"2918",
	X"0014",
	X"1418",
	X"0026",
	X"100C",
	X"1022",
	X"0002",
	X"002A",
	X"100D",
	X"1022",
	X"0002",
	X"5804",
	X"0104",
	X"1020",
	X"004B",
	others => (others => 'X')); 

begin

	
end architecture memSim_arch;
