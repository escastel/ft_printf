NAME = libftprintf.a

FILES = ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_count_nb.c \
ft_putnbr.c \
ft_putunsignbr.c \
ft_puthexa.c \
ft_putptr.c



OBJECTS = $(FILES:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(OBJECTS): $(FILES)
	gcc $(FLAGS) -c $(FILES)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(OBJECTS)

re: fclean all

PHONY : all clean fclean re