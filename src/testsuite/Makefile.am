#
# Makefile template for the test suite
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# (c) 2004 - All rights reserved
#
noinst_PROGRAMS = gatest
gatest_SOURCES = gatests.h			\
                 list.c				\
                 dlist.c                        \
		 stack.c                        \
                 testsuite.c
AM_CPPFLAGS=-I./ -I../../include
AM_CFLAGS=$(CFLAGS)
AM_LDFLAGS=-lga -L../

