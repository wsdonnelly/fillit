/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:06:04 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/28 17:20:14 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	add_to_queue(char buf[BUFF_SIZE], t_queue *queue, int *count)
{
	t_tetri	*temp;

	temp = (t_tetri *)malloc(sizeof(t_tetri));
	if (!temp)
		return (0);
	get_rule(buf, temp);
	get_lr(temp);
	temp->count = *count;
	temp->next = NULL;
	if (queue->tail == NULL)
	{
		queue->tail = temp;
		queue->head = temp;
	}
	else
	{
		(queue->tail)->next = temp;
		queue->tail = temp;
	}
	return (1);
}

void	get_rule(char buf[BUFF_SIZE], t_tetri *temp)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + 1;
	while (buf[j])
	{
		if (buf[j] == '#')
		{
			if ((j - i) % 5 == 0)
				ft_strcat(temp->rule, "d");
			else if ((j - i) % 5 == 1)
				ft_strcat(temp->rule, "r");
			else if ((j - i) % 5 == 3)
				ft_strcat(temp->rule, "2");
			else if ((j - i) % 5 == 4)
				ft_strcat(temp->rule, "1");
			i = j;
		}
		j++;
	}
}

void	get_lr(t_tetri *temp)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < 3)
	{
		if (temp->rule[i] == 'r')
		{
			if (++x > temp->right)
				temp->right++;
		}
		else if (temp->rule[i] == '2')
		{
			x -= 2;
			if (x < temp->left)
				temp->left = x;
		}
		else if (temp->rule[i] == '1')
		{
			if (--x < temp->left)
				temp->left = x;
		}
		i++;
	}
}

void	get_stop(t_tetri *temp, int size)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	temp->stop = 0;
	while (i < 3)
	{
		if (temp->rule[i] == 'd')
			temp->stop += size;
		else if (temp->rule[i] == '2')
			temp->stop += size;
		else if (temp->rule[i] == '1')
			temp->stop += size;
		i++;
	}
	temp->stop += temp->right;
}

void	get_shape(t_tetri *temp, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		if (temp->rule[i] == 'd')
			j += size;
		else if (temp->rule[i] == 'r')
			j++;
		else if (temp->rule[i] == '2')
			j += size - 2;
		else if (temp->rule[i] == '1')
			j += size - 1;
		temp->shape[i] = j;
		i++;
	}
}
