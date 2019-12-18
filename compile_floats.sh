#!/bin/zsh
clang -Wall -Wextra -Werror -I includes -I libft/includes src/floats.c -o floats.exe -L libft -lft
./floats.exe