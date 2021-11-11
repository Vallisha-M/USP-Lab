#!/bin/sh/
echo "Enter n"
read n
i=1
fact=1
while [ $i -le $n ]
do
	fact=`echo "$fact * $i" | bc`
	i=`echo "$i+1" | bc`
done
echo "Factorial = "$fact
