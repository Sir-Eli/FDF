NAME = fdf
FLAGS = -Wall -Wextra
INC = libft/libft.a \
	gnl/get_next_line.c \


all:
	gcc main.c read_file.c draw.c $(INC) -o $(NAME) $(FLAGS) \
	-L /usr/local/lib -lmlx -framework OpenGl -framework AppKit -g
fclean:
	rm -f $(NAME)
exec:
	./fdf ./test_maps/42.fdf
re:
	fclean all
	
.PHONY: all clean fclean re

#gcc main.c libft/libft.a create_map.c gnl/get_next_line.c
#-I /usr/local/include -L /usr/local/lib \
#-l mlx -l ft -framework OpenGL -framework Appkit
#-Werror