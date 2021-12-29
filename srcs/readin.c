/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:01:52 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/29 13:09:22 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*readin(t_queue *queue, int *count, int fd)
{
	ssize_t	ret;
	ssize_t	ret_cpy;
	char	buf[BUFF_SIZE + 1];

	if (fd == -1)
		return (0);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		ret_cpy = ret;
		if (ret == -1 || ret < 19)
			return (0);
		buf[ret] = '\0';
		if (!validate(buf, queue, count))
			return (0);
		ret = read(fd, buf, BUFF_SIZE);
		if ((ret_cpy == 21 && ret == 0))
			return (0);
	}
	close (fd);
	return (queue->head);
}

int	validate(char buf[BUFF_SIZE], t_queue *queue, int *count)
{
	int	i;
	int	hash_count;
	int	connections;

	i = 0;
	hash_count = 0;
	connections = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && buf[i] != '.' && buf[i] != '#')
			return (0);
		else if (i % 5 == 4 && buf[i] != '\n' && buf[i] != '\0')
			return (0);
		if (buf[i] == '#' && ++hash_count < 5)
			connections += check_connections(buf, i);
		i++;
	}
	if (connections > 5 && hash_count == 4)
	{
		(*count)++;
		if (!add_to_queue(buf, queue, count))
			return (0);
		return (1);
	}
	return (0);
}

int	check_connections(char buf[BUFF_SIZE], int i)
{
	int	c;

	c = 0;
	if (i - 5 >= 0)
	{
		if (buf[i - 5] == '#')
			c++;
	}
	if (i + 1 <= 18)
	{
		if (buf[i + 1] == '#')
			c++;
	}
	if (i + 5 <= 18)
	{
		if (buf[i + 5] == '#')
			c++;
	}
	if (i - 1 >= 0)
	{
		if (buf[i - 1] == '#')
			c++;
	}
	return (c);
}
