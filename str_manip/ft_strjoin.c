/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:49:09 by aliaudet          #+#    #+#             */
/*   Updated: 2025/05/01 16:59:25 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strjoin(const char *s1, const char *s2, alloc_ctx_t ctx)
{
	size_t	len = ft_strlen(s1) + ft_strlen(s2);
	char *	dst;
	int	i = 0;
	int	j = ft_strlen(s1);

	dst = alloc(sizeof(char) * (len + 1), ctx._allocptr, ctx._type);
	if (!dst)
		return (ft_fprintf(2, "ft_strjoin\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	dst[len] = '\0';
	while (s1[i]) {
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		dst[j++] = s2[i++];
	return (dst);
}
