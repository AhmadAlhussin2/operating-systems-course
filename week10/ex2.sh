rm _ex2.txt
mkdir -p ../week1
touch ../week1/file.txt
echo "Ahmad Alhussin" > ../week1/file.txt
link ../week1/file.txt _ex2.txt
touch ex2.txt
number=$(ls -i ../week1/file.txt | awk '{print $1}')
find ../week1/file.txt -inum "$number" > ex2.txt
find ../week1/file.txt -inum "$number" -exec rm {} \; >> ex2.txt
