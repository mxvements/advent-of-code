#!bin/bash

while true
do
    gcc -g3 -I../ft_get_next_line ../ft_get_next_line/get_next_line.c ../ft_get_next_line/get_next_line_utils.c day02-pt1.c && ./a.out
    sleep 2
    clear
done
