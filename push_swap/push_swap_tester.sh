#!/bin/bash

if [ "$#" -lt 4 ]; then
    echo "Usage: $0 start_range end_range repeat_count [-debug] [-with_steps]"
    exit 1
fi

START_RANGE=$1
END_RANGE=$2
COUNT=$3
REPEATS=$4

DEBUG_MODE=0
WITH_STEPS=0
if [ "$#" -eq 5 ]; then
    if [ "$5" == "-debug" ]; then
        DEBUG_MODE=1
    fi
    if [ "$5" == "-with_steps" ]; then
        WITH_STEPS=1
    fi
fi

if [ "$#" -eq 6 ]; then
    if [ "$6" == "-with_steps" ]; then
        WITH_STEPS=1
    fi
fi

make

for i in $(seq 1 $REPEATS)
do
    # Generate $COUNT unique random numbers within the specified range
    ARG=$(shuf -i $START_RANGE-$END_RANGE -n $COUNT | tr '\n' ' ')

    echo -ne "= Iteration $i\t| "
    output=$(./push_swap $ARG | ./checker_linux $ARG)
    if [ "$output" == "OK" ]; then
        echo -e "\033[32m$output\033[0m"
    else
        echo -e "\033[31m$output\033[0m"
    fi
 
    if [ $WITH_STEPS -eq 1 ]; then
        STEP_COUNT=$(./push_swap $ARG | wc -l)
        echo -e "== STEPS: $STEP_COUNT\n"    
    fi
    
	if [ $DEBUG_MODE -eq 1 ]; then
    	echo -e "\nARG=\"$ARG\"\n"
	fi
done
