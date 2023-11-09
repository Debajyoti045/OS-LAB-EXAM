#!/bin/bash

#shell script to find sum of n numbers

echo 'enter a number'
read num

sum=0
for((i=1;i<=num;i++))
{
    sum=$(($sum+$i))
}
echo $sum