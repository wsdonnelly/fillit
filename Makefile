NAME = fillit
CC = gcc
#DEBUG = -g
FLAGS = -Wall -Wextra -Werror
MORE_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
SRCS = srcs/main.c srcs/readin.c srcs/util.c srcs/solve.c srcs/queue.c
#SRCS = srcs/test_main.c srcs/readin.c srcs/util.c srcs/solve.c srcs/queue.c
#OBJS = $(SRCS:.c=.o)
OBJS = main.o readin.o util.o solve.o queue.o
#OBJS = test_main.o readin.o util.o solve.o queue.o
HDRS = hdrs/
LIB = libft/
#LIBFT = make -C libft/ fclean && make -C libft/

all:
#	$(MAKE) -C $(LIB)
	$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) $(MORE_FLAGS) -c $(SRCS) -I $(HDRS)


clean:
	rm -f $(OBJS)
#	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
#	$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re