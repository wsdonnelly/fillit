/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:16:45 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/25 17:03:47 by willdonnell      ###   ########.fr       */
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
	int rl[4];

	if (temp == NULL)
		return (1);
	i = 0;
	while (i < (size * size) - 3)
	{
		if (add_tetri(temp, i, grid, size, rl))
		{
			if (place_on_grid(grid, temp->next, size))
				return (1);
			draw_delete_tetri(0, grid, rl, temp->count);
		}
		i++;
	}
	return (0);
}
/*
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
		draw_delete_tetri(1, temp, grid, size, i);
		return (1);
	}
	return (0);
}
*/
int	add_tetri(t_tetri *temp, int i, char *grid, int size, int rl[4])
{
	int	j;
	int	k;

	j = 0;
	if (grid[i] == '.')
	{
		k = i;
		rl[0] = k;
		while (j < 3)
		{
			if ((temp->rule)[j] == 'd' && (k + size) < (size * size) \
			&& grid[k + size] == '.')
			{
				k += size;
				rl[j + 1] = k;
			}
			else if ((temp->rule)[j] == 'r' && (k % size) + 1 < size \
			&& grid[k + 1] == '.')
			{
				k++;
				rl[j + 1] = k;
			}
			else if ((temp->rule)[j] == '2' && ((k + size) < (size * size) \
			&& (k % size) - 2 >= 0) && grid[k + size - 2] == '.')
			{
				k += size - 2;
				rl[j + 1] = k;
			}
			else if ((temp->rule)[j] == '1' && ((k + size) < (size * size) \
			&& (k % size) - 1 >= 0) && grid[k + size - 1] == '.')
			{
				k += size - 1;
				rl[j + 1] = k;
			}
			else
				return (0);
			j++;
		}
		draw_delete_tetri(1, grid, rl, temp->count);
		return (1);
	}
	return (0);
}

void draw_delete_tetri(int flag, char *grid, int rl[4], int count)
{
	int		j;
	char	c;

	j = 0;
	c = '@';

	while (j < 4)
	{
		if (flag)
			grid[rl[j]] = (char)(c	+ count);
		else
			grid[rl[j]] = '.';
		j++;
	}
}
	/*if (flag)
		grid[i] = (char)(c + temp->count);
	else
		grid[i] = '.';
	while (j < 3)
	{
		if ((temp->rule)[j] == 'd')
		{
			i += size;
			if (flag)
				grid[i] = (char)(c + temp->count);
			else
				grid[i] = '.';
		}
		else if ((temp->rule)[j] == 'r')
		{
			i++;
			if (flag)
				grid[i] = (char)(c + temp->count);
			else
				grid[i] = '.';
		}
		else if ((temp->rule)[j] == '2')
		{
			i += size - 2;
			if (flag)
				grid[i] = (char)(c + temp->count);
			else
				grid[i] = '.';
		}
		else if ((temp->rule)[j] == '1')
		{
			i += size - 1;
			if (flag)
				grid[i] = (char)(c + temp->count);
			else
				grid[i] = '.';
		}
		j++;
	}
	

}
*/
/*
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
*/
