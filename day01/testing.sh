#!bin/bash

while true
do
    gcc -g3 -I./gnl gnl/get_next_line.c gnl/get_next_line_utils.c day01-pt2.c && ./a.out
    sleep 2
    clear
done
