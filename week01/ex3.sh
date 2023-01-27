mkdir ~/week1/dir1
printf "Date is : $(date)\n"
sleep 3
mkdir ~/week1/dir2
printf "Date is : $(date)\n"
sleep 3
touch ~/week1/dir1/root.txt
printf "Date is : $(date)\n"
sleep 3
touch ~/week1/dir2/home.txt
printf "Date is : $(date)\n"
sleep 3
ls -lr ~/ > ~/week1/dir2/home.txt 
ls -lr / > ~/week1/dir1/root.txt 
cat ~/week1/dir1/root.txt
cat ~/week1/dir2/home.txt
