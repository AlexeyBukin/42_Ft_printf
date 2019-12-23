#!/bin/zsh
clang -L libft/  src/*.c src/flags/*.c -I libft/includes -I includes -lft -g -o danya.exe
valgrind --track-origins=yes --leak-check=full ./danya.exe
#src/*.c src/flags/*.c

#src/main.c