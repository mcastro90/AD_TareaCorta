#!/usr/bin/bash

aclocal
automake --add-missing
autoconf
./configure --prefix=$PWD/build
make
make install
