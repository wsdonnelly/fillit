#include "fillit.h"

t_list	*readin(char *file, t_list **head)
{
	int fd;
	ssize_t	ret;
	char buf[BUFF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		//OPEN ERROR
		ft_putstr("open error\n");
		return (0);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			// READ ERROR
			ft_putstr("read error\n");
			return (0);
		}
		buf[ret] = '\0';
		if ((ret == BUFF_SIZE && buf[20] != '\n') || (ret == 18 && buf[19] != '\0'))
		//if (ret < BUFF_SIZE || (buf[20] != '\n'))
		{
			//INVALID TETRIMINO ERROR
			ft_putstr("invalid tetrimino1\n");
			return (0);
		}
		if (!validate(buf, head))
		{
			//TETRIMINO ERROR
			ft_putstr("invalid tetrimino2\n");
			return (0);
		}
	}
	ft_putstr("valid file!\n");
	close (fd);
	return (*head);
}

int	validate(char buf[BUFF_SIZE], t_list **head)
{
	int	i;
	int hash_count;
	int connections;

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
				ft_putstr("error here 1\n");
				return (0);
			}
			if (buf[i] == '#')
				hash_count++;
		}
		else
		{
			if (buf[i] != '\n' && buf[i] != '\0')
			{
				//TETRIMINO ERROR
				ft_putstr("error here 2\n");
				return (0);
			}
		}
		connections += check_connections(buf, i);
		i++;
	}
	if (connections > 5 && hash_count == 4)
	{
		//VALID TETRIMINO
		ft_putstr("valid tetrimino\n");
		if (!add_to_list(buf, head))
		{
			//MALLOC ERROR
			ft_putstr("malloc error\n");
			return (0);
		}
		return (1);
	}
	return (0);
}

int check_connections(char buf[BUFF_SIZE], int i)
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

int add_to_list(char buf[BUFF_SIZE], t_list **head)
{
	int		i;
	int		j;
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (0);
	i = 0;
	j = 0;
	while (i < 19)
	{
		if (i % 5 != 4)
			temp->tetri[j++] = buf[i];
		i++;
	}
	temp->next = *head;
	*head = temp;
	return (1);
}
