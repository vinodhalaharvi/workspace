library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.mycpu_defs.all; 

entity  aluSim is
	port (
		     GPR_left_operand : in std_logic_vector(31 downto 0); 
		     GPR_right_operand : in std_logic_vector(31 downto 0); 
		     IR : in std_logic_vector(31 downto 0); 
		     ALU_C : out std_logic;
		     ALU_Z : out std_logic;
		     ALU_result : out std_logic_vector(31 downto 0)
	     ); 
end entity aluSim;

architecture aluSim_arch of aluSim  is
	signal ALU_result_internal : std_logic_vector(31 downto 0); 
	signal ALU_Z_internal : std_logic := '0'; 
	signal ALU_C_internal : std_logic := '0'; 
	signal IR_internal :  std_logic_vector(31 downto 0); 
	--define instruction aliases
	alias IR31_26 is IR_internal(31 downto 26);
	alias IR25_21 is IR_internal(25 downto 21);
	alias IR20_16 is IR_internal(20 downto 16);
	alias IR15_11 is IR_internal(15 downto 11);
	alias IR10_6 is IR_internal(10 downto 6);
	alias IR5_0 is IR_internal(5 downto 0);
	alias IR_immed is IR_internal(15 downto 0);
	alias IR_count is IR_internal(10 downto 6);
	alias IR_offset is IR_internal(15 downto 0);
begin
	IR_internal <= IR;
	ALU_result <= ALU_result_internal;
	ALU_C <= ALU_C_internal;
	ALU_Z <= ALU_Z_internal;
	ALU_Inst : process(all) is 
	begin
		if (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_add) then
			ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
					       + unsigned(GPR_right_operand));
		elsif (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_sub) then
			ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
					       - unsigned(GPR_right_operand));
		elsif (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_sll) then
			ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
					       sll to_integer(unsigned(IR_count)));
		elsif (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_srl) then
			ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
					       srl to_integer(unsigned(IR_count)));
		elsif (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_sllv) then 
			ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
					       sll to_integer(unsigned(GPR_left_operand))); 
		elsif (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_srav) then 
			ALU_result_internal <= std_logic_vector(unsigned(GPR_right_operand) 
					       srl to_integer(unsigned(GPR_left_operand))); 
		elsif (IR31_26 = op_fn_special) and (IR5_0 = alu_fn_slt) then 
			if to_integer(unsigned(GPR_left_operand)) < to_integer(unsigned(GPR_right_operand)) 
			then
				ALU_result_internal <=  X"00000001";
			else 
				ALU_result_internal <=  X"00000000";
			end if; 
		elsif (IR31_26 = op_fn_beq) then 
			if to_integer(unsigned(GPR_left_operand)) = to_integer(unsigned(GPR_right_operand)) 
			then
				ALU_Z_internal <= '1' ;
			else 
				ALU_Z_internal <= '0'; 
			end if;
		elsif (IR31_26 = op_fn_bne) then 
			if to_integer(unsigned(GPR_left_operand)) /= to_integer(unsigned(GPR_right_operand)) 
			then
				ALU_Z_internal <= '1' ;
			else 
				ALU_Z_internal <= '0'; 
			end if;
		elsif (IR31_26 = op_fn_addi) then 
			ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
					       +  unsigned(X"0000" & std_logic_vector(IR_immed)));
		elsif (IR31_26 = op_fn_slti) then 
			if (unsigned(GPR_left_operand) < unsigned(IR_immed))  then 
				ALU_result_internal <=  X"00000001";
			else 
				ALU_result_internal <= X"00000000";
			end if;
		elsif (IR31_26 = op_fn_andi) then 
			ALU_result_internal <= GPR_left_operand and (X"0000" & std_logic_vector(IR_immed)); 
		elsif (IR31_26 = op_fn_ori) then 
			ALU_result_internal <= GPR_left_operand or (X"0000" & std_logic_vector(IR_immed)); 
		elsif (IR31_26 = op_fn_lui) then 
			ALU_result_internal <= std_logic_vector(unsigned(X"0000" & std_logic_vector(IR_immed)) sll 16); 
		elsif (IR31_26 = op_fn_lw) then 
			ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
					       + unsigned(X"0000" & std_logic_vector(IR_offset))); 
		elsif (IR31_26 = op_fn_sb) then 
			ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
					       + unsigned(X"0000" & std_logic_vector(IR_offset))); 
		elsif (IR31_26 = op_fn_sw) then 
			ALU_result_internal <= std_logic_vector(unsigned(GPR_left_operand) 
					       + unsigned(X"0000" & std_logic_vector(IR_offset))); 
		else
			ALU_result_internal <= (others => 'X'); 
		end if;

		if ALU_result_internal = X"00000000" then 
			ALU_Z_internal <= '1';
		end if; 
		--wait for 10 ns; 
	end process ALU_Inst;
end architecture aluSim_arch;
