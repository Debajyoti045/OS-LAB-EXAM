#!/bin/bash
#shell script to check whether a number is positive or negative

echo 'enter a number'
read num

if [ $num -gt 0 ]
then
    echo 'number is positive'
elif [ $num -eq 0 ]
then
    echo 'number is neither positive nor negative'
else
    echo 'number is negative'
fi