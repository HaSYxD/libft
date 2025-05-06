/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:57:02 by aliaudet          #+#    #+#             */
/*   Updated: 2025/05/01 17:00:37 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strdup(const char *s, alloc_ctx_t ctx)
{
	char *	dest;
	int	i = 0;

	while (s[i])
		i++;
	dest = alloc(sizeof(char) * (i + 1), ctx._allocptr, ctx._type);
	if (!dest)
		return (ft_fprintf(2, "ft_strdup:\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	i = 0;
	while (s[i]) {
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
