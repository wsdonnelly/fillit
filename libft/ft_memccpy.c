/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:19:04 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/12 15:53:00 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	unsigned char	uc;

	uc = (unsigned char)c;
	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	while (n--)
	{
		if (*ps == uc)
		{
			*pd++ = uc;
			return (pd);
		}
		*pd++ = *ps++;
	}
	return (NULL);
}
