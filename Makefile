NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c readin.c util.c solve.c queue.c
OBJS = main.o readin.o util.o solve.o queue.o
HDRS = fillit.h
LIB = libft/

all:
	$(MAKE) -C $(LIB)
	$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS) -I $(HDRS)


clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re