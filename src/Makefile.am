# -*-makefile -*-
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.4 2004-04-04 11:13:53 ron_lima Exp $
SUBDIRS = list dlist clist ivector
lib_LTLIBRARIES = libga.la
libga_la_SOURCES =
libga_la_LIBADD=list/liblist.la			\
                dlist/libdlist.la		\
                clist/libclist.la
include_HEADERS = ../include/list.h		\
                  ../include/dlist.h		\
                  ../include/clist.h		\
                  ../include/ivector.h          \
                  ../include/gacommon.h

