/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:03:01 by aliaudet          #+#    #+#             */
/*   Updated: 2025/05/01 17:01:23 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *	ft_substr(const char *s, unsigned int start, size_t len, alloc_ctx_t ctx)
{
	unsigned int	i = 0;
	unsigned int	j = 0;
	char *		dst;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dst = alloc(sizeof(*s) * (len + 1), ctx._allocptr, ctx._type);
	if (!dst)
		return (ft_fprintf(2, "ft_substr:\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	while (s[i]) {
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
