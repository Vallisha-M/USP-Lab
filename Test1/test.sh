#!/bin/bash
ten=10
for ((i=1;i<=20;i++)); do
	square=`expr $i \* $i`
	reverse=0
	original_square=$square
	entered=0
	while [ $square -gt 0 ] ; do
		entered=1
		d=`expr $square % $ten`
		reverse=`expr $reverse \* $ten`
		reverse=`expr $reverse + $d`
		square=`expr $square \/ $ten`
	done

	if [ $reverse -eq $original_square ] || [ $entered -eq 0 ] ; then
		echo "$i^2 = $original_square is a palindrome"
	else
		echo "$i^2 = $original_square is not a palindrome"
	fi
done
