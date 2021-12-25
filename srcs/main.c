#include "fillit.h"

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*tail;
	int		valid_count;
	char	*grid;
	char	*grid_cpy;
	int		size;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file.fillit\n");
		return (0);
	}
	head = NULL;
	tail = NULL;
	valid_count = 0;
	head = readin(av[1], &head, &tail, &valid_count);
	if (!head)
		return (0);
	size = get_size(valid_count);
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
	free_list(&head);
	return (0);
}
