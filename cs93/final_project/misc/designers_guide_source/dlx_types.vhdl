library ieee;  use ieee.std_logic_1164.all;

package dlx_types is

  -- little-endian addresses
  subtype dlx_address is std_logic_vector(31 downto 0);
  subtype dlx_bv_address is bit_vector(31 downto 0);

  -- big-endian data words
  subtype dlx_word is std_logic_vector(0 to 31);
  subtype dlx_bv_word is bit_vector(0 to 31);

  type dlx_word_array is array (natural range <>) of dlx_word;

  -- tristate bus driving value
  constant disabled_dlx_word : dlx_word := ( others => 'Z' );

  -- type for specifying data width on the data bus
  subtype dlx_mem_width is std_logic_vector(1 downto 0);

  constant dlx_mem_width_byte : dlx_mem_width := "01";
  constant dlx_mem_width_halfword : dlx_mem_width := "10";
  constant dlx_mem_width_word : dlx_mem_width := "00";

  -- type for controlling trace information generated by model
  type dlx_debug_control is
    ( none,
      msg_every_100_instructions, msg_each_instruction,
      trace_each_instruction, trace_each_step );

end package dlx_types;