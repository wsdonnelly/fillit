#include "fillit.h"
#include <time.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_queue	queue;
	int		count;
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
	queue.head = readin(av[1], &queue, &count);
	if (!queue.head)
		return (0);
	solve(count, queue.head);
	free_list(queue.head);
	stop = time(NULL);
	//printf("Total time:\t%ld\n", stop - start);
	return (0);
}
