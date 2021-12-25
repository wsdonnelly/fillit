#include "fillit.h"

void	free_list(t_tetri *head)
{
	t_tetri	*cur;
	t_tetri	*next;

	cur = head;
	while (cur)
	{
		next = cur->next;
		free (cur);
		cur = next;
	}
}

int	get_size(int valid_count)
{
	int size;

	size = 2;
	while (size * size < valid_count * 4)
		size++;
	return (size);
}

char	*new_grid(int size)
{
	char	*grid;
	int		i;

	grid = ft_strnew((size_t)(size * size));
	i = 0;
	while (i < (size * size))
		grid[i++] = '.';
	return (grid);
}

void print_grid(char *grid, int size)
{
	int i;
	i = 0;

	while (grid[i])
	{
		if (i % size != size - 1)
			write(1, &grid[i], 1);
		else
		{
			write(1, &grid[i], 1);
			write(1, "\n", 1);
		}
		i++;
	}
}
