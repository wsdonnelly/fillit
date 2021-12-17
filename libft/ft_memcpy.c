/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:19:34 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/19 17:10:49 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pd;
	char	*ps;

	if (!dst && !src && n > 0)
		return (NULL);
	pd = (char *)dst;
	ps = (char *)src;
	while (n--)
		*pd++ = *ps++;
	return (dst);
}
