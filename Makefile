NAME = fdf

CC = cc
# CFLAGS = -Wall -Wextra -Werror

SRC = main2.c  parsing_map.c parsing_map_util.c \
		parsing_map_util2.c parsing_map_util3.c


OBJ = $(SRC:.c=.o)


INCLUDE = -I libft/libft.h


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all