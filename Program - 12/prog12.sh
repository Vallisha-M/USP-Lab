#!/bin/sh
echo "Enter n"
read n
i=1
sum=0
while [ $i -le $n ]; do
sum=`expr $sum + $i`
i=`expr $i + 1`
done
echo "Sum of natural numbers upto n = "$sum
