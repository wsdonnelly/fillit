#include "fillit.h"
#include <time.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_queue	queue;
	int		count;
	int		fd;
	time_t start;
	time_t stop;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file.fillit\n");
		return (0);
	}
	queue.head = NULL;
	queue.tail = NULL;
	count = 0;
	start = time(NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	queue.head = readin(&queue, &count, fd);
	if (!queue.head)
	{
		ft_putstr("error\n");
		return (0);
	}
	solve(count, queue.head);
	free_list(queue.head);
	stop = time(NULL);
	//printf("Total time:\t%ld\n", stop - start);
	return (0);
}
