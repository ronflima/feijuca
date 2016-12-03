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
# Intermediary makefile template to build the fjc_stack subset of the
# library
# Project: G.A. Library
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: Makefile.am,v 1.5 2006-01-11 10:21:39 harq_al_ada Exp $
noinst_LTLIBRARIES = libfjc_stack.la
libfjc_stack_la_SOURCES = fjc_stack_init.c			\
                      fjc_stack_pop.c				\
                      fjc_stack_destroy.c			\
                      fjc_stack_push.c				\
	                  fjc_stack_size.c				\
                      ../../include/fjc_stack.h
AM_CPPFLAGS=-I../../include/
