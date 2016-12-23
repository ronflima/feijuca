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

noinst_LTLIBRARIES = libqueue.la
libqueue_la_SOURCES = fjc_queue_init.c						\
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
