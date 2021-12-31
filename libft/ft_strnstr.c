/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:23:04 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/24 15:05:45 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	char	*p;

	p = (char *)haystack;
	if (*needle == '\0')
		return (p);
	n_len = ft_strlen(needle);
	i = 0;
	while (p[i] != '\0' && i < len)
	{
		if (p[i] == needle[0] && n_len + i <= len)
		{
			if (ft_strncmp(&p[i], needle, n_len) == 0)
				return (&p[i]);
		}
		i++;
	}
	return (NULL);
}
