-- code from book

entity and2 is
  generic ( Tpd : time );
  port ( a, b : in bit;  y : out bit );
end entity and2;


architecture simple of and2 is
begin

  and2_function :
    y <= a and b after Tpd;

end architecture simple;

-- end code from book


entity ch_12_01 is

end entity ch_12_01;


----------------------------------------------------------------


library util;  use util.stimulus_generators.all;

architecture test of ch_12_01 is

  signal a1, b1, sig1, sig2, sig_out : bit;
  signal test_vector : bit_vector(1 to 3);

begin

  -- code from book

  gate1 : entity work.and2(simple)
    generic map ( Tpd => 2 ns )
    port map ( a => sig1,  b => sig2,  y => sig_out );

  gate2 : entity work.and2(simple)
    generic map ( Tpd => 3 ns )
    port map ( a => a1,  b => b1,  y => sig1 );

  -- end code from book

  stimulus : all_possible_values ( bv => test_vector,
				   delay_between_values => 10 ns );

  (sig2, a1, b1) <= test_vector;

end architecture test;
