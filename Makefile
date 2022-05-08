NAME = fdf

FLAGS = -Wall -Wextra -Werror

INC = -I libft/includes -L libft -lft

SRCS = main.c key_actions.c read_file.c draw.c utils.c

FRAME = libmlx_Linux.a -lm -lX11 -lXext 

EXTRA = -g -fsanitize=address

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRCS) $(INC) $(FLAGS) $(FRAME)
clean:
	make clean -C libft/
	rm -f *.o
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
re: fclean all
	
.PHONY: all clean fclean re


#gcc main.c read_file.c draw.c utils.c gnl/get_next_line.c $(INC) $(FLAGS) \
	-I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGl -framework AppKit -g -o \
	$(NAME) -fsanitize=address
#gcc main.c read_file.c draw.c utils.c gnl/get_next_line.c $(INC) $(FLAGS) \
	libmlx_Linux.a -lm -lX11 -lXext -g -o $(NAME)#-fsanitize=address