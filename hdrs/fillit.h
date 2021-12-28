/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:28:21 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/28 17:20:13 by willdonnell      ###   ########.fr       */
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
	int				left;
	int				right;
	int				stop;
	int				shape[3];
	struct s_tetri	*next;
}				t_tetri;

typedef struct s_queue
{
	struct s_tetri	*head;
	struct s_tetri	*tail;
}				t_queue;

//readin 
t_tetri	*readin(t_queue *queue, int *valid_count, int fd);
int		validate(char buf[BUFF_SIZE], t_queue *queue, int *valid_count);
int		check_connections(char buf[BUFF_SIZE], int i);

//queue
int		add_to_queue(char buf[BUFF_SIZE], t_queue *queue, int *valid_count);
void	get_rule(char buf[BUFF_SIZE], t_tetri *temp);
void	get_lr(t_tetri *temp);
void	get_stop(t_tetri *temp, int size);
void	get_shape(t_tetri *temp, int size);

//util
void	free_list(t_tetri *head);
char	*new_grid(int size);
void	print_grid(char *grid, int size);
int		get_size(int valid_count);
void	get_info(t_tetri *head, int size);

//solve
void	solve(int count, t_tetri *head);
int		place_on_grid(char *grid, t_tetri *temp, int size);
int		add_tetri(t_tetri *temp, int i, char *grid);
void	draw_delete_tetri(int flag, char *grid, t_tetri *temp, int i);

#endif
