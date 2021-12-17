/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:24:01 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/17 09:41:00 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*p;
	size_t	len;

	p = (char *)haystack;
	if (*needle == '\0')
		return (p);
	len = ft_strlen(needle);
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == needle[0])
		{
			if (ft_strncmp(&p[i], needle, len) == 0)
				return (&p[i]);
		}
		i++;
	}
	return (NULL);
}
