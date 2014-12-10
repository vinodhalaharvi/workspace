#Simulation script for VHDL  hardwareSim demo
onbreak (resume)
#compile using "-just" command to resolve order dependiencides

echo  --------> compile package, bodies, entities and architecture
vcom +cover -2008 -just p *.vhd
vcom +cover -2008 -just b *.vhd
vcom +cover -2008 -just e *.vhd
vcom +cover -2008 -just a *.vhd

# start simulation
echo ----------> simulate design
vsim -t 10ns -L work hardwareSim_tb

# Wave signals
add wave /* 

# run the simulation
run 1000ms 
