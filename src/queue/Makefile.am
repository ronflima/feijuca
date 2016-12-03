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
# Intermediary makefile template to build the fjc_queue subset of the
# library
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.7 2006-05-14 00:48:06 harq_al_ada Exp $
noinst_LTLIBRARIES = libfjc_queue.la
libfjc_queue_la_SOURCES = fjc_queue_init.c						\
                      fjc_queue_push.c						\
                      fjc_queue_destroy.c					\
                      fjc_queue_pop.c						\
                      descriptor/fjc_queue_get_size.c		\
                      descriptor/fjc_queue_is_valid_.c		\
                      descriptor/fjc_queue_get_list_.c 		\
                      descriptor/fjc_queue_set_list_.c      \
                      ../../include/fjc_queue.h				\
                      ../../include/fjc_queue_.h
AM_CPPFLAGS=-I../../include/
