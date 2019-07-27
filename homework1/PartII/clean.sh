#!/bin/sh

make clean

rm -rf aclocal.m4 autom4te.cache build-aux install-sh missing\
      depcomp config.log config.status configure compile\
      lib/Makefile lib/Makefile.in Makefile \
      Makefile.in src/Makefile src/Makefile.in \
      lib/libmemcheck.so src/memcheck src/memcheck.o \
      lib/libmemcheck.o src/.deps* lib/.deps* \
      output build config.* libtool ltmain.sh m4 log.txt
