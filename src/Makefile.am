# -*-makefile -*-
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.3 2004-03-30 11:29:41 ron_lima Exp $
SUBDIRS = list dlist clist
lib_LTLIBRARIES = libga.la
libga_la_SOURCES =
libga_la_LIBADD=list/liblist.la			\
                dlist/libdlist.la		\
                clist/libclist.la
include_HEADERS = ../include/list.h		\
                  ../include/dlist.h		\
                  ../include/clist.h		\
                  ../include/gacommon.h

