/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:42 by wdonnell          #+#    #+#             */
/*   Updated: 2021/12/14 15:57:01 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	add_new_line(char *temp, int fd, int len, t_list **head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free(temp);
		return (0);
	}
	new->ln = ft_strsub(temp, 0, (size_t)len);
	new->fd = fd;
	new->next = *head;
	if (*head != NULL)
		(new->next)->prev = new;
	new->prev = NULL;
	*head = new;
	return (1);
}

int	find_next_line(t_list **head, char **line, int fd)
{
	t_list	*temp;

	if (*head == NULL)
		return (0);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp != NULL)
	{
		if (temp->fd == fd)
		{
			*line = temp->ln;
			if (temp->next)
				(temp->next)->prev = temp->prev;
			if (temp->prev)
				(temp->prev)->next = temp->next;
			else
				*head = temp->next;
			free(temp);
			return (1);
		}
		temp = temp->prev;
	}
	return (0);
}

int	add_lines_from_temp(char **temp, int fd, t_list **head)
{
	int		len;
	char	*temp2;

	len = 0;
	while ((*temp)[len])
	{
		if ((*temp)[len] == '\n')
		{
			if (!add_new_line(*temp, fd, len, head))
				return (0);
			temp2 = *temp;
			*temp = ft_strsub(temp2, (unsigned int)len + 1, \
			(size_t)((ft_strlen(temp2) - (size_t)(len + 1))));
			if (!temp)
			{
				free (temp2);
				return (0);
			}
			free (temp2);
			len = 0;
			continue ;
		}
		len++;
	}
	return (1);
}

int	read_in(char **temp, int fd, t_list	**head)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	char		*temp2;

	ret = 1;
	while (ret)
	{
		ret = read(fd, &buf, BUFF_SIZE);
		if (ret == -1)
			return (0);
		buf[ret] = '\0';
		temp2 = *temp;
		*temp = ft_strjoin(temp2, buf);
		if (!(*temp))
		{
			free (temp2);
			return (0);
		}
		free (temp2);
		if (!add_lines_from_temp(temp, fd, head))
			return (0);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	char			*temp;

	if (!line || fd < 0 || BUFF_SIZE < 1 || fd > MAX_FD)
		return (-1);
	temp = ft_strnew(1);
	if (!read_in(&temp, fd, &head))
	{
		free(temp);
		return (-1);
	}
	if (ft_strlen(temp) > 0)
	{
		if (!add_new_line(temp, fd, (int)ft_strlen(temp), &head))
			return (-1);
		free(temp);
		return (find_next_line(&head, line, fd));
	}
	else
	{
		free (temp);
		return (find_next_line(&head, line, fd));
	}
}
