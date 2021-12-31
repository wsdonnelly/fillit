/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:21:49 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/24 15:03:07 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	size_t	n;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	n = dstsize;
	while (*dst)
	{
		if (n > 0)
			n--;
		dst++;
	}
	while (*src && n > 1)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	if (dstsize > len_dst)
		return (len_dst + len_src);
	return (dstsize + len_src);
}
