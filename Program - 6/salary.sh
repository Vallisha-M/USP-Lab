#!/bin/sh
echo "Enter the basic salary"
read basic_salary
gross_salary=`echo "$basic_salary + 0.1 * $basic_salary + 0.2 * $basic_salary " | bc`
echo "Gross Salary is $"$gross_salary
