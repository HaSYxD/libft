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

# include "libft.h"

char *	clean_stash(char *stash, alloc_ctx_t ctx)
{
	char *	dst;
	int	i = 0;
	int	j = 0;

	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	dst = alloc(sizeof(char) * (ft_gnlstrlen(stash) - i + 1), ctx._allocptr, ctx._type);
	if (!dst)
		return (NULL);
	i++;
	while (stash[i])
		dst[j++] = stash[i++];
	dst[j] = '\0';
	return (dst);
}

char *	extract_line(char *stash, alloc_ctx_t ctx)
{
	char	*dst;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	dst = alloc(sizeof(char) * (i + 2), ctx._allocptr, ctx._type);
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

char *	read_to_stash(int fd, char *stash, alloc_ctx_t ctx)
{
	char *	buff;
	int	rd_bytes = 1;

	buff = alloc(sizeof(char) * (GNL_BUFFER_SIZE + 1), ctx._allocptr, ctx._type);
	if (!buff)
		return (NULL);
	while (!ft_gnlstrchr(stash, '\n') && rd_bytes != 0) {
		rd_bytes = read(fd, buff, GNL_BUFFER_SIZE);
		if (rd_bytes == -1)
			return (NULL);
		buff[rd_bytes] = '\0';
		stash = ft_gnlstrjoin(stash, buff, ctx);
	}
	return (stash);
}

int	gnl(int fd, char **line, alloc_ctx_t ctx)
{
	static char *	stash;

	if (fd < 0 || GNL_BUFFER_SIZE <= 0)
		return (-1);
	stash = read_to_stash(fd, stash, ctx);
	if (!stash)
		return (0);
	*line = extract_line(stash, ctx);
	stash = clean_stash(stash, ctx);
	return (ft_strlen(*line));
}
