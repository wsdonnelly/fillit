/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:06:04 by willdonnell       #+#    #+#             */
/*   Updated: 2021/12/25 14:38:33 by willdonnell      ###   ########.fr       */
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
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			j = i;
			while (buf[j])
			{
				j++;
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
			}
			break ;
		}
		i++;
	}
}
