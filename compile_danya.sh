#!/bin/zsh
clang -L libft/ src/*.c src/numbers/*.c -I libft/includes -I includes -lft -o danya.exe
./danya.exe