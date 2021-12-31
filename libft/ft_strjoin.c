/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:35:38 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/18 14:30:20 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join(char *new, char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	join(new, s1, s2);
	return (new);
}
