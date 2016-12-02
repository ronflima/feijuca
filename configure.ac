#                                               -*- Autoconf -*-
# Feijuca - A generic algorithms and data structures library
# Copyright (C) 2005 - Ronaldo Faria Lima
#
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
# USA
#
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: configure.ac,v 1.21 2006-02-04 16:06:42 harq_al_ada Exp $

AC_PREREQ(2.57)
AC_INIT([feijuca], [1.0.0], [ronaldo@ronaldolima.eti.br])
AM_INIT_AUTOMAKE([subdir-objects])
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
[  --enable-debug          Turn on debugging of the library],
[case "${enableval}" in
  yes) debug=true;;
  no) debug=false;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug);;
esac], [debug=false])
AM_CONDITIONAL(DEBUG, test x$debug = xtrue)
if test x$debug = xtrue; then
  AC_SUBST([CFLAGS], [-g])
else
  AC_SUBST([CFLAGS], [-DNDEBUG])
fi

# Disable assertions for debugging purposes
AC_ARG_ENABLE(assertions,
[  --disable-assertions    Disable assertions in the code],
[case "${enableval}" in
  no) assertions=true;;
  yes) assertions=false;;
  *) AC_MSG_ERROR(bad value ${enableval} for --disable-assertions);;
esac], [assertions=false])
AM_CONDITIONAL(DEBUG, test x$assertions = xtrue)
if test x$assertions = xtrue; then
  AC_SUBST([CFLAGS], [-DNDEBUG])
fi

# Create the ability to profile the library
AC_ARG_ENABLE(profiling,
[  --enable-profiling      Turn on profiling of the library],
[case "${enableval}" in
  yes) profiling=true;;
  no) profiling=false;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-profiling);;
esac], [profiling=false])
AM_CONDITIONAL(DEBUG, test x$profiling = xtrue)
if test x$profiling = xtrue; then
  AC_SUBST([CFLAGS], [-pg])
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
                 src/dclist/Makefile
                 doc/Makefile])

# Checks if the test suite exists in the source tree. If yes, create
# its makefile. Otherwise, just let it go.
if test -r src/testsuite/Makefile.am; then
   AC_CONFIG_FILES([src/testsuite/Makefile])
fi
AC_OUTPUT
