#!/bin/sh
echo "Enter the number"
read square
reverse=0
ten=10
entered=0
original_square=$square
while [ $square -gt 1 ]; do
		entered=1
		d=`expr $square % $ten`
		reverse=`expr $reverse \* $ten`
		reverse=`expr $reverse + $d`
		square=`expr $square \/ $ten`
done
if [ $reverse -eq $original_square ] || [ $entered -eq 0 ]; then
		echo "$reverse is a palindrome"
else
		echo " $original_square is not a palindrome"
fi
