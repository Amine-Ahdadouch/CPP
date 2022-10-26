#! /bin/sh
# Expects the executable called "main" to be in the same directory
# Needs the tool diff
# Will create a temporary file called tmpIsPrime.a7d371 and tmpIsPrime.a7d372

# Expected result
echo "0 is a prime: False
1 is a prime: False
2 is a prime: True
3 is a prime: True
4 is a prime: False
5 is a prime: True
6 is a prime: False
7 is a prime: True
8 is a prime: False
9 is a prime: False
10 is a prime: False
51321531327 is a prime: False" > tmpIsPrime.a7d371

# Calling your function
echo "0 1 2 3 4 5 6 7 8 9 10 51321531327" | ./main > tmpIsPrime.a7d372

# Getting the difference
rr=$(diff tmpIsPrime.a7d371 tmpIsPrime.a7d372)

if [[ -z $rr ]]
then
    echo "Passed simple test"
else
    echo "Failed for"
    echo "echo \"0 1 2 3 4 5 6 7 8 9 10 51321531327\" | ./main"
    echo "Diff is"
    echo $rr
fi
