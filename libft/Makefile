NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes/

O_DIR = objects/
SRC_DIR = src/

SRC_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')
O_FILES = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
O_DIRS = $(patsubst $(SRC_DIR)%, $(O_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)
	@echo "make: Done building \`$(NAME)'."

$(NAME): $(O_DIRS) $(O_FILES)
	@ranlib $(NAME)

$(O_DIRS):
	@mkdir -vp $(O_DIRS)

$(O_DIR)%.o: $(SRC_DIR)%.c
	@clang -c $(FLAGS) $(INCLUDES) -o $@ $<
	@ar rc $(NAME) $@

clean:
	@rm -rf $(O_DIR)
	@echo "make: Done clean of \`$(NAME)'."

fclean: clean
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."