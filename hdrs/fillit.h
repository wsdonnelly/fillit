#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

#include <stdio.h>

# define BUFF_SIZE 21

typedef struct s_list
{
	char				tetri[16];
	struct s_list		*next;
}				t_list;

t_list *readin(char *file, t_list **head);
int	validate(char buf[BUFF_SIZE], t_list **head);
int check_connections(char buf[BUFF_SIZE], int i);
int add_to_list(char buf[BUFF_SIZE], t_list **head);

void solve(t_list *list);

#endif
