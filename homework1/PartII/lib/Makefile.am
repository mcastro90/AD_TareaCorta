# whatever flags you want to pass to the C compiler & linker
AM_CFLAGS =-fPIC -shared
AM_LDFLAGS =-ldl

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
lib_LTLIBRARIES = libmemcheck.la
libmemcheck_la_SOURCES = libmemcheck.c
