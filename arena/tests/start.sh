#!/bin/bash
clang -Wall -Werror -Wextra -g arena_tests.c -I../ -I../../ -I../../ft_fprintf -L../../ -lft -o test

if [ "$1" = "-v" ]; then
	valgrind ./test
else
	valgrind --log-file=.memcheck.log ./test
fi
rm test
