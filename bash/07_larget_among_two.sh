#!/bin/bash
#shell script to find the greatest of two numbers

echo 'enter num1'
read num1
echo 'enter num2'
read num2

if [ $num1 -gt $num2 ]
then
    echo $num1
else
    echo $num2
fi