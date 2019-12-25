# Makefile for ft_printf project in school 21 (ecole 42)
# written by kcharla, 2019
#
# Usage:
#
# 1) `make all' OR `make libftprintf.a' to compile libftprintf.a
#
# 2.1) `make clean' to delete objects locally and in libft
# 2.2) `make lclean' to delete objects locally only (don't touch libft)
#
# 3.1) `make fclean' to delete libftprintf.a, libft.a and objects locally and in libft
# 3.2) `make lfclean' to delete libftprintf.a and objects locally (don't touch libft)
#
# 4.1) `make re' to run `make fclean' and `make all'
# 4.2) `make lre' to run `make lfclean' and `make all'
#
# TO USE DEBUG
#              add `DEBUG=-g' before rule like this: `make DEBUG=-g re'
# OR USE RULE
#              run `make debug' which runs `make DEBUG=-g re'

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
DEBUG = ""

LIB_FT = libft/
LIB_FT_FILE = $(LIB_FT)/libft.a
INCLUDES = -I includes/ -I libft/includes

O_DIR = objects/
SRC_DIR = src/
MAIN_DIR = src/main

SRC_FILES = $(shell find $(SRC_DIR) -not \( -path $(MAIN_DIR) -prune \) -type f -name "*.c")
O_FILES = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
O_DIRS = $(patsubst $(SRC_DIR)%, $(O_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(O_DIRS) $(O_FILES)
	@ranlib $(NAME)
	@echo $(SRC_FILES)

$(LIB_FT_FILE):
	@make DEBUG=$(DEBUG) -C $(LIB_FT)
	@libtool -static -o $(NAME) $(LIB_FT_FILE)

$(O_DIRS):
	@mkdir -vp $(O_DIRS)

$(O_DIR)%.o: $(SRC_DIR)%.c
	clang -c $(FLAGS) $(DEBUG) $(INCLUDES) -o $@ $<
	@ar rc $(NAME) $@

exe:
	@clang $(FLAGS) $(DEBUG) $(MAIN_DIR)/main.c $(INCLUDES) $(NAME) -o grind_me.exe

run: exe
	@echo ".................................................."
	@echo ".....       starting     grind.exe           ....."
	@echo "..................................................\n"
	@./grind_me.exe

grind: exe
	@echo ".................................................."
	@echo ".....       grinding     grind.exe           ....."
	@echo "..................................................\n"
	@valgrind --track-origins=yes --show-leak-kinds=all --leak-check=full ./grind_me.exe

clean:
	@make clean -C $(LIB_FT)
	@rm -rf $(O_DIR)
	@echo "make: Done clean of \`$(NAME)'."

fclean: lclean
	@make fclean -C $(LIB_FT)
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."

lclean:
	@rm -rf $(O_DIR)
	@echo "make: Done local clean of \`$(NAME)'."

lfclean: lclean
	@rm -f $(NAME)
	@echo "make: Done local full clean of \`$(NAME)'."

lre: lfclean all
	@echo "make: Done local recompile of \`$(NAME)'."
