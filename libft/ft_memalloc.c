/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:41:40 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/12 15:52:38 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*vp;

	if (size == 0)
		return (NULL);
	vp = malloc(size);
	if (vp == NULL)
		return (NULL);
	ft_bzero(vp, size);
	return (vp);
}
