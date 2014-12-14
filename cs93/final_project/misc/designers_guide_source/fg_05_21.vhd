entity full_adder is
  port ( a, b, c_in : bit;  s, c_out : out bit );
end entity full_adder;


architecture truth_table of full_adder is
begin

  with bit_vector'(a, b, c_in) select
    (c_out, s) <= bit_vector'("00") when "000",
                  bit_vector'("01") when "001",
                  bit_vector'("01") when "010",
                  bit_vector'("10") when "011",
                  bit_vector'("01") when "100",
                  bit_vector'("10") when "101",
                  bit_vector'("10") when "110",
                  bit_vector'("11") when "111";

end architecture truth_table;


-- not in book

entity fg_05_21 is
end entity fg_05_21;


library util;
use util.stimulus_generators.all;

architecture test of fg_05_21 is

  signal a, b, c_in, s, c_out : bit;
  signal test_vector : bit_vector(1 to 3);

begin

  dut : entity work.full_adder
    port map ( a => a, b => b, c_in => c_in, s => s, c_out => c_out );

  all_possible_values ( test_vector, 10 ns );

  (a, b, c_in) <= test_vector;

end architecture test;


-- end not in book
