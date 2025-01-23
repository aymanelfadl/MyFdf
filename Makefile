CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = fdf

LIBFTDIR = libft
GETNEXTLINEDIR = getNextLine
SRCDIRS = parsing_map mini-garbage-collector

SRCS = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): libft get_next_line $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -L$(LIBFTDIR) -lft -L$(GETNEXTLINEDIR) -lgnl  -o $@ 

libft:
	$(MAKE) -C $(LIBFTDIR)

get_next_line:
	$(MAKE) -C $(GETNEXTLINEDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(GETNEXTLINEDIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GETNEXTLINEDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft get_next_line