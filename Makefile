NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIB_FT = libft/
LIB_FT_FILE = $(LIB_FT)/libft.a
INCLUDES = -I includes/ -I libft/includes

O_DIR = objects/
SRC_DIR = src/

SRC_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')
O_FILES = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
O_DIRS = $(patsubst $(SRC_DIR)%, $(O_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(O_DIRS) $(O_FILES)
	@ranlib $(NAME)

$(LIB_FT_FILE):
	@make -C $(LIB_FT)
	@libtool -static -o $(NAME) $(LIB_FT_FILE)

$(O_DIRS):
	@mkdir -vp $(O_DIRS)

$(O_DIR)%.o: $(SRC_DIR)%.c
	@clang -c $(FLAGS) $(INCLUDES) -o $@ $<
	@ar rc $(NAME) $@

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
