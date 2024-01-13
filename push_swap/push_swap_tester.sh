#!/bin/bash

if [ "$#" -lt 3 ]; then
    echo "Usage: $0 start_range end_range count [debug]"
    exit 1
fi

START_RANGE=$1
END_RANGE=$2
COUNT=$3

DEBUG_MODE=0
if [ "$4" == "debug" ]; then
    DEBUG_MODE=1
fi

make

REPEATS=10
for i in $(seq 1 $REPEATS)
do
    # Generate $COUNT unique random numbers within the specified range
    ARG=$(shuf -i $START_RANGE-$END_RANGE -n $COUNT | tr '\n' ' ')

    echo -ne "= Iteration $i\t| "
    ./push_swap $ARG | ./checker_linux $ARG

    STEP_COUNT=$(./push_swap $ARG | wc -l)
    echo -e "== STEPS: $STEP_COUNT\n"
    
	if [ $DEBUG_MODE -eq 1 ]; then
    	echo -e "\nARG=\"$ARG\"\n"
	fi
done
