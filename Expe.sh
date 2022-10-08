#!/bin/bash
sizeN=(10 20 50 100 150 200 300 400 500)
sizeM=(5 10 15 20 25 30 35 40 45 50)

for i in "${sizeN[@]}";
do
	for j in "${sizeM[@]}";
	do
		./program.exe EjemploDic.txt $i $j > ./Ejemplos/Vector/VectorN"${i}"M"${j}".txt
	done
done
