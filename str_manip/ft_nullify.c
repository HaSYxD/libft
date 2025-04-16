/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasyxd <aliaudet@student.42lehavre.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:19:59 by hasyxd            #+#    #+#             */
/*   Updated: 2025/04/10 13:21:05 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *	ft_nullifyStr(char *str, const char c)
{
	for (int i = 0; str[i]; i++)
		if (str[i] == c)
			str[i] = 0;
	return (str);
}
