#!/bin/bash

if [ $# == 0 ]
then
	echo "Compiling for default platform 'DESKTOP'"
	echo "To specify another platform add the argument 'PLATFORM=<platform>'"
	echo "Currently supported plarforms are 'DESKTOP', 'WEB'"
	make CC=clang AR=ar NAME=libft-desktop.a
	exit 0
fi

if [ $# == 1 ] && [ $1 == "PLATFORM=WEB" ]
then
	echo "Compiling for default platform 'WEB'"
	make CC=emcc AR=emar NAME=libft-web.a
elif [ $# == 1 ] && [ $1 == "PLATFORM=DESKTOP" ]
then
	echo "Compiling for default platform 'DESKTOP'"
	make CC=clang AR=ar NAME=libft-desktop.a
fi
