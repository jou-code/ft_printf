
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all : $(NAME)

.c.o :
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
