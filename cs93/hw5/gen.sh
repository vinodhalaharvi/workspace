for file in $(ls asm/hardware/asm/*.asm) ; 
do 
	cp $file asm/test.asm ; 
	runas > /tmp/temp.res;  
	cp /tmp/temp.res $file.res; 
	cp mif/test.mif $file.mif; 
done; 
