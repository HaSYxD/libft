/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:20:50 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/09 15:09:37 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_close(int n_args, ...)
{
	va_list	args;
	int	fd;

	va_start(args, n_args);
	for  (int i = 0; i < n_args; i++)
	{
		fd = va_arg(args, int);
		if (fd > 0)
			close(fd);
	}
}
