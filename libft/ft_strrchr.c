/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:23:16 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/18 09:34:57 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*p;
	char	cc;
	int		i;

	p = (char *)s;
	cc = (char)c;
	if (!s && cc != '\0')
		return (p);
	len = ft_strlen(p);
	if (cc == '\0')
		return (&p[len]);
	i = len - 1;
	while (i >= 0)
	{
		if (p[i] == cc)
			return (&p[i]);
		i--;
	}
	return (NULL);
}
