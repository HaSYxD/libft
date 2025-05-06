/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_domstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:55:11 by aliaudet          #+#    #+#             */
/*   Updated: 2025/05/01 16:53:43 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_aschar(const char *str)
{
	int	i = -1;

	while (str[++i])
		if (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '\t')
			return (1);
	return (0);
}

char *	ft_domstr(char *str, size_t start, size_t end, alloc_ctx_t ctx)
{
	char *	s1 = ft_substr(str, 0, start, ctx);
	char *	s2 = ft_substr(str, end, ft_strlen(str), ctx);

	if (!s1)
		return (ft_fprintf(2, "ft_domstr:\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	if (!s2)
		return (ft_fprintf(2, "ft_domstr:\n%s\n", arena_geterrlog(g_arena_err)), NULL);

	if (!ft_aschar(s1))
		return (s2);
	if (!ft_aschar(s2))
		return (s1);

	char *	out = ft_strjoin(s1, s2 , ctx);
	if (!out)
		return (ft_fprintf(2, "ft_domstr:\n%s\n", arena_geterrlog(g_arena_err)), NULL);

	return (out);
}
