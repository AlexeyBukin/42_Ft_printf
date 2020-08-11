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

CC = gcc
FLAGS = #-Wall -Wextra -Werror
DEBUG = -g

LIB_FT = libft/
LIB_FT_FILE = $(LIB_FT)/libft.a
INCLUDES = -I includes/ -I libft/includes

O_DIR = objects/
SRC_DIR = src/
MAIN_DIR = src/main

SRC_FILES = \
src/flags/float/ft_strf_flag_f.c  src/flags/float/ft_strf_flag_f_special.c  src/flags/float/ft_strf_flag_f_str.c  \
src/flags/ft_strf_flag_c.c        src/flags/ft_strf_flag_cast.c             src/flags/ft_strf_flag_di.c           \
src/flags/ft_strf_flag_o.c        src/flags/ft_strf_flag_p.c                src/flags/ft_strf_flag_perc.c         \
src/flags/ft_strf_flag_s.c        src/flags/ft_strf_flag_u.c                src/flags/ft_strf_flag_unknown.c      \
src/flags/ft_strf_flag_x.c        src/flags/float/ft_strf_flag_f_fast.c     src/flags/float/ft_strf_flag_f_round.c\
src/ft_printf/ft_printf.c         src/ft_printf/ft_printf_resolve.c         src/ft_strf/ft_strf.c                 \
src/ft_strf/ft_strf_adjust.c      src/ft_strf/ft_strf_adjust_dioux.c        src/ft_strf/ft_strf_adjust_psc.c      \
src/ft_strf/ft_strf_format.c      src/ft_strf/ft_strf_parse.c               src/ft_strf/ft_strf_parse_utils.c     \
src/ft_strf/ft_strf_resolve.c

O_FILES = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
O_DIRS = $(patsubst $(SRC_DIR)%, $(O_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(O_DIRS) $(O_FILES)
	@ranlib $(NAME)
	@libtool -static -o $(NAME) $(NAME) $(LIB_FT_FILE)
	@echo $(SRC_FILES)

$(LIB_FT_FILE):
	@make DEBUG=$(DEBUG) -C $(LIB_FT)
	@libtool -static -o $(NAME) $(LIB_FT_FILE)

$(O_DIRS):
	@mkdir -vp $(O_DIRS)

$(O_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(FLAGS) $(DEBUG) $(INCLUDES) -o $@ $<
	@ar rc $(NAME) $@

exe: all
	@$(CC) $(FLAGS) $(DEBUG) $(MAIN_DIR)/main.c $(INCLUDES) $(NAME) -o grind_me.exe

run: exe
	@echo ".................................................."
	@echo ".....       starting     grind.exe           ....."
	@echo "..................................................\n"
	@./grind_me.exe

grind: exe
	@echo ".................................................."
	@echo ".....       grinding     grind.exe           ....."
	@echo "..................................................\n"
	@valgrind --track-origins=yes --leak-check=full ./grind_me.exe

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
