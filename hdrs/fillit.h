#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

#include <stdio.h>

# define BUFF_SIZE 21

typedef struct s_tetri
{
	char			rule[4];
	int				count;
	struct s_tetri	*next;
}				t_tetri;

typedef struct s_list
{
	struct s_tetri	*head;
	struct s_tetri	*tail;
}				t_list;

//read in functions
t_tetri	*readin(char *file, t_list *list, int *valid_count);
int		validate(char buf[BUFF_SIZE], t_list *list, int *valid_count);
int		check_connections(char buf[BUFF_SIZE], int i);
int		add_to_list(char buf[BUFF_SIZE], t_list *list, int *valid_count);
//util
void	free_list(t_tetri *head);
char	*new_grid(int size);
void	print_grid(char *grid, int size);
int		get_size(int valid_count);

//void place_on_grid(char *grid, t_list **head, int size);
int		place_on_grid(char *grid, t_tetri *temp, int size); //recursive
int		add_tetri(t_tetri *temp, int i, char *grid, int size);
void	draw_tetri(t_tetri *temp, char *grid, int size, int i);
void	delete_tetri(t_tetri *temp, char *grid, int size, int i);

#endif
