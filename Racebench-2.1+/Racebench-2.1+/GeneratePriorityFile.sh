#!/bin/bash
# this script is used to generate the '_priority.txt' file
# just for the racebench

rm -rf *.txt

ls . | grep -E ".*\..*c$" | while read file
do
	echo "current file: $file"
	awk 'BEGIN { isrNum=1 }\
	   	/void\ svp_simple.*isr.*().*/ { printf "svp_simple_001_001_isr_%d/%d/%d\n",isrNum,isrNum,isrNum; isrNum++ }'\
	< $file\
	> "${file%.c}_priority.txt"
	echo "${file%.c}_priority.txt done!"
done

