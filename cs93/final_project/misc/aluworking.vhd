-- REFERENCE: Designers Guide to VHDL text book
-- page 695

-- Vinod Halaharvi
-- HUID: 80778287
-- vinod.halaharvi@gmail.com , (904) 200 1070
library ieee;
use ieee.std_logic_1164.all, ieee.numeric_std.all;
package alu_defs is
        subtype word32 is std_logic_vector(31 downto 0);
        subtype alu_fn_code is unsigned(5 downto 0);
        constant alu_fn_add : alu_fn_code := "100000";
        constant alu_fn_sub : alu_fn_code := "100010";
        constant alu_fn_and : alu_fn_code := "100100";
        constant alu_fn_or : alu_fn_code := "100101";
        constant alu_fn_xor : alu_fn_code := "100110";
        constant shift_fn_sll : shift_fn_code := "000000";
        constant shift_fn_srl : shift_fn_code := "000010";
        constant shift_fn_sra : shift_fn_code := "000011";
end package alu_defs;

package body alu_defs is
        procedure perform_alu_op ( fn : in alu_fn_code;
                        a, b : in word32;
                        C_in : in std_ulogic;
                        result : out word32;
                        Z_out, C_out : out std_ulogic ) is
        begin
                case fn is
                        when alu_fn_add =>
                                (C_out, result) := ('0' & a) + ('0' & b);
                        when alu_fn_sub =>
                                (C_out, result) := ('0' & a) - ('0' & b);
                        when alu_fn_and =>
                                (C_out, result) := ('0' & a) and ('0' & b);
                        when alu_fn_or =>
                                (C_out, result) := ('0' & a) or ('0' & b);
                        when alu_fn_xor =>
                                (C_out, result) := ('0' & a) xor ('0' & b);
                        when alu_fn_nor =>
                                (C_out, result) := ('0' & a) nor ('0' & b);
                        when shift_fn_sll =>
                                (C_out, result) := ('0' & a) sll to_integer(b);
                        when shift_fn_srl =>
                                (result, C_out) := (a & '0') srl to_integer(b);
                        when shift_fn_sra =>
                                (result, C_out) := (a & '0') sra to_integer(b);
                        when others =>
                                report "Invalid ALU operation code to the ALU"
                                severity failure;
                end case;
                Z_out := result ?= X"00";
        end procedure perform_alu_op;
end package alu_defs;