# include "libft.h"
# include "libgc.h"

void *	alloc(const size_t size, void *allocptr, const alloc_type_t type)
{
	if (type == ARENA)
		return (arena_allocate(size, allocptr));
	else if (type == GARBAGE_COLLECTOR)
		return (allocate(size, allocptr));
	return (NULL);
}

void	dealloc(void *ptr, void *allocptr, const alloc_type_t type)
{
	if (type == ARENA)
		ft_fprintf(2, "Error: ARENA allocator type does not support deallocation");
	else if (type == GARBAGE_COLLECTOR)
		deallocate(ptr, allocptr);
}
