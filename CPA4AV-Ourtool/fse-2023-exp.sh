#!/bin/bash
# this file test the tasks in dir 'targetDir'
# this file should be run under 'CPA4AV-Ourtoll' dir
# usage: ./fse-2023-exp.sh config/example.properties targetDir 

# judge whether the config file exist
if [ $# -eq 0 ];then
	echo "missing .properties file && test_file_dir"
	exit 0
elif [ $1 == "" ];then
	echo "missing .properties file"
	exit 0
elif [ $2 == "" ];then
	echo "missing test_file_dir"
	exit 0
elif [ ! -e $1 ];then
	echo "the file $1 does not exist!"
	exit 0
elif [ ! -d $2 ];then
	echo "test_file_dir $2 does not exist!"
	exit 0
fi

# generate the output file (.md)
config_file=$1
test_file_dir=$2
# output="$(date +%y-%m-%d_%H-%M).md"
output="results.md"
touch $output
touch tmp.out
echo "### $(date)" > $output
echo "> `cat /proc/cpuinfo | grep "model name" | uniq | awk '{ print $4," ",$5," ",$6," ",$7,$9 }'`" >> $output
echo "" >> $output
echo "| task-name | RWR | WRW | RWW | WWR | total-bugs| state | total time(ms) |" >> $output
echo "| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | " >> $output

# run the ./scripts/cpa.sh for task in 'racebench'
for task in $(ls $test_file_dir | grep -E ".*\.c")
do
	# m1:RWR, m2:WRW, m3:RWW, m4:WWR
	total_num=0 m1=0 m2=0 m3=0 m4=0 exstate=0 time=0 i=1 flag=0 
	task="$test_file_dir/$task"
	# for line in $lines (attention: 'for' will read content separated by space)
	# but 'while read' will read content separeted by newline)
	./scripts/cpa.sh -config "./config/${config_file##*/}" -nolog $task | grep -E "(^[RW][RW][RW])|(explored\ states)|(total\ time)" > tmp.out
   	while read line
	do 
		flag=$[flag+1] 
		case $i in  
			1) exstate=$(echo $line | awk '/explored.*/{ print $3 }') 
				i=$(($i+1)) 
				;;
			2) time=$(echo $line | awk '/total.*/{ print $3 }') 
				i=$(($i+1)) 
				;; 
			3) m1=$(echo $line | awk '/^[RW]/ { print $4 }') 
				i=$(($i+1)) 
				;; 
			4) m2=$(echo $line | awk '/^[RW]/ { print $4 }') 
				i=$(($i+1)) 
				;; 
			5) m3=$(echo $line | awk '/^[RW]/ { print $4 }') 
				i=$(($i+1)) 
				;; 
			6) m4=$(echo $line | awk '/^[RW]/ { print $4 }') 
				i=1 
				;; 
		esac; 
		
		# when "^C" caught, break the loop
		trap "break" SIGINT
	done < tmp.out

	# can't give a valid answer, like unsupport array
	if [ $flag == 0 ];then
		echo "| ${task##*/} | --- | --- | --- | --- | --- | --- | --- |" >> $output 		
		continue
	# give a valid answer
	else
		echo "${task##*/}: m1(RWR) = $m1, m2(WRW) = $m2, m3(RWW) = $m3, m4(WWR) = $m4, state = $exstate, time = $time"
		total_num=$(($m1+$m2+$m3+$m4))
		echo "| ${task##*/} | ${m1} | ${m2} | ${m3} | ${m4} | $total_num | $exstate | $time |" >> $output
		total_num=0 m1=0 m2=0 m3=0 m4=0 time=0 state=0
		flag=0
	fi


	# when "^C" caught, break the loop
	trap "break" SIGINT
done
if [ -e a.out ];then
	rm -rf a.out
	exit 0
	echo "done!"
fi

[ -e tmp.out ] && rm -rf tmp.out;

trap "echo 'exit'" EXIT
