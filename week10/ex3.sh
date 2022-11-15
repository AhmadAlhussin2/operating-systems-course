rm _ex3.txt
rm ex3.txt
touch _ex3.txt
touch ex3.txt
echo "Ahmad Alhussin" > _ex3.txt
chmod a-x _ex3.txt
ls -l > ex3.txt
chmod uo+rwx _ex3.txt
ls -l >> ex3.txt
chmod g=u _ex3.txt
ls -l >> ex3.txt

echo "660 code means Users belonging to your group can change this file, others don't have any access to it at all." >> ex3.txt
echo "775 code means Standard file sharing mode for a group." >> ex3.txt
echo "777 code means Everybody can do everything to this file." >> ex3.txt
