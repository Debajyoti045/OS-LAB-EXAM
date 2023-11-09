#!/bin/bash
#shell script to print numbers 1 to 100
#using for loop

echo 'enter limit'
read lim
for((i=1;i<=lim;i++))
do
    echo $i
done

# other syntex:

for i in {1..100}
do
    echo $i
done
