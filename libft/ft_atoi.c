/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:48:05 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/19 17:13:14 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_wspace(const char *str, int *ip)
{
	while (str[*ip] == ' ' || str[*ip] == '\t' || str[*ip] == '\n' \
		|| str[*ip] == '\v' || str[*ip] == '\f' || str[*ip] == '\r')
		(*ip)++;
}

static void	get_sign(const char *str, int *ip, int *sp)
{
	if (str[*ip] == '-')
	{
		*sp = -1;
		(*ip)++;
	}
	else if (str[*ip] == '+')
		(*ip)++;
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	val;

	sign = 1;
	val = 0;
	i = 0;
	skip_wspace(str, &i);
	get_sign(str, &i, &sign);
	while (ft_isdigit((int)str[i]))
	{
		val = (val * 10) + str[i++] - '0';
		if (val > 9223372036854775807u && sign == 1)
			return (-1);
		else if (val > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)(val * sign));
}
