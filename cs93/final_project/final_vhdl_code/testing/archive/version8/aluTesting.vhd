entity  AluTesting is
	port (
		     ALU_Z : out std_logic; 
		     ALU_C : out std_logic; 
		     ALU_result : buffer  std_logic_vector(31 downto 0);
			--debuffing
		     seg0 : out std_logic_vector (6 downto 0); 
		     seg1 : out std_logic_vector (6 downto 0); 
		     seg2 : out std_logic_vector (6 downto 0); 
		     seg3 : out std_logic_vector (6 downto 0); 
		     aluCode : in std_logic_vector(3 downto 0)
); 
end entity AluTesting;

architecture AluTesting_arch of AluTesting  is
	attribute chip_pin : string;
	attribute chip_pin of seg0 : signal is "G18, F22, E17, L26, L25, J22, H22";
	attribute chip_pin of seg1 : signal is "M24, Y22, W21, W22, W25, U23, U24";
	attribute chip_pin of seg2 : signal is "AA25, AA26, Y25, W26, Y26, W27, W28";
	attribute chip_pin of seg3 : signal is "V21, U21, AB20, AA21, AD24, AF23, Y19";
	attribute chip_pin of ALU_Z : signal is "G19"; 
	attribute chip_pin of ALU_C : signal is "F19"; 
	signal IR_decode_add ,
		IR_decode_sub ,
		IR_decode_sll ,
		IR_decode_srl ,
		IR_decode_sllv ,
		IR_decode_srav ,
		IR_decode_slt ,
		IR_decode_beq ,
		IR_decode_bne ,
		IR_decode_addi ,
		IR_decode_slti ,
		IR_decode_andi ,
		IR_decode_ori ,
		IR_decode_lui ,
		IR_decode_lw ,
		IR_decode_sb ,
		IR_decode_sw : std_logic; 
--IR31_26 IR25_21 IR20_16 IR15_11 IR10_6 IR5_0 
begin
	sevenSegTesting0_inst: entity sevenSegTesting 
	port map (
			 bcd => ALU_result(3 downto 0), 
			 seg => seg0 
		 ); 
	sevenSegTesting1: entity sevenSegTesting 
	port map (
			 bcd => ALU_result(7 downto 4), 
			 seg => seg1 
		 ); 
	sevenSegTesting2: entity sevenSegTesting 
	port map (
			 bcd => ALU_result(11 downto 8), 
			 seg => seg2 
		 ); 
	sevenSegTesting3: entity sevenSegTesting 
	port map (
			 bcd => ALU_result(15 downto 12), 
			 seg => seg3 
		 ); 

	case aluCode is
		when "0001" => IR_decode_sll <= '1'; 
		when "0010" => IR_decode_srl <= '1'; 
		when "0011" => IR_decode_sllv <= '1'; 
		when "0100" => IR_decode_srav <= '1'; 
		when "0110" => IR_decode_add <= '1'; 
		when "0101" => IR_decode_sub <= '1'; 
		when "0111" => IR_decode_slt <= '1'; 
		when "1000" => IR_decode_beq <= '1'; 
		when "1001" => IR_decode_bne <= '1'; 
		when "1010" => IR_decode_addi <= '1'; 
		when "1011" => IR_decode_slti <= '1'; 
		when "1100" => IR_decode_andi <= '1'; 
		when "1101" => IR_decode_ori <= '1'; 
		when "1110" => IR_decode_lui <= '1'; 
		when "1111" => IR_decode_lw <= '1'; 
	end case; 


	ALU_Inst : process (all)
	begin
		case '1' is
			when IR_decode_add =>
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR25_21))) + ('0' & GPR(to_integer(IR20_16)));
			when IR_decode_sub =>
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR25_21))) - ('0' & GPR(to_integer(IR20_16)));
			when IR_decode_sll =>
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR20_16))) sll to_integer(IR10_6);
			when IR_decode_srl =>
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR20_16))) srl to_integer(IR10_6);
			when IR_decode_sllv => 
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR20_16))) sll GPR(to_integer(IR25_21)); 
			when IR_decode_srav => 
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR20_16))) srl GPR(to_integer(IR25_21)); 
			when IR_decode_slt => 
				ALU_result <= GPR(to_integer(IR25_21))) < GPR(to_integer(IR20_16))); 
			when IR_decode_beq => 
				ALU_Z <= GPR(to_integer(IR25_21)) = GPR(to_integer(IR20)); 
			when IR_decode_bne => 
				ALU_Z <= GPR(to_integer(IR25_21)) /= GPR(to_integer(IR20)); 
			when IR_decode_addi => 
				(ALU_C, ALU_result) <= ('0' & GPR(to_integer(IR25_21))) + ('0' & IR_immed);
			when IR_decode_slti => 
				ALU_result <= GPR(to_integer(IR25_21))) < IR_immed;  
			when IR_decode_andi => 
				ALU_result <= GPR(to_integer(IR25_21))) and IR_immed;  
			when IR_decode_ori => 
				ALU_result <= GPR(to_integer(IR25_21))) or IR_immed;  
			when IR_decode_lui => 
				ALU_result <= (IR_immed sll 16) and X"000000FF"; 
			when IR_decode_lw => 
				ALU_result <= GPR(to_integer(IR25_21)) + IR_offset; 
			when IR_decode_sb => 
				ALU_result <= GPR(to_integer(IR25_21)) + IR_offset; 
			when IR_decode_sw => 
				ALU_result <= GPR(to_integer(IR25_21)) + IR_offset; 
			when others =>
				(ALU_C, ALU_result) <= 'X' & unsigned_byte'(others => 'X');
		end case;
		if ALU_result = X"00000000" then 
			ALU_Z <= '1';
		end if; 
	end process ALU_Inst;



end architecture AluTesting_arch;
