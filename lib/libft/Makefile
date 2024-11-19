CFLAGS  = -Wall -Wextra -Werror
NAME    = libft.a
AR		= ar -rcs
SRC =  src/ft_isascii.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isdigit.c src/ft_isprint.c src/ft_bzero.c src/ft_calloc.c src/ft_memcpy.c src/ft_memchr.c src/ft_memcmp.c src/ft_memmove.c src/ft_memset.c src/ft_atoi.c src/ft_itoa.c src/ft_split.c src/ft_substr.c src/ft_strlcat.c src/ft_strchr.c src/ft_strrchr.c src/ft_strncmp.c \
		src/ft_strlcpy.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c src/ft_strlen.c src/ft_strmapi.c src/ft_tolower.c src/ft_toupper.c src/ft_strnstr.c src/ft_strtrim.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_lstadd_back.c src/ft_lstadd_front.c src/ft_lstclear.c src/ft_lstdelone.c src/ft_lstiter.c src/ft_lstlast.c \
		src/ft_lstmap.c src/ft_lstnew.c src/ft_lstsize.c src/get_next_line.c src/get_next_line_utils.c src/ft_printf.c src/ft_printf_putchar.c src/ft_printf_putstr.c \
		src/ft_printf_putunsigned.c src/ft_printf_countnbr.c src/ft_printf_countnbr_unsigned.c src/ft_printf_conversion.c src/ft_printf_putaddress.c src/ft_printf_putnbr.c src/ft_printf_hex.c \

OBJ		= ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -I inc -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re