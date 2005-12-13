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

 Description: Interfaces and datatypes for queues

 CVS Information
 $Author: ron_lima $
 $Id: queue.h,v 1.10 2005-12-13 10:18:50 ron_lima Exp $
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "gacommon.h"
#include "list.h"

GABEGINDECLS
/*
 * Constants
 */
enum
{
  GA_QUEUE_SIGNATURE=(ga_magic_t)0xFADEDEADu
};

/*
 * Datatypes
 */
typedef struct queue_t
{
  ga_magic_t signature_;
  list_t list_;
} queue_t;

/*
 * Prototypes
 */
int (queue_init) __P ((queue_t *, deallocator_t *));
int (queue_destroy) __P ((queue_t *));
int (queue_pop) __P ((queue_t *, void **));
int (queue_push) __P ((queue_t *, const void *));

GAENDDECLS
#endif /* QUEUE_H */
