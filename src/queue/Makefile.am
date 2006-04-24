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
# Intermediary makefile template to build the queue subset of the
# library
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.6 2006-04-24 12:36:33 daniel_csoares Exp $
noinst_LTLIBRARIES = libqueue.la
libqueue_la_SOURCES = queue_init.c						\
                      queue_push.c						\
                      queue_destroy.c					\
                      queue_pop.c						\
                      descriptor/queue_get_size.c		\
                      descriptor/queue_is_valid_.c		\
                      descriptor/queue_get_list_.c 		\
                      ../../include/queue.h				\
                      ../../include/queue_.h
INCLUDES=-I../../include/
