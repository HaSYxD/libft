/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:44:52 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 14:32:25 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# ifndef C_DEFAULT
#  define C_DEFAULT	"\033[0m"
# endif
# ifndef C_RED
#  define C_RED		"\033[0;31m"
# endif
# ifndef C_GREEN
#  define C_GREEN	"\033[0;32m"
# endif
# ifndef C_YELLOW
#  define C_YELLOW	"\033[0;33m"
# endif
# ifndef C_CYAN
#  define C_CYAN	"\033[0;36m"
# endif

# ifndef DEBUG
#  define DEBUG	0
# endif
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
