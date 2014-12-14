function copyfromubuntu(){
        scp -i ~/keys/pair1.pem -r ubuntu@54.237.165.19:/home/ubuntu/hd/workspace/cs93/final_project/final_vhdl_code/testing/"$1" ./
}

function copytoubuntu(){
        scp -i ~/keys/pair1.pem "$1" ubuntu@54.237.165.19:/home/ubuntu/hd/workspace/cs93/final_project/final_vhdl_code/testing/
}

for file in alu.vhd de2_115_shell.vhd mycpu.vhd mycpu_defs.vhd
do 
	copytoubuntu $file ;
done;
