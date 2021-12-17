#include "fillit.h"

int	main(int ac, char **av)
{
	t_list *head;

	if (ac != 2)
	{
		//ERROR
		ft_putstr("argument error\n");
		return (0);
	}
	head = NULL;
	head = readin(av[1], &head);
	if (!head)
		//ERROR INVALID LIST
		return (0);
	
	//solve(list);

	//FREE ENTIRE LIST
	free (head);
	return (0);
}
