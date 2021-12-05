#!/bin/sh
echo "Enter the basic salary"
read basic_salary
echo "Enter DA percentage"
read da
da=`echo "scale=2;$da/100" | bc`
echo "Enter HRA percentage"
read hra
hra=`echo "scale=2;$hra/100" | bc`
gross_salary=`echo "$basic_salary + $da * $basic_salary + $hra* $basic_salary " | bc`
echo "Gross Salary is $"$gross_salary
