#!/bin/bash
Name=$1
sizeN=(2 3 4 5 6 7 8 9 10)
sizeM=(2 3 4 5 6 7 8 9 10)
SEED=0

for i in "${sizeN[@]}";
do
	for j in "${sizeM[@]}";
	do
		echo "$Name"N"${i}"M"${j}"
		./program.exe EjemploDic.txt $i $j $SEED > ./Ejemplos/$Name/"$Name"N"${i}"M"${j}".txt
	done
done
