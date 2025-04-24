#!/bin/bash
clang -Wall -Werror -Wextra -g arena_tests.c -L../../ -lft -o test

if [ "$1" = "-v" ]; then
	valgrind ./test
else
	valgrind --log-file=.memcheck.log ./test
fi
rm test
