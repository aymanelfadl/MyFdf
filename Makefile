CC = gcc
CFLAGS = -Wall -Wextra -Werror -no-pie

NAME = fdf

LIBFTDIR = libft
GETNEXTLINEDIR = getNextLine
MINILIBXDIR = minilibx-linux

SRCS = main.c draw_line.c garbage_collector.c get_points.c map_boundaries.c \
        events.c map_scale.c mlx_init.c parallel.c process_map.c rotation.c \
        img_zoom.c ft_atoi_base.c set_color.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft get_next_line minilibx
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -L$(GETNEXTLINEDIR) -lgnl -L$(MINILIBXDIR) -lmlx -lXext -lX11 -lm -o $(NAME)
    
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFTDIR)

get_next_line:
	$(MAKE) -C $(GETNEXTLINEDIR)

minilibx:
	$(MAKE) -C $(MINILIBXDIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(GETNEXTLINEDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GETNEXTLINEDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft get_next_line minilibx