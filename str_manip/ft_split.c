/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:55:44 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 15:48:33 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	get_splitstrs(const char *s, int start, int end, arena_t *a)
{
	char	*dst;
	int		i;

	dst = arena_allocate((end - start + 1) * sizeof(char), a);
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

char **	ft_split(const char *s, char c, arena_t *a)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		index;

	split = arena_allocate(sizeof(char *) * (ft_countw(s, c) + 1), a);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = get_splitstrs(s, index, i, a);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
