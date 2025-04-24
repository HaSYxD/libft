/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasyxd <aliaudet@student.42lehavre.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:36:49 by hasyxd            #+#    #+#             */
/*   Updated: 2025/04/24 03:12:26 by hasyxd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdlib.h>
# include <stdint.h>

# define ARENA_SMALL	(size_t)512
# define ARENA_MEDIUM	(size_t)4096
# define ARENA_LARGE	(size_t)32768
# define ARENA_HUGE	(size_t)262144

# define __ARENA_MAX_SIZEBLK	1024000
# define __ARENA_ERR_DICT	(char *[]){"", "[INIT ERROR]: block size must be a non-zero positive number", \
					"[INIT ERROR]: block size must be less than or equal to __ARENA_MAX_SIZEBLK", \
					"[ALLOC ERROR]: malloc failed to allocate some memory", \
					"[ALLOC ERROR]: allocation size must be a non-zero positive number", \
					"[ALLOC ERROR]: allocation size must be less than or equal to the defined _blksize", \
					"[ARGUMENT ERROR]: invalid arena pointer passed"}

extern uint8_t	g_arena_err;

enum	arena_err_e {
	NONE = 0,
	INITERR_TOSMALL,
	INITERR_TOBIG,
	ALLOCERR_MALLOCFAILED,
	ALLOCERR_TOSMALL,
	ALLOCERR_TOBIG,
	ARGERR_INVALIDARENA
};

typedef struct arenablk_s {
	struct arenablk_s *	_next;
	void *			_data;
	size_t			_capacity;
}	arenablk_t;

typedef struct arena_s {
	arenablk_t *	_blks;
	size_t		_blksize;
}	arena_t;

// Will return a pointer to an arena context
//
// This function takes a non-zero positive number that will determine the size of each block of the arena:
// 	arena_init(16);
// 	arena_init(1024);
//
// Defaults values are accessible:
// 	arena_init(ARENA_SMALL);
// 	arena_init(ARENA_MEDIUM);
// 	arena_init(ARENA_LARGE);
//
// The 'blksize' parameter cannot be bigger than __ARENA_MAX_SIZEBLK. It is not recommanded to change its value if you do not know what you are doing
//
// In case of error will return 'NULL' and set 'g_arena_err' to the corresponding error value
arena_t *	arena_init(const size_t blksize);

// Will return a pointer to the start of the requested memory plage
//
// The 'size' parameter cannot be bigger than the block size specified at the arena initialization
//
// In case of error will return 'NULL' and set 'g_arena_err' to the corresponding error value
void *	arena_allocate(const size_t size, arena_t *arena);

// Will erase all the memory held by the arena
//
// THIS WILL INVALIDATE EVERY POINTER ALLOCATED WITH THE ARENA AS WELL AS THE ARENA POINTER ITSELF
void	arena_destroy(arena_t *arena);

// Will return a string corresponding to the global variable 'g_arena_err'
//
// THIS IS NOT TIDED TO A SPECIFIC ARENA BUT TO THE WHOLE APPLICATION !! MULTIPLE ARENA CAN AFFECTE THE RESULT
char *	arena_geterrlog(const uint8_t err);

#endif
