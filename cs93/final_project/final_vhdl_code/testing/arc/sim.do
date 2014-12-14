#vlib work 
view structure
# counter is the top level workbench
#vsim -t 1ms -voptargs=+acc -L work counter
vsim -t 1ms -L work counter
#do counter.do 
run -all 
