/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:16:45 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/31 12:28:11 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(int count, t_tetri *head)
{
	int		size;
	char	*grid;
	char	*grid_cpy;

	size = get_size(count);
	grid = new_grid(size);
	if (!grid)
		return ;
	get_info(head, size);
	while (!place_on_grid(grid, head, size))
	{
		size++;
		get_info(head, size);
		grid_cpy = grid;
		grid = new_grid(size);
		free (grid_cpy);
	}
	print_grid(grid, size);
	free (grid);
}

int	place_on_grid(char *grid, t_tetri *temp, int size)
{
	int	i;

	if (temp == NULL)
		return (1);
	i = -temp->left;
	while (i < (size * size) - temp->stop)
	{
		if (grid[i] == '.' && i % size >= -temp->left \
		&& i % size < size - temp->right)
		{
			if (add_tetri(temp, i, grid))
			{
				if (place_on_grid(grid, temp->next, size))
					return (1);
				draw_delete_tetri(0, grid, temp, i);
			}
		}
		i++;
	}
	return (0);
}

int	add_tetri(t_tetri *temp, int i, char *grid)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if (grid[temp->shape[j] + i] == '.')
			j++;
		else
			return (0);
	}
	draw_delete_tetri(1, grid, temp, i);
	return (1);
}

void	draw_delete_tetri(int flag, char *grid, t_tetri *temp, int i)
{
	int		j;
	char	c;

	j = 0;
	c = (char)('A' - 1 + temp->count);
	if (flag)
		grid[i] = c;
	else
		grid[i] = '.';
	while (j < 3)
	{
		if (flag)
			grid[temp->shape[j] + i] = c;
		else
			grid[temp->shape[j] + i] = '.';
		j++;
	}
}

				/*
				t_tetri *temp = head;
				while (temp)
				{
					printf("rule:\t");
					for (int i = 0; i < 3; i++)
						printf("%c ", temp->rule[i]);
					printf("\n");
					printf("shape:\t");
					for (int i = 0; i < 3; i++)
						printf("%d ", temp->shape[i]);
					printf("\n");
					printf("left:\t%d\n", temp->left);
					printf("right:\t%d\n", temp->right);
					printf("stop:\t%d\n", temp->stop);
					temp = temp->next;
				}
				*/