#!/usr/bin/env bash
## ETNA PROJECT, 02/04/2021 by feuvra_v
## make_testfile
## File description:
##      generates random test files for my_crd
##

#!/bin/bash

make_second_part() {
    follow=$(($RANDOM%3+1))
    if [[ follow -eq 1 ]]; then
        echo $(shuf -i 1-2147483647 -n 1)
    elif [[ follow -eq 2 ]]; then
        echo 'D'
    fi
}

small_keys() {
    i=1
    echo $(($RANDOM%$1+1)) $(make_second_part) > $3
    while [[ $i -lt $2 ]]; do
        echo $(($RANDOM%$1+1)) $(make_second_part) >> $3
        i=$(($i+1))
    done
}

big_keys() {
    i=1
    echo $(shuf -i 1-$1 -n 1) $(make_second_part) > $3
    while [[ $i -lt $2 ]]; do
        echo $(shuf -i 1-$1 -n 1) $(make_second_part) >> $3
        i=$(($i+1))
    done
}

echo "writing output file"
if [[ $1 -le 32767 ]]; then
    small_keys $1 $2 $3
else
    big_keys $1 $2 $3
fi
echo $3 "has been generated"
