NAME = fdf
FLAGS = -Wall -Wextra #-Werror
INC = -I libft -L libft \
	-I gnl \
	-I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

all:
	gcc main.c $(INC) -o $(NAME) $(FLAGS)
	rm *.o
fclean:
	rm -f $(NAME)
re:
	fclean all
	
.PHONY: all clean fclean re
