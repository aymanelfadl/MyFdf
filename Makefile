CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

HEADER = fdf.h

LIBFTDIR = libft
GETNEXTLINEDIR = getNextLine
MINILIBXDIR = minilibx-linux

SRCS = main.c draw_line.c garbage_collector.c get_points.c map_boundaries.c \
        events.c map_scale.c mlx_init.c parallel.c process_map.c rotation.c \
        img_zoom.c ft_atoi_base.c set_color.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
GNL = $(GETNEXTLINEDIR)/libgnl.a
MLX = $(MINILIBXDIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX) 
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -L$(GETNEXTLINEDIR) -lgnl -L$(MINILIBXDIR) -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(GNL):
	$(MAKE) -C $(GETNEXTLINEDIR)

$(MLX):
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

.PHONY: all clean fclean re