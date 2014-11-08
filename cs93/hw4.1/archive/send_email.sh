for file in $(ls *.c) 
do 
	cat $file | mail -s "$file" vinod.halaharvi@gmail.com 
	echo $file Done .. 
done

