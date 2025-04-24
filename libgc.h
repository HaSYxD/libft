/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:39:00 by aliaudet          #+#    #+#             */
/*   Updated: 2025/04/24 14:32:13 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_H
# define LIBGC_H

# include <stdlib.h>
# include <stdio.h>


typedef struct s_ptr
{
	struct s_ptr	*next;
	void			*data;
}	t_ptr;

typedef struct s_garb
{
	t_ptr	*alloc_ptr;
	size_t	blocks_num;
}	t_garb;

t_ptr	*add_to_collector(void *data, t_ptr *alloc_ptr);

void	*allocate(size_t size, t_garb *collector);
void	clean_garbage(t_garb *collector);
void	deallocate(void *ptr, t_garb *collector);
void *reallocate(size_t size, void *ptr, t_garb *collector);

#endif
