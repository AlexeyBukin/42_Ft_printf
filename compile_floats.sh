#!/bin/zsh
clang -Wall -Wextra -Werror -I includes -I libft/includes -lft src/floats.c -o floats.exe -L libft
./floats.exe