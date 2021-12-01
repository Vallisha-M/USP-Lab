#!/bin/sh
echo "Enter base"
read b
echo "Enter exponent"
read n
i=1
ans=1
while [ $i -le $n ]; do
ans=`expr $ans \* $b`
i=`expr $i + 1`
done
echo "$b^$n = "$ans

