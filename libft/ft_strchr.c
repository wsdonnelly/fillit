/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:21:15 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/12 15:46:14 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*p;
	char			cc;

	cc = (char)c;
	p = (char *)s;
	i = 0;
	if (*p == '\0' && cc != '\0')
		return (NULL);
	if (cc == '\0')
		return (&p[ft_strlen(s)]);
	while (p[i] != cc && p[i] != '\0')
	{
		i++;
		if (p[i] == '\0')
			return (NULL);
	}
	return (&p[i]);
}
