CC = gcc
CFLAGS = -Wall -Wextra -Werror -no-pie

TARGET = fdf

LIBFTDIR = libft
GETNEXTLINEDIR = getNextLine
MINILIBXDIR = minilibx-linux

SRCS = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): libft get_next_line minilibx $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -L$(LIBFTDIR) -lft -L$(GETNEXTLINEDIR) -lgnl -L$(MINILIBXDIR) -lmlx -lXext -lX11 -lm -o $@

libft:
	$(MAKE) -C $(LIBFTDIR)

get_next_line:
	$(MAKE) -C $(GETNEXTLINEDIR)

minilibx:
	$(MAKE) -C $(MINILIBXDIR)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(GETNEXTLINEDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GETNEXTLINEDIR) fclean
	$(MAKE) -C $(MINILIBXDIR) fclean

re: fclean all

.PHONY: libft get_next_line minilibx

.SECONDARY: