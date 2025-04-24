/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:03:01 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 15:45:08 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *	ft_substr(const char *s, unsigned int start, size_t len, arena_t *a)
{
	unsigned int	i;
	unsigned int	j;
	char			*dst;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dst = arena_allocate(sizeof(*s) * (len + 1), a);
	i = 0;
	j = 0;
	if (!dst)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
