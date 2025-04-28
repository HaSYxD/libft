/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasyxd <aliaudet@student.42lehavre.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:45:39 by hasyxd            #+#    #+#             */
/*   Updated: 2025/04/28 16:26:53 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <arena.h>

uint8_t	g_arena_err = NONE;

static void *	__arena_return_err(const uint8_t err)
{
	g_arena_err = err;
	return (NULL);
}

arena_t *	arena_init(const size_t blksize)
{
	// Check for user input error
	if (blksize == 0)
		return __arena_return_err(INITERR_TOSMALL);
	if (blksize > _ARENA_MAX_SIZEBLK)
		return __arena_return_err(INITERR_TOBIG);

	// Allocate the Arena funtion pointer
	arena_t *	arena = malloc(sizeof(arena_t));
	if (arena == NULL)
		return __arena_return_err(ALLOCERR_MALLOCFAILED);

	// Allocate the arena first block pointer
	arena->_blksize = blksize;
	arena->_blks = malloc(sizeof(P_arenablk_t));
	if (arena->_blks == NULL) {
		free(arena);
		return __arena_return_err(ALLOCERR_MALLOCFAILED);
	}

	// Allocate the block data
	arena->_blks->_next = NULL;
	arena->_blks->_capacity = 0;
	arena->_blks->_data = malloc(blksize);
	if (arena->_blks->_data == NULL) {
		free(arena->_blks);
		free(arena);
		return __arena_return_err(ALLOCERR_MALLOCFAILED);
	}

	return (arena);
}

void *		arena_allocate(const size_t size, arena_t *arena)
{
	// Check for user input error
	if (arena == NULL)
		return __arena_return_err(ARGERR_INVALIDARENA);
	if (size == 0)
		return __arena_return_err(ALLOCERR_TOSMALL);
	if (size > arena->_blksize)
		return __arena_return_err(ALLOCERR_TOBIG);

	P_arenablk_t *	start = arena->_blks;
	void *		allocptr = NULL;
	
	while (arena->_blks) {
		size_t	free_mem = arena->_blksize - arena->_blks->_capacity;
		if (arena->_blks->_next == NULL && size > free_mem) {
			arena->_blks->_next = malloc(sizeof(P_arenablk_t));
			if (arena->_blks->_next == NULL) {
				arena->_blks = start;
				return __arena_return_err(ALLOCERR_MALLOCFAILED);
			}
			arena->_blks->_next->_data = malloc(arena->_blksize);
			if (arena->_blks->_next->_data == NULL) {
				free(arena->_blks->_next);
				arena->_blks->_next = NULL;
				arena->_blks = start;
				return __arena_return_err(ALLOCERR_MALLOCFAILED);
			}
			allocptr = arena->_blks->_next->_data + size;
			arena->_blks->_next->_capacity = size;
			arena->_blks->_next->_next = NULL;
			break ;
		}
		else if (size <= free_mem) {
			allocptr = arena->_blks->_data + arena->_blks->_capacity;
			arena->_blks->_capacity += size;
			break ;
		}
		arena->_blks = arena->_blks->_next;
	}
	arena->_blks = start;
	return (allocptr);
}

void		arena_destroy(arena_t *arena)
{
	if (arena == NULL)
		return (void)__arena_return_err(ARGERR_INVALIDARENA);

	while (arena->_blks) {
		P_arenablk_t *	next = arena->_blks->_next;
		
		free(arena->_blks->_data);
		free(arena->_blks);
		arena->_blks = next;
	}
	free(arena);
}

char *	arena_geterrlog(const uint8_t err)
{
	return (_ARENA_ERR_DICT[err]);
}

size_t	arena_getblks_count(arena_t *arena)
{
	P_arenablk_t *	begin = arena->_blks;
	size_t		count = 0;

	while (arena->_blks) {
		count++;
		arena->_blks = arena->_blks->_next;
	}
	arena->_blks = begin;
	return (count);
}
