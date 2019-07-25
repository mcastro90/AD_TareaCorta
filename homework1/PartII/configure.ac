#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([memcheck], [0.1], [g5@tec])
AC_CONFIG_SRCDIR([src/memcheck.c])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 lib/Makefile])

AC_OUTPUT

