#!/bin/zsh
clang -L libft/  src/*.c src/flags/*.c -I libft/includes -I includes -lft -o danya.exe
./danya.exe
#src/*.c src/flags/*.c

#src/main.c