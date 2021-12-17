/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:20:08 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/17 09:40:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	size_t				i;

	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	if ((!dst && !src))
		return (NULL);
	i = 0;
	if (dp < sp)
	{
		while (i < len)
		{
			dp[i] = sp[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			dp[len] = sp[len];
	}
	return (dst);
}
