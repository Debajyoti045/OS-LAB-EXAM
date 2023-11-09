#!/bin/bash
# Print numbers 1 to 100 using while loop - Shell Script

echo 'enter the upper limit'
read lim
i=1
while [ $i -le $lim ]
do
    echo $i
    i=$(($i+1))
done