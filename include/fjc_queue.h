/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This library is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as
 published by the Free Software Foundation; either version 2.1 of the
 License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
 USA

 System: G.A. Lib

 Description: Interfaces and datatypes for fjc_queues

 CVS Information
 $Author: daniel_csoares $
 $Id: fjc_queue.h,v 1.13 2006-04-24 12:36:13 daniel_csoares Exp $
*/

#ifndef FJC_QUEUE_H
#define FJC_QUEUE_H

#include <stddef.h>
#include "fjc_common.h"

FJC_BEGINDECLS
/*
 * Datatypes
 */
typedef struct fjc_queue_t * fjc_queue_t;

/*
 * Prototypes
 */
int (fjc_queue_init)     __P ((fjc_queue_t *, fjc_deallocator_t *));
int (fjc_queue_destroy)  __P ((fjc_queue_t));
int (fjc_queue_pop)      __P ((fjc_queue_t, void **));
int (fjc_queue_push)     __P ((fjc_queue_t, const void *));
int (fjc_queue_get_size) __P ((fjc_queue_t, size_t *));

FJC_ENDDECLS
#endif /* FJC_QUEUE_H */
