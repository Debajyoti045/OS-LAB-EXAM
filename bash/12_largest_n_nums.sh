#!/bin/bash
# shell script for largest of n numbers

echo 'total numbers'
read N
mx=0
while [ $N -gt 0 ]
do
    read num
    if [ $num -gt $mx ]
    then
        mx=$num
    fi
    N=$(($N-1))
done
echo $mx