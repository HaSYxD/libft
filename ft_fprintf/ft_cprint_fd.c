/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:11:47 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/09 13:46:57 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_cputunsnbr_fd(const int fd, unsigned int nbr, int *i)
{
	if (nbr <= 9)
		ft_cputchar_fd(fd, '0' + nbr, i);
	if (nbr > 9)
	{
		ft_cputnbr_fd(fd, nbr / 10, i);
		ft_cputnbr_fd(fd, nbr % 10, i);
	}
}

void	ft_cputnbr_fd(const int fd, int nbr, int *i)
{
	if (nbr == -2147483648)
	{
		ft_cputstr_fd(fd, "-2147483648", i);
		return ;
	}
	if (nbr < 0)
	{
		ft_cputchar_fd(fd, '-', i);
		nbr *= -1;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_cputchar_fd(fd, '0' + nbr, i);
	}
	if (nbr > 9)
	{
		ft_cputnbr_fd(fd, nbr / 10, i);
		ft_cputnbr_fd(fd, nbr % 10, i);
	}
}

void	ft_cputstr_fd(const int fd, const char *str, int *i)
{
	if (!str)
	{
		write(fd, "(null)", 6);
		*i += 6;
		return ;
	}
	while (*str)
	{
		write(fd, &*str++, 1);
		++*i;
	}
}

void	ft_cputchar_fd(const int fd, char c, int *i)
{
	++*i;
	write(fd, &c, 1);
}
