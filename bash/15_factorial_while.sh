#!/bin/bash

#shell script for factorial of a number
#factorial using while loop

echo 'enter a number'
read num
i=2
fact=1
while [ $i -le $num ]
do
    fact=$(($fact * $i))
    i=$(($i+1))
done
echo $fact