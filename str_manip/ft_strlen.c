/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <afromont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:48:22 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 16:14:33 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *str, const char c)
{
	size_t	i = 0;

	while (str[i] && str[i] != c)
		i++;
	return (i);
}

size_t	ft_strcount(char **s)
{
	size_t	i = 0;

	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
