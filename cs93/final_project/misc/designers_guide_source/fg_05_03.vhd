entity fg_05_03 is
end entity fg_05_03;

architecture test of fg_05_03 is

  constant T_pw : time := 10 ns;

  signal clk : bit;

begin

  -- code from book

  clock_gen : process (clk) is
  begin
    if clk = '0' then
      clk <= '1' after T_pw, '0' after 2*T_pw;
    end if;
  end process clock_gen;

  -- end code from book

end architecture test;
