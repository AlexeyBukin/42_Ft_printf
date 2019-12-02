#!/bin/zsh
clang -Wall -Wextra -Werror -L libft/ src/*.c -I libft/includes -I includes -lft -o danya.exe
./danya.exe