/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:20:42 by wdonnell          #+#    #+#             */
/*   Updated: 2021/11/18 15:23:57 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_start_end(char const *s, unsigned int *start, unsigned int *end)
{
	*start = 0;
	while ((s[*start] == ' ' || s[*start] == '\n' \
	|| s[*start] == '\t') && s[*start] != '\0')
		(*start)++;
	*end = (unsigned int)ft_strlen(s);
	if (*start == *end)
		return ;
	(*end)--;
	while (s[*end] == ' ' || s[*end] == '\n' \
	|| s[*end] == '\t')
		(*end)--;
}

char	*ft_strtrim(char const *s)
{
	char			*new;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	if (!s)
		return (NULL);
	set_start_end(s, &start, &end);
	new = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start) + 1)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
