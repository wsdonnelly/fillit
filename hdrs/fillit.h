/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:28:21 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/25 14:33:23 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFF_SIZE 21

typedef struct s_tetri
{
	char			rule[4];
	int				count;
	struct s_tetri	*next;
}				t_tetri;

typedef struct s_queue
{
	struct s_tetri	*head;
	struct s_tetri	*tail;
}				t_queue;

//readin 
t_tetri	*readin(char *file, t_queue *queue, int *valid_count);
int		validate(char buf[BUFF_SIZE], t_queue *queue, int *valid_count);
int		check_connections(char buf[BUFF_SIZE], int i);
//queue
int		add_to_queue(char buf[BUFF_SIZE], t_queue *queue, int *valid_count);
void	get_rule(char buf[BUFF_SIZE], t_tetri *temp);
//util
void	free_list(t_tetri *head);
char	*new_grid(int size);
void	print_grid(char *grid, int size);
int		get_size(int valid_count);

//solve
void	solve(int count, t_tetri *head);
int		place_on_grid(char *grid, t_tetri *temp, int size);
int		add_tetri(t_tetri *temp, int i, char *grid, int size);
void	draw_tetri(t_tetri *temp, char *grid, int size, int i);
void	delete_tetri(t_tetri *temp, char *grid, int size, int i);

#endif
