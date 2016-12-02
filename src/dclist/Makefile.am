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
# Intermediary makefile template to build the dclist subset of the
# library
# Project: G.A. Library
# Author: Daniel Costa Soares <daniel_csoares@yahoo.com.br>
# $Id: Makefile.am,v 1.4 2006-01-18 23:52:27 harq_al_ada Exp $
noinst_LTLIBRARIES = libdclist.la
libdclist_la_SOURCES = dclist_init.c			\
                      dclist_del.c				\
                      dclist_destroy.c			\
                      dclist_get.c				\
                      dclist_insert.c			\
                      dclist_move.c				\
	                  dclist_size.c				\
                      dclist_make_circular_.c	\
			          ../../include/dclist.h
AM_CPPFLAGS=-I../../include/
