/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:44:52 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/09 13:41:57 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UPPERCASE	"0123456789ABCDEF"
# define LOWERCASE	"0123456789abcdef"

void	ft_cputchar_fd(const int fd, char c, int *i);
void	ft_cputstr_fd(const int fd, const char *str, int *i);
void	ft_cputnbr_fd(const int fd, int nbr, int *i);
void	ft_cputunsnbr_fd(const int fd, unsigned int nbr, int *i);
void	ft_cputhexnbr_fd(const int fd, unsigned long nbr, int *i, char type);
void	ft_cputptr_fd(const int fd, unsigned long long nbr, int *i);

int	ft_fprintf(const int fd,const char *str, ...);

#endif
