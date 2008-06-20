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

 Description: Interfaces and datatypes for double-linked lists. Even
 being a specialization of single lists, the double-linked lists are
 being implemented as a brand new different kind of list.
*/

#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>
#include "gacommon.h"

GABEGINDECLS
/* Abstraction for the list descriptor */
typedef struct dlist_t *dlist_t;

/*
 * Prototypes
 */
dlist_t (dlist_init) __P ((deallocator_t *));
void (dlist_destroy) __P ((dlist_t));
const void *(dlist_get) __P ((dlist_t, position_t));
GAERROR (dlist_insert) __P ((dlist_t, const void *, position_t));
GAERROR (dlist_move) __P ((dlist_t, position_t));
GAERROR (dlist_del) __P ((dlist_t, void **, position_t));
size_t (dlist_size) __P ((dlist_t));

GAENDDECLS
#endif /* LIST_H */
