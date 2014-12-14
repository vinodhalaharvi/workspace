package arithmetic_ops is

  -- code from book

  procedure increment ( bv : inout bit_vector;  by : in integer := 1 );

  procedure increment ( int : inout integer;  by : in integer := 1 );

  -- end code from book

end package arithmetic_ops;



package body arithmetic_ops is

  procedure increment ( bv : inout bit_vector;  by : in integer := 1 ) is
  begin
  end procedure increment;

  procedure increment ( int : inout integer;  by : in integer := 1 ) is
  begin
  end procedure increment;

end package body arithmetic_ops;



----------------------------------------------------------------


entity ch_09_04 is

end entity ch_09_04;


----------------------------------------------------------------


library util;  use util.stimulus_generators.all;

architecture test of ch_09_04 is

  -- code from book

  -- MTI bug mt017
  -- alias bv_increment is work.arithmetic_ops.increment [ bit_vector, integer ];

  alias int_increment is work.arithmetic_ops.increment [ integer, integer ];

  -- workaround to avoid MTI bug mt018
  -- alias "*" is "and" [ bit, bit return bit ];

  alias "*" is std.standard."and" [ bit, bit return bit ];

  -- alias "+" is "or" [ bit, bit return bit ];

  alias "+" is std.standard."or" [ bit, bit return bit ];

  -- alias "-" is "not" [ bit return bit ];

  alias "-" is std.standard."not" [ bit return bit ];

  -- end workaround

  alias high is std.standard.'1' [ return bit ];

  -- end code from book

  signal a, b, c, s : bit := '0';
  signal test_vector : bit_vector(1 to 3);
  signal test_high : bit := high;

begin

  -- code from book

  -- workaround to avoid MTI bug mt018
  -- s <= a * b + (-a) * c;

  s <= (a and b) or ((not a) and c);

  -- end workaround

  -- end code from book

  stimulus : all_possible_values ( bv => test_vector,
				   delay_between_values => 10 ns );

  (a, b, c) <= test_vector;

end architecture test;
