
CC = gcc
CFLAGS = -Wall -Wextra -Werror -DM

NAME = pipex
SRC_DIR = src
SRC = main.c 
BUILD_DIR = build
INCLUDE_DIR = includes
INCLUDES = -I./$(INCLUDE_DIR)
LIB_DIR = lib
LIBS = -L./$(LIB_DIR)
LIBFT = lib/libft/libft.a


# Do not change these
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR = $(BUILD_DIR)/obj
OBJ = $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJ))


all: $(NAME)

-include $(OBJ_FILES:.o=.d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\033[0;32mCompiling $<\033[0m"
	@mkdir -p $(basename $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_FILES) 
	@echo "\033[0;34mLinking $@\033[0m"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) $(INCLUDES) -o $(BUILD_DIR)/$(NAME) $(LIBFT)
	@echo "\033[0;33mFinished building $@\033[0m"

$(LIBFT):
	@make -C lib/libft/

clean:
	@echo "\033[0;31mDeleting $(OBJ_DIR)\033[0m"
	@make -C lib/libft/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[0;31mDeleting $(BUILD_DIR)\033[0m"
	@make -C lib/libft/ fclean
	@rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
