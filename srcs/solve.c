/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:16:45 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/25 18:05:40 by willdonnell      ###   ########.fr       */
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
	int	rl[4];

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

int	add_tetri(t_tetri *temp, int i, char *grid, int size, int rl[4])
{
	int	j;

	j = 0;
	if (grid[i] == '.')
	{
		rl[0] = i;
		while (j < 3)
		{
			if ((temp->rule)[j] == 'd' && (i + size) < (size * size) \
			&& grid[i + size] == '.')
				i += size;
			else if ((temp->rule)[j] == 'r' && (i % size) + 1 < size \
			&& grid[i + 1] == '.')
				i++;
			else if ((temp->rule)[j] == '2' && ((i + size) < (size * size) \
			&& (i % size) - 2 >= 0) && grid[i + size - 2] == '.')
				i += size - 2;
			else if ((temp->rule)[j] == '1' && ((i + size) < (size * size) \
			&& (i % size) - 1 >= 0) && grid[i + size - 1] == '.')
				i += size - 1;
			else
				return (0);
			rl[j + 1] = i;
			j++;
		}
		draw_delete_tetri(1, grid, rl, temp->count);
		return (1);
	}
	return (0);
}

void	draw_delete_tetri(int flag, char *grid, int rl[4], int count)
{
	int		j;
	char	c;

	j = 0;
	c = '@';
	while (j < 4)
	{
		if (flag)
			grid[rl[j]] = (char)(c + count);
		else
			grid[rl[j]] = '.';
		j++;
	}
}
