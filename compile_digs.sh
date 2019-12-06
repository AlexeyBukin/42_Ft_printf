#!/bin/zsh
clang -Wall -Wextra -Werror -I includes -I libft/includes -lft src/floats.c -o digits.exe -L libft
./digits.exe