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
	char			rule[4];
	int				count;
	struct s_list	*next;
}				t_list;

//read in functions
t_list	*readin(char *file, t_list **head, t_list **tail,int *valid_count);
int		validate(char buf[BUFF_SIZE], t_list **head, t_list **tail, int *valid_count);
int		check_connections(char buf[BUFF_SIZE], int i);
int	add_to_list(char buf[BUFF_SIZE], t_list **head, t_list **tail, int *valid_count);
//solve functions
void	solve(t_list *list);
//util
void	free_list(t_list **head);
//grid
char	*new_grid(int size);
void	print_grid(char *grid, int size);
int get_size(int valid_count);

//void place_on_grid(char *grid, t_list **head, int size);
int	place_on_grid(char *grid, t_list *temp, int size); //recursive
int	add_tetri(t_list *temp, int i, char *grid, int size);
void	draw_tetri(t_list *temp, char *grid, int size, int i);
void	delete_tetri(t_list *temp, char *grid, int size, int i);

#endif
