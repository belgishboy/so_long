SOURCES	= so_long.c check_map.c

OBJECTS	= $(SOURCES:.c=.o)
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
INCLUDES = ./

NAME	= so_long.a
LIBFTM	= libft
LIBFT	= ${LIBFTM}/libft.a

all:	$(NAME)

$(NAME): $(SOURCES)
	$(MAKE) $(LIBFT)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	gcc $(FLAGS) $(LIBFT) so_long.c so_long.a -o so_long
	$(MAKE) clean

$(LIBFT) :
	cd $(LIBFTM) && $(MAKE)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFTM) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
