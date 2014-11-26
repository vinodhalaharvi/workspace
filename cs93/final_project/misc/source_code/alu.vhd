-- synthesis library cscie93
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity alu is
	port (
		GPR_rs, GPR_r2 : in std_logic_vector(31 downto 0),
                ALU_C : out std_logic
                ALU_Z : out std_logic, 
                ALU_result : out std_logic_vector(31 downto 0), 
	);
end;
architecture alu_arch of alu is
begin
        ALU_Inst : process (all)
                variable fn : alu_fn_code;
                variable right_operand : unsigned_byte;
                variable shift_result : unsigned_byte;
        begin
                if IR_decode_alu_reg or IR_decode_alu_immed or IR_decode_mem then
                        if IR_decode_alu_reg then
                                fn := IR_alu_reg_fn;
                                right_operand := GPR_r2;
                        elsif IR_decode_alu_immed then
                                fn := IR_alu_immed_fn;
                                right_operand := IR_immed;
                        else
                                fn := alu_fn_add;
                                right_operand := IR_offset;
                        end if;
                        case fn is
                                when alu_fn_add =>
                                        (ALU_C, ALU_result) <= ('0' & GPR_rs)
                                        + ('0' & right_operand);
                                when alu_fn_sub =>
                                        (ALU_C, ALU_result) <= ('0' & GPR_rs)
                                        - ('0' & right_operand);
                                when alu_fn_and =>
                                        (ALU_C, ALU_result) <= ('0' & GPR_rs)
                                        and ('0' & right_operand);
                                when alu_fn_or =>
                                        (ALU_C, ALU_result) <= ('0' & GPR_rs)
                                        or ('0' & right_operand);
                                when alu_fn_xor =>
                                        (ALU_C, ALU_result) <= ('0' & GPR_rs)
                                        xor ('0' & right_operand);
                                when others =>
                                        (ALU_C, ALU_result) <= 'X'
                                        & unsigned_byte'(others => 'X');
                        end case;
                else
                        case IR_shift_fn is
                                when shift_fn_shl =>
                                        (ALU_C, ALU_result) <= ('0' & GPR_rs)
                                        sll to_integer(IR_count);
                                when shift_fn_shr =>
                                        (ALU_result, ALU_C) <= (GPR_rs & '0')
                                        srl to_integer(IR_count);
                                when others =>
                                        (ALU_C, ALU_result) <= 'X'
                                        & unsigned_byte'(others => 'X');
                        end case;
                end if;
        end process ALU;
        ALU_Z <= ALU_result ?= unsigned_byte'(others => '0');
end architecture alu_arch;