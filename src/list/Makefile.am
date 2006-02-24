# -*-makefile-*-
#
# G.A. Library - A generic algorithms and data structures library
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
# Intermediary makefile template to build the list subset of the
# library
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.10 2006-02-24 10:35:57 harq_al_ada Exp $
noinst_LTLIBRARIES = liblist.la
liblist_la_SOURCES = list_init.c						\
                     list_del.c							\
                     list_destroy.c						\
                     list_get.c							\
                     list_insert.c						\
                     list_move.c						\
                     list_reverse.c						\
                     list_size.c						\
			         list_getpos.c						\
                     elements/list_element_init_.c		\
                     elements/list_element_destroy_.c	\
					 elements/list_element_get_data_.c	\
                     elements/list_element_get_next_.c	\
                     elements/list_element_set_data_.c	\
                     elements/list_element_set_next_.c	\
                     ../../include/list.h
INCLUDES=-I../../include/
