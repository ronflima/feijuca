# -*-makefile -*
#
# Copyright (c) 2016 Ronaldo Faria Lima
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

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

#
# Test Suites
#

check_PROGRAMS=             \
testsuite/list_scenario_01  \
testsuite/list_scenario_02  \
testsuite/list_scenario_03  \
testsuite/clist_scenario_01

TESTS = $(check_PROGRAMS)
LDADD=libfjca.la

AM_CPPFLAGS=-I../include


