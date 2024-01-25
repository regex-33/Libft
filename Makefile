NAME = libft.a

CC = cc
SDIR = ./
CFLAGS = -Wall -Wextra -Werror
FILES = ./ft_atoi.c ./ft_memmove.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c ./ft_strdup.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c
FILES_O = $(FILES:%.c=%.o)
BONUS_FILES = ./ft_lstmap_bonus.c ./ft_lstiter_bonus.c ./ft_lstclear_bonus.c ./ft_lstdelone_bonus.c ./ft_lstadd_back_bonus.c ./ft_lstlast_bonus.c ./ft_lstsize_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstnew_bonus.c
BONUS_O = $(BONUS_FILES:%.c=%.o)
all: $(NAME)

$(NAME): $(FILES_O)
	ar -rc $(NAME) $(FILES_O)

bonus: $(BONUS_O) $(FILES_O)
	ar -rc $(NAME) $?

.c.o: $(BONUS_O) $(FILES_O)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean:
	-rm -f $(FILES_O) $(BONUS_O)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
