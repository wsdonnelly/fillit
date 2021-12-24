#include "fillit.h"

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*tail;
	t_list *temp;
	int		valid_count;
	char *grid;
	char *grid_cpy;
	int	size;

	if (ac != 2)
	{
		//ERROR DISPLAY USAGE
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
	//printf("start size:\t%d\n", size);
	temp = head;
	/*
	while (temp)
	{
		printf("temp->rule %s\n", temp->rule);
		temp = temp->next;
	}
	*/
	//temp = head;
	while (!place_on_grid(grid, head, size))
	{
		size++;
		grid_cpy = grid;
		grid = new_grid(size);
		free (grid_cpy);
	}
	print_grid(grid, size);
	free (grid);
	//FREE ENTIRE LIST
	free_list(&head);
	return (0);
}
