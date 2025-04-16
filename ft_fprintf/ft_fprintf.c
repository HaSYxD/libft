/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:54:19 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/09 13:53:17 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	get_type(const int fd, va_list args, char c, int *i)
{
	if (c == 'c')
		ft_cputchar_fd(fd, va_arg(args, int), i);
	else if (c == 's')
		ft_cputstr_fd(fd, va_arg(args, char *), i);
	else if (c == 'p')
		ft_cputptr_fd(fd, va_arg(args, unsigned long long), i);
	else if (c == 'd' || c == 'i')
		ft_cputnbr_fd(fd, va_arg(args, int), i);
	else if (c == 'u')
		ft_cputunsnbr_fd(fd, va_arg(args, unsigned int), i);
	else if (c == 'x' || c == 'X')
		ft_cputhexnbr_fd(fd, va_arg(args, unsigned int), i, c);
	else if (c == '%')
		ft_cputchar_fd(fd, '%', i);
}

int	ft_fprintf(const int fd, const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			get_type(fd, args, *(str + 1), &i);
			str++;
		}
		else
			ft_cputchar_fd(fd, *str, &i);
		str++;
	}
	return (i);
}
