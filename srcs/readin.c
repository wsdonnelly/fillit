#include "fillit.h"

t_tetri	*readin(char *file, t_list *list, int *valid_count)
{
	int		fd;
	ssize_t	ret;
	ssize_t	ret_cpy;
	char	buf[BUFF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		//OPEN ERROR
		ft_putstr("error\n");
		return (0);
	}
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 0)
	{
		//INVALID TETRIMINO ERROR
		ft_putstr("error\n");
		return (0);
	}
	while (ret)
	//while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		ret_cpy = ret;
		if (ret == -1)
		{
			// READ ERROR
			ft_putstr("error\n");
			return (0);
		}
		buf[ret] = '\0';
		if ((ret == BUFF_SIZE && buf[20] != '\n') \
		|| (ret == 19 && buf[19] != '\0'))
		{
			//INVALID TETRIMINO ERROR
			ft_putstr("error\n");
			return (0);
		}
		if (!validate(buf, list, valid_count))
		{
			//TETRIMINO ERROR
			ft_putstr("error\n");
			return (0);
		}
		//CATCH FILE ENDING WITH \N???
		//DISPLAY EMPTY ERROR
		ret = read(fd, buf, BUFF_SIZE);
		if (ret_cpy == 21 && ret == 0)
		{
			//TETRIMINO ERROR
			ft_putstr("error\n");
			return (0);
		}
	
	}
	//ft_putstr("valid file!\n");
	close (fd);
	return (*(list->head));
}

int	validate(char buf[BUFF_SIZE], t_list *list, int *valid_count)
{
	int	i;
	int	hash_count;
	int	connections;

	i = 0;
	hash_count = 0;
	connections = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
			{
				//TETRIMINO ERROR
				return (0);
			}
			if (buf[i] == '#')
			{
				connections += check_connections(buf, i);
				//printf("connections = %d\n", connections);
				hash_count++;
			}
		}
		else
		{
			if (buf[i] != '\n' && buf[i] != '\0')
			{
				//TETRIMINO ERROR
				return (0);
			}
		}
		i++;
	}
	if (connections > 5 && hash_count == 4)
	{
		(*valid_count)++;
		//VALID TETRIMINO
		//ft_putstr("valid tetrimino\n");
		if (!add_to_list(buf, list, valid_count))
		{
			return (0);
		}
		return (1);
	}
	return (0);
}

int	check_connections(char buf[BUFF_SIZE], int i)
{
	int c;

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

int	add_to_list(char buf[BUFF_SIZE], t_list *list, int *valid_count)
{
	int		i;
	int		j;
	t_tetri	*temp;

	temp = (t_tetri *)malloc(sizeof(t_tetri));
	if (!temp)
		return (0);
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
					//temp->rule[k] = (j - i) % size;
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
	temp->count = *valid_count;
	temp->next = NULL;
	if (*(list->tail) == NULL)
	{
		*(list->tail) = temp;
		*(list->head) = temp;
	}
	else
	{
		(*(list->tail))->next = temp;
		*(list->tail) = temp;
	}
	return (1);
}
