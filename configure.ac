#                                               -*- Autoconf -*-
# Autoconf script for the project
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: configure.ac,v 1.17 2005-08-07 12:27:29 ron_lima Exp $

AC_PREREQ(2.57)
AC_INIT([ga-lib], [1.0.0], [ronaldo@ronaldolima.eti.br])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([include/list.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

# Creates conditionals for the library. This is used to let you
# compile the library without any optmization and with all debug
# information inside

# Create the ability to put debugging code into the library
AC_ARG_ENABLE(debug,
[  --enable-debug     Turn on debugging of the library],
[case "${enableval}" in
  yes) debug=true;;
  no) debug=false;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug);;
esac], [debug=false])
AM_CONDITIONAL(DEBUG, test x$debug = xtrue)
if test x$debug = xtrue; then
  AC_SUBST([CFLAGS], [-g])
else
  AC_SUBST([AM_CFLAGS], [-DNDEBUG])
fi

# Create the ability to profile the library
AC_ARG_ENABLE(profiling,
[  --enable-profiling     Turn on profiling of the library],
[case "${enableval}" in
  yes) profiling=true;;
  no) profiling=false;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-profiling);;
esac], [profiling=false])
AM_CONDITIONAL(DEBUG, test x$profiling = xtrue)
if test x$profiling = xtrue; then
  AC_SUBST([CFLAGS], [-pg])
else
  AC_SUBST([AM_CFLAGS], [-DNDEBUG])
fi

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/list/Makefile
                 src/dlist/Makefile
                 src/clist/Makefile
                 src/ivector/Makefile
                 src/stack/Makefile
                 src/queue/Makefile
                 src/deque/Makefile
                 doc/Makefile])

# Checks if the test suite exists in the source tree. If yes, create
# its makefile. Otherwise, just let it go.
if test -r src/testsuite/Makefile.am; then
   AC_CONFIG_FILES([src/testsuite/Makefile])
fi
AC_OUTPUT
