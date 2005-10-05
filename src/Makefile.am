# -*-makefile -*-
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.10 2005-10-05 12:18:31 daniel_csoares Exp $
SUBDIRS = list dlist clist ivector stack queue deque dclist
lib_LTLIBRARIES = libga.la
libga_la_SOURCES =
libga_la_LIBADD=list/liblist.la			\
	   	        dlist/libdlist.la		\
                clist/libclist.la		\
                ivector/libivector.la	\
                stack/libstack.la		\
				deque/libdeque.la		\
				dclist/libdclist.la		\
                queue/libqueue.la 
include_HEADERS = ../include/list.h			\
                  ../include/dlist.h		\
                  ../include/clist.h		\
                  ../include/ivector.h		\
                  ../include/stack.h		\
                  ../include/queue.h		\
				  ../include/deque.h		\
				  ../include/dclist.h		\
                  ../include/gacommon.h

