entity fg_05_08 is
end entity fg_05_08;

architecture test of fg_05_08 is

  constant T_pw : time := 10 ns;

  signal clk : bit;

begin

  -- code from book

  clock_gen : process is
  begin
    clk <= '1' after T_pw, '0' after 2*T_pw;
    wait for 2*T_pw;
  end process clock_gen;

  -- end code from book

end architecture test;