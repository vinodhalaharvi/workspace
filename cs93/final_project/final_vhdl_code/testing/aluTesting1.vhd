--Vinod Halaharvi
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 

entity alu is
	port (
	-- inputs
	GPR_rs, GPR_r2 : in std_logic_vector(3 downto 0);
	alu_fn_code : in std_logic_vector(5 downto 0); 

	-- outputs
	ALU_C : out std_logic;
	ALU_Z : out std_logic;
	ALU_result : buffer std_logic_vector(3 downto 0);

	-- for seven segment display
	seg1  : out std_logic_vector(6 downto 0)
);
end;
architecture alu_arch of alu is
	subtype alu_fn_code_type is std_logic_vector(5 downto 0);
	constant alu_fn_add : alu_fn_code_type := "100000";
	constant alu_fn_sub : alu_fn_code_type := "100010";
	constant alu_fn_and : alu_fn_code_type := "100100";
	constant alu_fn_or :  alu_fn_code_type := "100101";
	constant alu_fn_xor : alu_fn_code_type := "100110";

	signal ALU_result_with_Carry : std_logic_vector(4 downto 0);

	attribute chip_pin : string;
	attribute chip_pin of GPR_rs : signal is "AB28, AC28, AC27, AD27";
	attribute chip_pin of GPR_r2 : signal is "AB27, AC26, AD26, AB26";
	attribute chip_pin of alu_fn_code : signal is "AC25, AB25, AC24, AB24, AB23, AA24"; 
	attribute chip_pin of seg1 : signal is "G18, F22, E17, L26, L25, J22, H22"; 
begin
	sevenSegTesting1_inst: entity sevenSegTesting port map (
			       bcd => ALU_result(3 downto 0), 
			       seg => seg1 
		       ); 
	ALU_Inst : process (GPR_rs, GPR_r2, alu_fn_code)
	begin
		case alu_fn_code is
			when alu_fn_add =>
				ALU_result_with_Carry <= std_logic_vector(unsigned('0' & GPR_rs)  + unsigned('0' & GPR_r2));
				ALU_result <= ALU_result_with_Carry(3 downto 0);
				ALU_C <= ALU_result_with_Carry(4); 
			when alu_fn_sub =>
				ALU_result_with_Carry <= std_logic_vector(unsigned('0' & GPR_rs)  - unsigned('0' & GPR_r2));
				ALU_result <= ALU_result_with_Carry(3 downto 0);
				ALU_C <= ALU_result_with_Carry(4); 
			when alu_fn_and =>
				ALU_result_with_Carry <= ('0' & GPR_rs)  and ('0' & GPR_r2);
				ALU_result <= ALU_result_with_Carry(3 downto 0);
				ALU_C <= ALU_result_with_Carry(4); 
			when alu_fn_or =>
				ALU_result_with_Carry <= ('0' & GPR_rs)  or ('0' & GPR_r2);
				ALU_result <= ALU_result_with_Carry(3 downto 0);
				ALU_C <= ALU_result_with_Carry(4); 
			when alu_fn_xor =>
				ALU_result_with_Carry <= ('0' & GPR_rs)  xor ('0' & GPR_r2);
				ALU_result <= ALU_result_with_Carry(3 downto 0);
				ALU_C <= ALU_result_with_Carry(4); 
			when others =>
				ALU_result <= X"0";
				ALU_C <= '0';
		end case;
		if ALU_result = X"0" then 
			ALU_Z <= '1';
		end if; 
	end process ALU_Inst;
end architecture alu_arch;


