# -*-makefile -*-
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.9 2005-07-28 12:20:12 daniel_csoares Exp $
SUBDIRS = list dlist clist ivector stack queue deque
lib_LTLIBRARIES = libga.la
libga_la_SOURCES =
libga_la_LIBADD=list/liblist.la			\
                dlist/libdlist.la		\
                clist/libclist.la		\
                ivector/libivector.la		\
                stack/libstack.la		\
				deque/libdeque.la	\
                queue/libqueue.la 
include_HEADERS = ../include/list.h		\
                  ../include/dlist.h		\
                  ../include/clist.h		\
                  ../include/ivector.h		\
                  ../include/stack.h		\
                  ../include/queue.h		\
				  ../include/deque.h	\
                  ../include/gacommon.h

