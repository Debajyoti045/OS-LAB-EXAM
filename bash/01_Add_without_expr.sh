#!/bin/bash
# Add two variables without using expr in shell script

var1=10
var2=20
sum=$(($var1+$var2))
echo $sum
