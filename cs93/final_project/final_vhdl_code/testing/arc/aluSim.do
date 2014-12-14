#Simulation script for VHDL  aluSim demo
onbreak (resume)
#compile using "-just" command to resolve order dependiencides

echo  --------> compile package, bodies, entities and architecture
vcom +cover -2008 -just p *.vhd
vcom +cover -2008 -just b *.vhd
vcom +cover -2008 -just e *.vhd
vcom +cover -2008 -just a *.vhd

#optimization if needed
#vopt +acc aluSim_tb -o aluSim_tb_opt

# start simulation
echo ----------> simulate design
vsim -t 10ns -L work aluSim_tb

# Wave signals
add wave /* 

# run the simulation
run 1000ms 
