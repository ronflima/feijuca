# -*-makefile -*-
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.8 2004-05-03 00:25:07 ron_lima Exp $
SUBDIRS = list dlist clist ivector stack queue
lib_LTLIBRARIES = libga.la
libga_la_SOURCES =
libga_la_LIBADD=list/liblist.la			\
                dlist/libdlist.la		\
                clist/libclist.la		\
                ivector/libivector.la		\
                stack/libstack.la		\
                queue/libqueue.la 
include_HEADERS = ../include/list.h		\
                  ../include/dlist.h		\
                  ../include/clist.h		\
                  ../include/ivector.h		\
                  ../include/stack.h		\
                  ../include/queue.h		\
                  ../include/gacommon.h

