#!/bin/bash
#shell script to find average of n numbers

echo 'total numbers'
read N
sum=0
n=$N
while [ $n -gt 0 ]
do
    read num
    sum=$(($sum+$num))
    n=$(($n-1))
done
avg=$(echo $sum / $N | bc -l)
echo $avg
