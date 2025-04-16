/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:00:46 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/09 13:42:36 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_cputptr_fd(const int fd, unsigned long long nbr, int *i)
{
	if (!nbr)
		ft_cputstr_fd(fd, "(nil)", i);
	else
	{
		ft_cputstr_fd(fd, "0x", i);
		ft_cputhexnbr_fd(fd, nbr, i, 'x');
	}
}

void	ft_cputhexnbr_fd(const int fd, unsigned long nbr, int *i, char type)
{
	if (nbr <= 15)
	{
		if (type == 'x')
			ft_cputchar_fd(fd, LOWERCASE[nbr], i);
		else if (type == 'X')
			ft_cputchar_fd(fd, UPPERCASE[nbr], i);
	}
	if (nbr > 15)
	{
		ft_cputhexnbr_fd(fd, nbr / 16, i, type);
		ft_cputhexnbr_fd(fd, nbr % 16, i, type);
	}
}
