/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:01:24 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/29 13:10:31 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_queue	queue;
	int		count;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file.fillit\n");
		return (0);
	}
	queue.head = NULL;
	queue.tail = NULL;
	count = 0;
	fd = open(av[1], O_RDONLY);
	queue.head = readin(&queue, &count, fd);
	if (!queue.head)
	{
		ft_putstr("error\n");
		return (0);
	}
	solve(count, queue.head);
	free_list(queue.head);
	return (0);
}
