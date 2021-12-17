/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:32:16 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/19 10:18:39 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char	*str_rev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

static void	fill_num(char *num, int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		num[0] = '0';
		return ;
	}
	while (n)
	{
		num[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	num[i] = '\0';
}

static void	fill_min(char *num)
{
	int		i;
	char	*min;

	min = "-2147483648";
	i = 0;
	while (i < 11)
	{
		num[i] = min[i];
		i++;
	}
}

char	*ft_itoa(int n)
{
	char			*num;
	int				sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	num = malloc(sizeof(char) * size(n) + 1);
	if (num == NULL)
		return (NULL);
	ft_bzero(num, (sizeof(char) * size(n) + 1));
	if (n == -2147483648)
	{
		fill_min(num);
		return (num);
	}
	n *= sign;
	fill_num(num, n);
	if (sign == -1)
		num[size(n)] = '-';
	return (str_rev(num));
}
