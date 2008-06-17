# -*-makefile-*-
#
# Feijuca Library - A generic algorithms and data structures library
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
# Makefile template for the test suite
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# (c) 2004 - All rights reserved
#
noinst_PROGRAMS = fjtest
fjtest_SOURCES = gatests.h						\
                 list.c							\
                 dlist.c						\
                 stack.c						\
                 clist.c						\
                 queue.c						\
                 ivector.c						\
		 deque.c						\
                 engine.c						\
		 dclist.c						\
                 testsuite.c
AM_CPPFLAGS=-I./ -I../../include
AM_CFLAGS=$(CFLAGS)
AM_LDFLAGS=-static -lfjca -L../

