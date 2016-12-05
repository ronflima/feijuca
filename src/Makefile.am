# -*-makefile-*-
#
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
# Makefile that handles intermediate libraries generation
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.16 2006-01-29 20:03:12 harq_al_ada Exp $
SUBDIRS = list dlist clist ivector stack queue deque dclist
lib_LTLIBRARIES = libfjca.la
libfjca_la_SOURCES =

libfjca_la_LIBADD=list/liblist.la	\
dlist/libdlist.la					\
clist/libclist.la					\
ivector/libivector.la				\
stack/libstack.la					\
deque/libdeque.la					\
dclist/libdclist.la					\
queue/libqueue.la 

include_HEADERS = ../include/fjc_list.h	\
../include/fjc_dlist.h					\
../include/fjc_clist.h					\
../include/fjc_ivector.h				\
../include/fjc_stack.h					\
../include/fjc_queue.h					\
../include/fjc_deque.h					\
../include/fjc_dclist.h					\
../include/fjc_common.h

noinst_HEADERS=../include/fjc_dclist_.h	\
../include/fjc_deque_.h					\
../include/fjc_dlist_.h					\
../include/fjc_ivector_.h				\
../include/fjc_list_.h					\
../include/fjc_queue_.h					\
../include/fjc_stack_.h



