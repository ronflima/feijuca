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
# Intermediary makefile template to build the dlist subset of the
# library
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>

noinst_LTLIBRARIES = libdlist.la
libdlist_la_SOURCES = fjc_dlist_init.c				\
                      fjc_dlist_del.c				\
                      fjc_dlist_destroy.c			\
                      fjc_dlist_get.c				\
                      fjc_dlist_insert.c			\
                      fjc_dlist_move.c				\
                      fjc_dlist_size.c				\
                      ../../include/fjc_dlist.h
AM_CPPFLAGS=-I../../include/
