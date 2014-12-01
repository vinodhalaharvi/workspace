--Vinod Halaharvi
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity alu is
	port (
	-- inputs
	GPR_rs, GPR_r2 : buffer std_logic_vector(31 downto 0);
	alu_fn_code : in std_logic_vector(5 downto 0); 

	-- outputs
	ALU_C : out std_logic;
	ALU_Z : out std_logic;
	ALU_result : buffer std_logic_vector(31 downto 0);

	-- for seven segment display
	seg0  : out std_logic_vector(6 downto 0); 
	seg1  : out std_logic_vector(6 downto 0);
	seg2  : out std_logic_vector(6 downto 0);
	seg3  : out std_logic_vector(6 downto 0);
	seg4  : out std_logic_vector(6 downto 0);
	seg5  : out std_logic_vector(6 downto 0);
	seg6  : out std_logic_vector(6 downto 0);
	seg7  : out std_logic_vector(6 downto 0)
);
end;
architecture alu_arch of alu is
	subtype alu_fn_code_type is std_logic_vector(5 downto 0);
	constant alu_fn_add : alu_fn_code_type := "100000";
	constant alu_fn_sub : alu_fn_code_type := "100010";
	constant alu_fn_and : alu_fn_code_type := "100100";
	constant alu_fn_or :  alu_fn_code_type := "100101";
	constant alu_fn_xor : alu_fn_code_type := "100110";

	signal ALU_result_with_Carry : std_logic_vector(32 downto 0);
	attribute chip_pin : string;
	--attribute chip_pin of GPR_rs : signal is "AB28, AC28, AC27, AD27";
	--attribute chip_pin of GPR_r2 : signal is "AB27, AC26, AD26, AB26";
	attribute chip_pin of alu_fn_code : signal is "AC25, AB25, AC24, AB24, AB23, AA24"; 
	constant GPR_rs_testing : std_logic_vector(31 downto 0) := X"00000009";
	constant GPR_r2_testing : std_logic_vector(31 downto 0) := X"00000002";

	attribute chip_pin of seg0 : signal is "G18, F22, E17, L26, L25, J22, H22";
	attribute chip_pin of seg1 : signal is "M24, Y22, W21, W22, W25, U23, U24";
	attribute chip_pin of seg2 : signal is "AA25, AA26, Y25, W26, Y26, W27, W28";
	attribute chip_pin of seg3 : signal is "V21, U21, AB20, AA21, AD24, AF23, Y19";
	attribute chip_pin of seg4 : signal is "AB19, AA19, AG21, AH21, AE19, AF19, AE18";
	attribute chip_pin of seg5 : signal is "AD18, AC18, AB18, AH19, AG19, AF18, AH18";
	attribute chip_pin of seg6 : signal is "AA17, AB16, AA16, AB17, AB15, AA15, AC17";
	attribute chip_pin of seg7 : signal is "AD17, AE17, AG17, AH17, AF17, AG18, AA14";
--this inside the architecture
begin
	GPR_rs <= GPR_rs_testing; 
	GPR_r2 <= GPR_r2_testing;
	sevenSegTesting0_inst: entity sevenSegTesting port map (
								       bcd => ALU_result(3 downto 0), 
								       seg => seg0 
							       ); 
	sevenSegTesting1: entity sevenSegTesting port map (
								  bcd => ALU_result(7 downto 4), 
								  seg => seg1 
							  ); 
	sevenSegTesting2: entity sevenSegTesting port map (
								  bcd => ALU_result(11 downto 8), 
								  seg => seg2 
							  ); 
	sevenSegTesting3: entity sevenSegTesting port map (
								  bcd => ALU_result(15 downto 12), 
								  seg => seg3 
							  ); 
	sevenSegTesting4: entity sevenSegTesting port map (
								  bcd => ALU_result(19 downto 16), 
								  seg => seg4 
							  ); 
	sevenSegTesting5: entity sevenSegTesting port map (
								  bcd => ALU_result(23 downto 20), 
								  seg => seg5 
							  ); 
	sevenSegTesting6: entity sevenSegTesting port map (
								  bcd => ALU_result(27 downto 24), 
								  seg => seg6 
							  ); 
	sevenSegTesting7: entity sevenSegTesting port map (
								  bcd => ALU_result(31 downto 28), 
								  seg => seg7 
							  ); 

	ALU_Inst : process (GPR_rs, GPR_r2, alu_fn_code)
	begin
		case alu_fn_code is
			when alu_fn_add =>
				ALU_result_with_Carry <= std_logic_vector(unsigned('0' & GPR_rs)  + unsigned('0' & GPR_r2));
				ALU_result <= ALU_result_with_Carry(31 downto 0);
				ALU_C <= ALU_result_with_Carry(32); 
			when alu_fn_sub =>
				ALU_result_with_Carry <= std_logic_vector(unsigned('0' & GPR_rs)  - unsigned('0' & GPR_r2));
				ALU_result <= ALU_result_with_Carry(31 downto 0);
				ALU_C <= ALU_result_with_Carry(32); 
			when alu_fn_and =>
				ALU_result_with_Carry <= ('0' & GPR_rs)  and ('0' & GPR_r2);
				ALU_result <= ALU_result_with_Carry(31 downto 0);
				ALU_C <= ALU_result_with_Carry(32); 
			when alu_fn_or =>
				ALU_result_with_Carry <= ('0' & GPR_rs)  or ('0' & GPR_r2);
				ALU_result <= ALU_result_with_Carry(31 downto 0);
				ALU_C <= ALU_result_with_Carry(32); 
			when alu_fn_xor =>
				ALU_result_with_Carry <= ('0' & GPR_rs)  xor ('0' & GPR_r2);
				ALU_result <= ALU_result_with_Carry(31 downto 0);
				ALU_C <= ALU_result_with_Carry(32); 
			when others =>
				ALU_result <= X"00000000";
				ALU_C <= '0';
		end case;
		if ALU_result = X"00000000" then 
			ALU_Z <= '1';
		end if; 
	end process ALU_Inst;
end architecture alu_arch;


