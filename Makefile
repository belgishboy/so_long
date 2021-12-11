NAME = so_long

SRC =	so_long.c	\
		check_map.c	\
		draw_map.c	\
		play.c		\

CC = gcc

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	$(CC) $(OBJ) mlx/libmlx.a libft/libft.a -L /usr/X11/lib -lXext -lX11 -g -o $(NAME)
	$(MAKE) clean

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f so_long
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
