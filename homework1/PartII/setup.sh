#!/bin/sh

libtoolize
aclocal
automake --add-missing
autoconf
./configure --prefix=$PWD/build
make
make install
