package ch_20_03_a is

  -- code from book:

  attribute cell_name : string;
  attribute pin_number : positive;
  attribute max_wire_delay : delay_length;
  attribute encoding : bit_vector;


  type length is range 0 to integer'high
    units nm;
      um = 1000 nm;
      mm = 1000 um;
      mil = 25400 nm;
    end units length;

  type coordinate is record
      x, y : length;
    end record coordinate;

  attribute cell_position : coordinate;

  -- end of code from book

end package ch_20_03_a;




entity ch_20_03 is

end entity ch_20_03;


----------------------------------------------------------------


architecture std_cell of ch_20_03 is

  use work.ch_20_03_a.all;

  signal enable, clk : bit;

  type state_type is (idle_state, other_state);

  -- code from book:

  attribute cell_name of std_cell : architecture is "DFF_SR_QQNN";
  attribute pin_number of enable : signal is 14;
  attribute max_wire_delay of clk : signal is 50 ps;
  attribute encoding of idle_state : literal is b"0000";
  attribute cell_position of the_fpu : label is ( 540 um, 1200 um );

  -- end of code from book

begin

  the_fpu : block is
  begin
  end block the_fpu;

  process is
    use std.textio.all;
    variable L : line;
  begin
    write(L, std_cell'cell_name);
    writeline(output, L);
    write(L, enable'pin_number);
    writeline(output, L);
    write(L, clk'max_wire_delay);
    writeline(output, L);
    write(L, idle_state[return state_type]'encoding);
    writeline(output, L);
    write(L, length'image(the_fpu'cell_position.x));
    write(L, ' ');
    write(L, length'image(the_fpu'cell_position.y));
    writeline(output, L);

    wait;
  end process;

end architecture std_cell;