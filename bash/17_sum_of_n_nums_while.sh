#!/bin/bash

#shell script to find sum of n numbers

echo 'enter a number'
read num
sum=0
i=1
while [ $i -le $num ]
do
    sum=$(($sum+$i))
    i=$(($i+1))
done
echo $sum