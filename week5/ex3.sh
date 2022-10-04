gcc ex3.c -o ex3
start_time=`date +%s`
./ex3 10000000 1
end_time=`date +%s`
echo execution time was `expr $end_time - $start_time` s for m=1.
start_time=`date +%s`
./ex3 10000000 2
end_time=`date +%s`
echo execution time was `expr $end_time - $start_time` s for m=2.
start_time=`date +%s`
./ex3 10000000 4
end_time=`date +%s`
echo execution time was `expr $end_time - $start_time` s for m=4.
start_time=`date +%s`
./ex3 10000000 10
end_time=`date +%s`
echo execution time was `expr $end_time - $start_time` s for m=10.
start_time=`date +%s`
./ex3 10000000 100
end_time=`date +%s`
echo execution time was `expr $end_time - $start_time` s for m=100.
