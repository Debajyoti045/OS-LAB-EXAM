#!/bin/bash
# Shell script to print sum of all digit using expr

echo 'enter the number'
read num
sum=0
while [ $num -gt 0 ]
do
    mod=`expr $num % 10`
    sum=`expr $sum + $mod`
    num=`expr $num / 10`
done
echo $sum