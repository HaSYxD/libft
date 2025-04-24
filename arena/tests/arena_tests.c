# include "../../libft.h"

int	init_tests()
{
	// Argument error test
	arena_t *	test_zero_arena = arena_init(0);
	if (test_zero_arena != NULL) {
		ft_fprintf(2, "%sINIT TEST 1 FAILED%s\n", C_RED, C_DEFAULT);
		return (1);
	}
	ft_fprintf(1, "%sINIT TEST 1 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_t *	test_tobig_arena = arena_init(_ARENA_MAX_SIZEBLK + 1);
	if (test_tobig_arena != NULL) {
		ft_fprintf(2, "%sINIT TEST 2 FAILED%s\n", C_RED, C_DEFAULT);
		return (2);
	}
	ft_fprintf(1, "%sINIT TEST 2 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	
	// Normal init
	arena_t *	test_small_arena = arena_init(ARENA_SMALL);
	if (test_small_arena == NULL) {
		ft_fprintf(2, "%sINIT TEST 3 FAILED%s\n", C_RED, C_DEFAULT);
		return (3);
	}
	ft_fprintf(1, "%sINIT TEST 3 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_small_arena);
	arena_t *	test_medium_arena = arena_init(ARENA_MEDIUM);
	if (test_medium_arena == NULL) {
		ft_fprintf(2, "%sINIT TEST 4 FAILED%s\n", C_RED, C_DEFAULT);
		return (4);
	}
	ft_fprintf(1, "%sINIT TEST 4 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_medium_arena);
	arena_t *	test_large_arena = arena_init(ARENA_LARGE);
	if (test_large_arena == NULL) {
		ft_fprintf(2, "%sINIT TEST 5 FAILED%s\n", C_RED, C_DEFAULT);
		return (5);
	}
	ft_fprintf(1, "%sINIT TEST 5 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_large_arena);
	arena_t *	test_max_arena = arena_init(_ARENA_MAX_SIZEBLK);
	if (test_max_arena == NULL) {
		ft_fprintf(2, "%sINIT TEST 6 FAILED%s\n", C_RED, C_DEFAULT);
		return (6);
	}
	ft_fprintf(1, "%sINIT TEST 6 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_max_arena);
	return (0);
}

int	alloc_tests()
{
	// Argument error tests
	arena_t *	test_zero_alloc = arena_init(ARENA_SMALL);
	if (arena_allocate(0, test_zero_alloc) != NULL) {
		ft_fprintf(2, "%sALLOC TEST 1 FAILED%s\n", C_RED, C_DEFAULT);
		arena_destroy(test_zero_alloc);
		return (1);
	}
	ft_fprintf(1, "%sALLOC TEST 1 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_zero_alloc);
	arena_t *	test_tobig_alloc = arena_init(ARENA_SMALL);
	if (arena_allocate(test_tobig_alloc->_blksize + 1, test_tobig_alloc) != NULL) {
		ft_fprintf(2, "%sALLOC TEST 2 FAILED%s\n", C_RED, C_DEFAULT);
		arena_destroy(test_tobig_alloc);
		return (2);
	}
	ft_fprintf(1, "%sALLOC TEST 2 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_tobig_alloc);
	if (arena_allocate(64, NULL) != NULL) {
		ft_fprintf(2, "%sALLOC TEST 3 FAILED%s\n", C_RED, C_DEFAULT);
		return (3);
	}
	ft_fprintf(1, "%sALLOC TEST 3 SUCCESS%s\n", C_GREEN, C_DEFAULT);

	// Alloc test
	arena_t *	test_single_block = arena_init(ARENA_SMALL);
	arena_allocate(test_single_block->_blksize / 8, test_single_block);
	arena_allocate(test_single_block->_blksize / 8, test_single_block);
	arena_allocate(test_single_block->_blksize / 8, test_single_block);
	arena_allocate(test_single_block->_blksize / 8, test_single_block);
	if (arena_getblks_count(test_single_block) != 1) {
		ft_fprintf(2, "%sALLOC TEST 4 FAILED%s\n", C_RED, C_DEFAULT);
		arena_destroy(test_single_block);
		return (4);
	}
	ft_fprintf(1, "%sALLOC TEST 4 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_single_block);
	arena_t *	test_multiple_blocks = arena_init(ARENA_SMALL);
	arena_allocate(test_multiple_blocks->_blksize, test_multiple_blocks);
	arena_allocate(test_multiple_blocks->_blksize, test_multiple_blocks);
	arena_allocate(test_multiple_blocks->_blksize, test_multiple_blocks);
	arena_allocate(test_multiple_blocks->_blksize, test_multiple_blocks);
	if (arena_getblks_count(test_multiple_blocks) != 4) {
		ft_fprintf(2, "%sALLOC TEST 5 FAILED%s\n", C_RED, C_DEFAULT);
		arena_destroy(test_multiple_blocks);
		return (5);
	}
	ft_fprintf(1, "%sALLOC TEST 5 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_multiple_blocks);
	arena_t *	test_multiple_blocks2 = arena_init(ARENA_SMALL);
	arena_allocate(test_multiple_blocks2->_blksize / 2, test_multiple_blocks2);
	arena_allocate(test_multiple_blocks2->_blksize / 2, test_multiple_blocks2);
	arena_allocate(test_multiple_blocks2->_blksize / 2, test_multiple_blocks2);
	arena_allocate(test_multiple_blocks2->_blksize / 2, test_multiple_blocks2);
	if (arena_getblks_count(test_multiple_blocks2) != 2) {
		ft_fprintf(2, "%sALLOC TEST 6 FAILED%s\n", C_RED, C_DEFAULT);
		arena_destroy(test_multiple_blocks2);
		return (6);
	}
	ft_fprintf(1, "%sALLOC TEST 6 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_multiple_blocks2);
	arena_t *	test_max_from_one = arena_init(ARENA_SMALL);
	for (size_t i = 0; i < test_max_from_one->_blksize; i++)
		arena_allocate(1, test_max_from_one);
	if (arena_getblks_count(test_max_from_one) != 1) {
		ft_fprintf(2, "%sALLOC TEST 7 FAILED%s\n", C_RED, C_DEFAULT);
		arena_destroy(test_max_from_one);
		return (7);
	}
	ft_fprintf(1, "%sALLOC TEST 7 SUCCESS%s\n", C_GREEN, C_DEFAULT);
	arena_destroy(test_max_from_one);
	return (0);
}

int	main(void)
{
	int	init_err = init_tests();
	if (init_err != 0)
		return (ft_fprintf(2, "INIT: %d\n", init_err));

	int	alloc_err = alloc_tests();
	if (alloc_err != 0)
		return (ft_fprintf(2, "ALLOC: %d\n", alloc_err));
	return (0);
}
