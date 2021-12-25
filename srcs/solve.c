/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:16:45 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/25 14:22:43 by willdonnell      ###   ########.fr       */
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
	while (!place_on_grid(grid, head, size))
	{
		size++;
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
	i = 0;
	while (i < (size * size) - 3)
	{
		if (add_tetri(temp, i, grid, size))
		{
			if (place_on_grid(grid, temp->next, size))
				return (1);
			delete_tetri(temp, grid, size, i);
		}
		i++;
	}
	return (0);
}

void	delete_tetri(t_tetri *temp, char *grid, int size, int i)
{
	int	j;
	int	k;

	grid[i] = '.';
	j = 0;
	k = i;
	while (j < 3)
	{
		if ((temp->rule)[j] == 'd')
		{
			k += size;
			grid[k] = '.';
		}
		else if ((temp->rule)[j] == 'r')
		{
			k++;
			grid[k] = '.';
		}
		else if ((temp->rule)[j] == '2')
		{
			k += size - 2;
			grid[k] = '.';
		}
		else if ((temp->rule)[j] == '1')
		{
			k += size - 1;
			grid[k] = '.';
		}
		j++;
	}
}

int	add_tetri(t_tetri *temp, int i, char *grid, int size)
{
	int	j;
	int	k;

	j = 0;
	if (grid[i] == '.')
	{
		k = i;
		while (j < 3)
		{
			if ((temp->rule)[j] == 'd' && (k + size) < (size * size) \
			&& grid[k + size] == '.')
				k += size;
			else if ((temp->rule)[j] == 'r' && (k % size) + 1 < size \
			&& grid[k + 1] == '.')
				k++;
			else if ((temp->rule)[j] == '2' && ((k + size) < (size * size) \
			&& (k % size) - 2 >= 0) && grid[k + size - 2] == '.')
				k += size - 2;
			else if ((temp->rule)[j] == '1' && ((k + size) < (size * size) \
			&& (k % size) - 1 >= 0) && grid[k + size - 1] == '.')
				k += size - 1;
			else
				return (0);
			j++;
		}
		draw_tetri(temp, grid, size, i);
		return (1);
	}
	return (0);
}

void	draw_tetri(t_tetri *temp, char *grid, int size, int i)
{
	int		j;
	char	c;

	c = '@';
	j = 0;
	grid[i] = (char)(c + temp->count);
	while (j < 3)
	{
		if ((temp->rule)[j] == 'd')
		{
			grid[i + size] = (char)(c + temp->count);
			i += size;
		}
		else if ((temp->rule)[j] == 'r')
		{
			grid[i + 1] = (char)(c + temp->count);
			i++;
		}
		else if ((temp->rule)[j] == '2')
		{
			grid[i + size - 2] = (char)(c + temp->count);
			i += size - 2;
		}
		else if ((temp->rule)[j] == '1')
		{
			grid[i + size - 1] = (char)(c + temp->count);
			i += size - 1;
		}
		j++;
	}
}
