/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <afromont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:24 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 16:18:54 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE	16
# endif

// SYSTEM INCLUDES
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>

// LIBRARY MODULES
# include "arena/arena.h"
# include "ft_fprintf/ft_fprintf.h"

typedef struct s_list {
	struct s_list *	next;
	void *		data;
}	t_list;

t_list *	ft_lstlast(t_list *lst);
t_list *	ft_lstnew(arena_t *a, void *data);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);

double	ft_gettime(void);

size_t	ft_gnlstrlen(const char *str);
char *	ft_gnlstrjoin(char *s1, char *s2, arena_t *a);
char *	ft_gnlstrchr(char *str, int c);
int	gnl(int fd, char **line, arena_t *a);

void *	ft_bzero(void *s, size_t n);
void *	ft_memset(void *s, int c, size_t n);
void *	ft_memcpy(void *dest, const void *src, size_t n);
void *	ft_memchr(const void *s, int c, size_t n);
void *	ft_memmove(void *dest, const void *src, size_t n);
void *	ft_calloc(size_t nmemb, size_t size);
void	ft_close(int n_args, ...);
void	ft_free(void *ptr);

size_t	ft_strinstcount(const char *str, const char c);
size_t	ft_strlenc(const char *str, const char c);
size_t	ft_strcount(char **s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char **	ft_split(const char *s, char c, arena_t *a);
char *	ft_nullifyStr(char *str, const char c);
char *	ft_domstr(char *str, size_t start, size_t end, arena_t *a);
char *	ft_strnstr(const char *big, const char *little, size_t len);
char *	ft_strdup(const char *s, arena_t *a);
char *	ft_strchr(const char *str, int c);
char *	ft_strrchr(const char *str, int c);
char *	ft_substr(const char *s, unsigned int start, size_t len, arena_t *a);
char *	ft_strmapi(const char *s, char (*f)(unsigned int, char));
char *	ft_strjoin(const char *s1, const char *s2, arena_t *a);
char *	ft_itoa(int n, arena_t *a);
char *	ft_strtrim(const char *s1, const char *set, arena_t *a);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_countw(const char *s, char c);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_atoi(const char *str);

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
//-int	ft_ptoi(char **str);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
