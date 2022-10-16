#!/bin/bash
sizeN=(2 3 4 5 6 7 8 9 10)
sizeM=(2 3 4 5 6 7 8 9 10)
SEED=(0 1 2 3)



for k in "${SEED[@]}"
do
	if ((k == 0));
		then
			Name="Vector"
	elif ((k ==  1));
		then
			Name="Trie"
			sizeN=(2 3 4 5 6 7 8 9 10 50 100 200 300 400 500)
			sizeM=(2 3 4 5 6 7 8 9 10 20 30 40 50 60)
	elif ((k == 2));
		then
			Name="Bloom"
	else
		Name="DHash"
	fi
	for i in "${sizeN[@]}";
	do
		for j in "${sizeM[@]}";
		do

			echo "SEED=${k}"
			echo "$Name"N"${i}"M"${j}"
			./program.exe UnsorterDic.txt $i $j 0 $k > ./Experiments/$Name/"$Name"N"${i}"M"${j}".txt
		done
	done
done
