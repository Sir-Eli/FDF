NAME = fdf
FLAGS = -Wall -Wextra
INC = libft/libft.a 


all:
	gcc main.c read_file.c draw.c utils.c key_actions.c gnl/get_next_line.c $(INC) $(FLAGS) \
	-I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGl -framework AppKit -g -o \
	$(NAME) -fsanitize=address
fclean:
	rm -f $(NAME)
exec:
	./fdf ./test_maps/42.fdf
re:
	fclean all
	
.PHONY: all clean fclean re


#gcc main.c read_file.c draw.c utils.c gnl/get_next_line.c $(INC) $(FLAGS) \
	-I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGl -framework AppKit -g -o \
	$(NAME) -fsanitize=address
#gcc main.c read_file.c draw.c utils.c gnl/get_next_line.c $(INC) $(FLAGS) \
	libmlx_Linux.a -lm -lX11 -lXext -g -o $(NAME)