/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:16:45 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/27 14:46:06 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	solve(int count, t_tetri *head)
{
	int		size;
	char	*grid;
	char	*grid_cpy;

	size = get_size(count);
	grid = new_grid(size);
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
	i = temp->start;
	while (i < (size * size) - temp->stop)
	{
		if (grid[i] == '.' && i % size >= temp->start && i % size < size - temp->right)
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

void get_info(t_tetri *head, int size)
{
	t_tetri *temp;

	temp = head;
	while (temp)
	{
		get_ssr(temp, size);
		get_shape(temp, size);
		temp = temp->next;
	}
}

void	get_ssr(t_tetri *temp, int size)
{
	int	i;

	i = 0;
	temp->start = 0;
	temp->stop = 0;
	temp->right = 0;
	while (i < 3)
	{
		if (temp->rule[i] == 'd')
			temp->stop += size;
		else if (temp->rule[i] == 'r')
		{
			temp->stop++;
			temp->right++;
		}
		else if (temp->rule[i] == '2') 
		{ 
			if (i == 0)
				temp->start += 2;
			else if (i == 1)
			{
				temp->start += 1;
				temp->stop += 3;
			}
			temp->stop += size - 2;
			temp->right -= 2;
		}
		else if (temp->rule[i] == '1')
		{ 
			if (i == 0 || (i == 1 && temp->rule[0] == 'd'))
				temp->start++;
			temp->stop += size - 1;
			temp->right--;
		}
		i++;
	}
}

void get_shape(t_tetri *temp, int size)
{
	int i;
	int j;

	i = j = 0;
	while (i < 3)
	{
		if (temp->rule[i] == 'd')
			j += size;
		else if (temp->rule[i] == 'r')
			j++;
		else if (temp->rule[i] == '2')
			j += size -	2;
		else if (temp->rule[i] == '1')
			j += size -	1;
		temp->shape[i] = j;
		i++;
	}
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
