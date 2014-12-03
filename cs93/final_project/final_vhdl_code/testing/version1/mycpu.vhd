library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
use mycpu_defs.all; 

entity  mycpu is
	port (
		     sysclk1 : in std_logic; 
		     mem_data_read : in std_logic_vector(31 downto 0);
		     mem_dataready_inv : in std_logic;
		     mem_ready : in std_logic;
		     reset : in std_logic;

		     mem_addr : out std_logic_vector(20 downto 0);
		     mem_data_write : buffer std_logic_vector(31 downto 0);
		     mem_rw : buffer std_logic;
		     mem_sixteenbit : buffer std_logic;
		     mem_thirtytwobit : buffer std_logic;
		     mem_addressready : buffer std_logic;
			-- just for output
		     --IR : out std_logic_vector(31 downto 0); 
		     IR : out instruction; 
		     fsmStateCode : out std_logic_vector(3 downto 0)
	     ); 
end entity mycpu;

architecture mycpu_arch of mycpu  is
	signal mem_data_read_internal : std_logic_vector(31 downto 0) := X"00000000";
	type control_state is (
		Init, 
		WaitForMemDataReadyInvHigh, 
		WaitForMemDataReadyInvLow,	
		SetControlAndDataInputs,
		ReadInputData, 
		pc_increment, 
		decode_state,
		execute_state,
	);

	--decode_state signals
	signal IR : instruction;
	alias IR_rd : reg_addr is IR(15 downto 11);
	alias IR_rs : reg_addr is IR(25 downto 21);
	alias IR_r2 : reg_addr is IR(20 downto 16);
	alias IR_immed : immed is IR(15 downto 0);
	alias IR_offset : disp is IR(15 downto 0);
	alias IR_count : shift_count is IR(10 downto 6);

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
		IR_decode_sw : std_ulogic;

	--execute_state state signals
	signal state : control_state := Init; 
	signal mem_addr_internal :  std_logic_vector(20 downto 0);
	signal GPR_rs, GPR_r2 :  std_logic_vector(31 downto 0);
	signal alu_fn_code :  std_logic_vector(5 downto 0); 
	signal ALU_C :  std_logic;
	signal ALU_Z :  std_logic;
	signal ALU_result :  std_logic_vector(31 downto 0);
	signal ALU_out : std_logic_vector(31 downto 0); 
	signal PC : IMem_addr;
begin
	--IR_decode_sll <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000000"; 
	--IR_decode_srl <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000010"; 
	--IR_decode_sllv <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "000100"; 
	--IR_decode_srav <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100000"; 
	--IR_decode_add <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100000"; 
	--IR_decode_sub <= IR(31 downto 26) ?= "000000" and IR(5 downto 0) ?= "100010"; 
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

	alu_inst : entity alu is
		port map (
		--inputs 
		GPR_rs, => GPR_rs,
		GPR_r2 => GPR_r2, 
		alu_fn_code => alu_fn_code,
		--outputs
		ALU_C => ALU_C,
		ALU_Z => ALU_Z,
		ALU_result => ALU_result
	);


	FSM :
	process(mem_data_read, mem_dataready_inv, mem_ready) is
	begin
		if rising_edge(sysclk1) then
			case state is
				when Init =>
					next_state <= WaitForMemDataReadyInvHigh;
					if mem_rw = '0' then
						mem_rw <= '1';
					else 
						mem_rw <= '0';
					end if;
				when WaitForMemDataReadyInvHigh =>
					if mem_dataready_inv = '1'  then 
						next_state <= SetControlAndDataInputs; 
					end if;
				when SetControlAndDataInputs =>
					if mem_rw = '1' then 
						mem_addr <= '0' & PC;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						mem_data_write <= mem_data_read_internal;
						next_state <= WaitForMemDataReadyInvLow; 
					else
						mem_addr <= '0' & PC;
						mem_sixteenbit <= '0';
						mem_thirtytwobit <= '1';
						mem_addressready <= '1';
						next_state <= WaitForMemDataReadyInvLow; 
					end if;
				when WaitForMemDataReadyInvLow =>
					if mem_dataready_inv = '0' then 
						if mem_rw = '0' then 
							next_state <= ReadInputData; 
						else
							mem_addressready <=  '0'; 
							next_state <= pc_increment; 
						end if;
					end if; 
				when ReadInputData =>
					mem_data_read_internal <= mem_data_read
					mem_addressready <=  '0'; 
					next_state <= pc_increment; 
				when pc_increment =>
					PC <= std_logic_vector(unsigned(PC) + 2); 
					next_state <= decode_state;
				when decode_state =>
					-- set the right operands for the ALU
					next_state <= execute_state; 
				when execute_state =>
					-- get the output from the ALU  if this is a ALU operation
					-- else perform other operations like branching etc.
					case  IR(31 downto 26) is
						when =>  op_fn_special | op_fn_addi | op_fn_slti 
							 |  op_fn_andi | op_fn_ori 
							next_state <= write_back_state; 	
						when =>  op_fn_jr   
							next_state <= pc_state; 
						when =>  op_fn_j    
							next_state <= pc_state; 
						when =>  op_fn_jal  
							next_state <= pc_state; 
						when =>  op_fn_beq  
							next_state <= branch_state; 
						when =>  op_fn_bne  
							next_state <= branch_state; 
						when =>  op_fn_lui  
							next_state <= mem_state; 	
						when =>  op_fn_lw   
							next_state <= mem_state; 	
						when =>  op_fn_sb   
							next_state <= write_back_state; 	
						when =>  op_fn_sw   
							next_state <= write_back_state; 	
					end case; 
			end case;
		end if;
	end process;

	update : process (sysclk1, reset) is
	begin
		if reset = '1' then 
			PC <= X"00000"; 
		elsif rising_edge(clk) then
			state <= next_state; 
		end if;
	end process update;
	

	IR <= mem_data_read_internal; 
	with state select
		fsmStateCode <=
	       "0000" when Init,
	       "0001" when WaitForMemDataReadyInvHigh,
	       "0010" when SetControlAndDataInputs,
	       "0011" when WaitForMemDataReadyInvLow,
	       "0101" when pc_increment,
	       "0110" when ReadInputData,
	       "0111" when decode_state,
	       "1000" when execute_state,
	       "1111" when others;

end architecture mycpu_arch;
