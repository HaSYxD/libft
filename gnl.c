/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <afromont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:38:00 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 15:49:51 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean_stash(char *stash, arena_t *a)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	dst = arena_allocate(sizeof(char) * (ft_gnlstrlen(stash) - i + 1), a);
	if (!dst)
		return (NULL);
	i++;
	while (stash[i])
		dst[j++] = stash[i++];
	dst[j] = '\0';
	return (dst);
}

char	*extract_line(char *stash, arena_t *a)
{
	char	*dst;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	dst = arena_allocate(sizeof(char) * (i + 2), a);
	if (!dst)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		dst[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		dst[i] = stash[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*read_to_stash(int fd, char *stash, arena_t *a)
{
	char	*buff;
	int		rd_bytes;

	buff = arena_allocate(sizeof(char) * (GNL_BUFFER_SIZE + 1), a);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_gnlstrchr(stash, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, GNL_BUFFER_SIZE);
		if (rd_bytes == -1)
			return (NULL);
		buff[rd_bytes] = '\0';
		stash = ft_gnlstrjoin(stash, buff, a);
	}
	return (stash);
}

int	gnl(int fd, char **line, arena_t *a)
{
	static char	*stash;

	if (fd < 0 || GNL_BUFFER_SIZE <= 0)
		return (-1);
	stash = read_to_stash(fd, stash, a);
	if (!stash)
		return (0);
	*line = extract_line(stash, a);
	stash = clean_stash(stash, a);
	return (ft_strlen(*line));
}
