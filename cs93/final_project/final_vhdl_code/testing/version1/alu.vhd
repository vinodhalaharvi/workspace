--Vinod Halaharvi
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all; 
use mycpu_defs.all; 

entity alu is
	port (
		GPR_rs : in std_logic_vector(31 downto 0);
		GPR_r2 : in std_logic_vector(31 downto 0);
		alu_fn_code : in std_logic_vector(5 downto 0); 

		ALU_C : out std_logic;
		ALU_Z : out std_logic;
		ALU_result : out std_logic_vector(31 downto 0)
	);
end entity alu;
architecture alu_arch of alu is
	--subtype alu_fn_code_type is std_logic_vector(5 downto 0);
	--constant alu_fn_add : alu_fn_code_type := "100000";
	--constant alu_fn_sub : alu_fn_code_type := "100010";
	--constant alu_fn_and : alu_fn_code_type := "100100";
	--constant alu_fn_or :  alu_fn_code_type := "100101";
	--constant alu_fn_xor : alu_fn_code_type := "100110";
	--attribute chip_pin : string;
	--attribute chip_pin of alu_fn_code : signal is "AC25, AB25, AC24, AB24, AB23, AA24"; 
	--constant GPR_rs_testing : std_logic_vector(31 downto 0) := X"00000009";
	--constant GPR_r2_testing : std_logic_vector(31 downto 0) := X"00000002";
	signal ALU_result_with_Carry : std_logic_vector(32 downto 0);
	signal ALU_result_internal : std_logic_vector(31 downto 0); 
begin
	--GPR_rs <= GPR_rs_testing; 
	--GPR_r2 <= GPR_r2_testing;
	ALU_result_internal <= ALU_result;
	ALU_Inst : process (GPR_rs, GPR_r2, alu_fn_code)
	begin
		case alu_fn_code is
			when alu_fn_add =>
				ALU_result_with_Carry <= std_logic_vector(unsigned('0' & GPR_rs)  
							 + unsigned('0' & GPR_r2));
				ALU_result <= ALU_result_with_Carry(31 downto 0);
				ALU_C <= ALU_result_with_Carry(32); 
			when alu_fn_sub =>
				ALU_result_with_Carry <= std_logic_vector(unsigned('0' & GPR_rs)  
							 - unsigned('0' & GPR_r2));
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
		if ALU_result_internal = X"00000000" then 
			ALU_Z <= '1';
		end if; 
	end process ALU_Inst;
end architecture alu_arch;
