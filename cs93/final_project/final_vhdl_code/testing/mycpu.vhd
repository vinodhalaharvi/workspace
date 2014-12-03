library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
use mycpu_defs.all;

entity  mycpu is
	port (
		     sysclk1 : in std_logic; 
		     reset : in std_logic; 
		     mem_data_read : in std_logic_vector(31 downto 0);
		     mem_dataready_inv : in std_logic;
		     mem_ready : in std_logic;

		     mem_addr : out std_logic_vector(20 downto 0);
		     mem_data_write : buffer std_logic_vector(31 downto 0);
		     mem_rw : buffer std_logic;
		     mem_sixteenbit : buffer std_logic;
		     mem_thirtytwobit : buffer std_logic;
		     mem_addressready : buffer std_logic;

		     ALU_result : buffer std_logic_vector(31 downto 0); 
		     destination_register : buffer std_logic_vector(31 downto 0); 
		     IR : buffer std_logic_vector(31 downto 0); 
		     PC :  buffer std_logic_vector(19 downto 0) := X"00000";
		     fsmStateCode : out std_logic_vector(3 downto 0)
	     ); 
end entity mycpu;

architecture mycpu_arch of mycpu  is
	signal mem_data_read_internal : std_logic_vector(31 downto 0) := X"00000000";
	type states is (
	Init, WaitForMemDataReadyInvHigh, 
	WaitForMemDataReadyInvLow,	
	SetControlAndDataInputs,
	write_back_state, 
	decode_state, 
	ReadInputData, 
	pc_increment);
	signal currentState : states := Init; 

	--signal PC :  std_logic_vector(19 downto 0) := X"00000";
	signal mem_addr_internal :  std_logic_vector(20 downto 0);

	-- deleteme later
	signal GPR_rs : std_logic_vector(31 downto 0); 
	signal GPR_r2 : std_logic_vector(31 downto 0); 
	signal ALU_C : std_logic; 
	signal ALU_Z : std_logic; 
	--signal ALU_result : std_logic_vector(31 downto 0); 

	--signal PC : IMem_addr;
	alias IR_alu_reg_fn : alu_fn_code is IR(5 downto 0);
	alias IR_rd : reg_addr is unsigned(IR(15 downto 11));
	alias IR_rs : reg_addr is unsigned(IR(25 downto 21));
	alias IR_r2 : reg_addr is unsigned(IR(20 downto 16));
	alias IR_immed : immed is unsigned(IR(15 downto 0));
	alias IR_count : shift_count is unsigned(IR(10 downto 6));
	alias IR_offset : disp is unsigned(IR(15 downto 0));
	signal IR_decode_alu_immed,
		IR_decode_mem, IR_decode_shift,
		IR_decode_alu_reg,
		IR_decode_jump,
		IR_decode_branch,
		IR_decode_misc : std_logic := '0';
	signal D_state : std_logic;
	signal cc_Z : std_logic;
	signal cc_C : std_logic;
	signal D : unsigned_byte;
	signal IR_decode_sll,
	IR_decode_srl,
	IR_decode_sllv,
	IR_decode_srav,
	IR_decode_add,
	IR_decode_sub,
	IR_decode_slt,
	IR_decode_jr,
	IR_decode_j,
	IR_decode_jal,
	IR_decode_beq,
	IR_decode_bne,
	IR_decode_addi,
	IR_decode_slti,
	IR_decode_andi,
	IR_decode_ori,
	IR_decode_lui,
	IR_decode_lw,
	IR_decode_sb,
	IR_decode_sw : std_logic := '0';
begin

	IR_decode_add <= '1';
	IR_decode_sub <= '0';


	--IR_decode_sub <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100010"; 
	--IR_decode_sll <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000000"; 
	--IR_decode_srl <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000010"; 
	--IR_decode_sllv <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000100"; 
	--IR_decode_srav <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100000"; 
	--IR_decode_slt <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "101010"; 
	--IR_decode_jr <= IR(31 downto 26) ?= "000000"  and IR(5 downto 0) ?= "001000" ;
	--IR_decode_j <= IR(31 downto 26) ?= "000010";
	--IR_decode_jal <= IR(31 downto 26) ?= "000011";
	--IR_decode_beq <= IR(31 downto 26) ?= "000100";
	--IR_decode_bne <= IR(31 downto 26) ?= "000101";
	--IR_decode_addi <= IR(31 downto 26) ?= "001000";
	--IR_decode_slti <= IR(31 downto 26) ?= "001010";
	--IR_decode_andi <= IR(31 downto 26) ?= "001100";
	--IR_decode_ori <= IR(31 downto 26) ?= "001101";
	--IR_decode_lui <= IR(31 downto 26) ?= "001111";
	--IR_decode_lw <= IR(31 downto 26) ?= "100011";
	--IR_decode_sb <= IR(31 downto 26) ?= "101000";
	--IR_decode_sw <= IR(31 downto 26) ?= "101010";

	IR_decode_alu_reg <=   IR_decode_add or IR_decode_sub; 
	IR <= mem_data_read_internal; 
	-- add alu entity here here
	alu_inst : entity alu port map
	(
		--GPR_rs => GPR_rs,
		--GPR_r2 => GPR_r2,
		--alu_fn_code => "100000",
		GPR_rs => X"00000006",
		GPR_r2 => X"00000003",
		alu_fn_code => IR(5 downto 0), 
		ALU_C => ALU_C,
		ALU_Z => ALU_Z,
		ALU_result => ALU_result
	);

	-- add register file process here
	GPR_mem : process (sysclk1)
		subtype reg_index is natural range 0 to 31;
		variable r2_addr : reg_addr;
		--variable write_data : unsigned_byte;
		variable write_data: std_logic_vector(31 downto 0); 
		subtype double_word is std_logic_vector(31 downto 0); 
		type std_logic_vector_array is array (reg_index) of double_word;
		variable GPR : std_logic_vector_array := (others => X"00000000");
	begin
		if rising_edge(sysclk1) then
			if reset then
				GPR := (others => (others => '0'));
			else
				if currentState = write_back_state and IR_rd /= 0 then
					if IR_decode_alu_reg then 
						write_data := ALU_result;
					end if;
					GPR(to_integer(IR_rd)) := write_data;
					destination_register <= write_data; 
				end if;
				if currentState = decode_state then
					if IR_decode_mem then 
						r2_addr := IR_rd;
					else
						r2_addr := IR_r2;
					end if;
					GPR_rs <= GPR(to_integer(IR_rs));
					GPR_r2 <= GPR(to_integer(r2_addr));
				end if;
			end if;
		end if;
	end process GPR_mem;

	FSM :
	process(sysclk1, mem_data_read, mem_dataready_inv, mem_ready) is
	begin
		if rising_edge(sysclk1) then
			case currentState is
				when Init =>
					currentState <= WaitForMemDataReadyInvHigh;
					if mem_rw = '0' then
						mem_rw <= '1';
					else 
						mem_rw <= '0';
					end if;
				when WaitForMemDataReadyInvHigh =>
					if mem_dataready_inv = '1'  then 
						currentState <= SetControlAndDataInputs; 
					end if;
				when SetControlAndDataInputs =>
					if mem_rw = '1' then 
						mem_addr <= '0' & PC;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						mem_data_write <= mem_data_read_internal;
						currentState <= WaitForMemDataReadyInvLow; 
					else
						mem_addr <= '0' & PC;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						currentState <= WaitForMemDataReadyInvLow; 
					end if;
				when WaitForMemDataReadyInvLow =>
					if mem_dataready_inv = '0' then 
						if mem_rw = '0' then 
							currentState <= ReadInputData; 
						else
							mem_addressready <=  '0'; 
							currentState <= pc_increment; 
						end if;
					end if; 
				when ReadInputData =>
					mem_data_read_internal <= mem_data_read;
					mem_addressready <=  '0'; 
					currentState <= pc_increment; 
				when pc_increment =>
					PC <= std_logic_vector(unsigned(PC) + 2); 
					currentState <= Init;
				when others => 
					currentState <= Init; 
			end case;
		end if;
	end process;

	with currentState select
		fsmStateCode <=
	       "0000" when Init,
	       "0001" when WaitForMemDataReadyInvHigh,
	       "0010" when SetControlAndDataInputs,
	       "0011" when WaitForMemDataReadyInvLow,
	       "0101" when pc_increment,
	       "0110" when write_back_state,
	       "0111" when decode_state,
	       "0100" when ReadInputData,
	       "1111" when others;

end architecture mycpu_arch;
