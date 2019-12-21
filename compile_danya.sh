#!/bin/zsh
clang -Wall -L libft/  src/*.c src/flags/*.c -I libft/includes -I includes -lft -g -o danya.exe
./danya.exe
#src/*.c src/flags/*.c

#src/main.c