# -*-makefile -*-
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.2 2004-02-29 22:20:32 ron_lima Exp $
SUBDIRS = list dlist
lib_LTLIBRARIES = libga.la
libga_la_SOURCES =
libga_la_LIBADD=list/liblist.la					\
                dlist/libdlist.la
include_HEADERS = ../include/list.h				\
                  ../include/dlist.h			\
                  ../include/gacommon.h

