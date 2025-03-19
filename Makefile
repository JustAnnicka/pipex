
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

NAME = pipex
SRC_DIR = src
SRC = main.c utils.c pipes.c
SRC_B = main_bonus.c utils.c pipes.c utils_bonus.c
BUILD_DIR = build
INCLUDE_DIR = includes
INCLUDES = -I./$(INCLUDE_DIR)
LIB_DIR = lib
LIBS = -L./$(LIB_DIR)
LIBFT = lib/libft/libft.a


# Do not change these
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
SRC_B_FILES = $(addprefix $(SRC_DIR)/, $(SRC_B))
OBJ_DIR = $(BUILD_DIR)/obj
OBJ = $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ))
OBJ_B = $(SRC_B:.c=.o)
OBJ_B_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ_B))

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)

-include $(OBJ_FILES:.o=.d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\033[0;32mCompiling $<\033[0m"
	@mkdir -p $(basename $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_FILES) 
	@echo "\033[0;34mCreating $@\033[0m"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) $(INCLUDES) -o $(NAME) $(LIBFT)
	@echo "\033[0;33mFinished building $@\033[0m"

$(LIBFT):
	@make -C lib/libft/

bonus: $(LIBFT) $(OBJ_B_FILES)
	@echo "\033[0;34mCreating $@\033[0m"
	@$(CC) $(CFLAGS) $(OBJ_B_FILES) $(LIBS) $(INCLUDES) -o $(NAME) $(LIBFT)
	@echo "$(COLOUR_GREEN)🔥 🔥 Compliling Everything ✅ ✅$(COLOUR_END)"
clean:
	@echo "\033[0;31mDeleting $(OBJ_DIR)\033[0m"
	@make -C lib/libft/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[0;31mDeleting $(BUILD_DIR)\033[0m"
	@make -C lib/libft/ fclean
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
