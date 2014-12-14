entity test_bench_03_06 is

end entity test_bench_03_06;


----------------------------------------------------------------


architecture test_cos_series of test_bench_03_06 is

  signal theta, result : real := 0.0;

begin

  dut : entity work.cos(series)
    port map ( theta => theta, result => result );

  stimulus : process is

    constant pi : real := 3.1415927;

  begin
    wait for 10 ns;
    theta <= pi / 6.0;		wait for 10 ns;
    theta <= pi / 4.0;		wait for 10 ns;
    theta <= pi / 3.0;		wait for 10 ns;
    theta <= pi / 2.0;		wait for 10 ns;

    wait;
  end process stimulus;

end architecture test_cos_series;
