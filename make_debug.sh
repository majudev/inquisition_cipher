#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR
if ! [ -e bin ]; then
	mkdir bin
fi
if ! [ -e lib ]; then
	mkdir lib
fi
if ! [ -e obj ]; then
	mkdir obj
fi
FLAGS="-g -Wall -fPIC -Iinclude -D_DBG"
LIBS=""
g++ -c $FLAGS src/key.cpp -o obj/key.o
g++ -c $FLAGS src/class.cpp -o obj/class.o
g++ -c $FLAGS src/find.cpp -o obj/find.o
g++ -c $FLAGS src/4bit.cpp -o obj/4bit.o
g++ -c $FLAGS src/8bit.cpp -o obj/8bit.o
g++ -Wall -shared \
	obj/key.o\
	obj/class.o\
	obj/find.o\
	obj/4bit.o\
	obj/8bit.o\
	$LIBS \
	-o lib/libinquisition.so
TESTFLAGS="-Wall -g -Llib -linquisition -Iinclude $LIBS"
g++ \
	$TESTFLAGS \
	src/test.cpp \
	-o bin/inquisition
g++ \
	$TESTFLAGS \
	src/test2.cpp \
	-o bin/inquisition2
g++ \
	$TESTFLAGS \
	src/test3.cpp \
	-o bin/inquisition3
