/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:55:44 by aliaudet          #+#    #+#             */
/*   Updated: 2025/05/01 16:57:17 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	get_splitstrs(const char *s, int start, int end, alloc_ctx_t ctx)
{
	char	*dst;
	int	i = 0;

	dst = alloc((end - start + 1) * sizeof(char), ctx._allocptr, ctx._type);
	if (!dst)
		return (ft_fprintf(2, "ft_split:\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	while (start < end)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

char **	ft_split(const char *s, char c, alloc_ctx_t ctx)
{
	char **	split;
	size_t	i = 0;
	size_t	j = 0;
	int	index = -1;

	split = alloc(sizeof(char *) * (ft_countw(s, c) + 1), ctx._allocptr, ctx._type);
	if (!split)
		return (ft_fprintf(2, "ft_split:\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	while (i <= ft_strlen(s)) {
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0) {
			split[j++] = get_splitstrs(s, index, i, ctx);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
