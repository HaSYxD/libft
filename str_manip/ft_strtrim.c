/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:57:16 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 15:44:38 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strtrim(const char *s1, const char *set, alloc_ctx_t ctx)
{
	char *	dst;
	size_t	len = 0;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]))
		len--;
	dst = alloc(len + 1, ctx._allocptr, ctx._type);
	if (dst)
		ft_strlcpy(dst, s1, len + 1);
	return (dst);
}
