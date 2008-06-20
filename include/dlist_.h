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

#ifndef DLIST__H
#define DLIST__H

#include <stddef.h>
#include "gacommon.h"

GABEGINDECLS
/*
 * Datatypes
 */
/* Abstraction for a single list element */
  struct dlist_element_t
{
  void *data_;
  struct dlist_element_t *next_;
  struct dlist_element_t *prev_;
};
typedef struct dlist_element_t * dlist_element_t;

/* Abstraction for the list descriptor */
struct dlist_t
{
  size_t size_;			/* List size */
  dlist_element_t curr_;	/* Current navigation point */
  dlist_element_t head_;	/* List head */
  dlist_element_t tail_;	/* List tail */
  deallocator_t *deallocator_;	/* Deallocator routine for elements */
};

GAENDDECLS
#endif /* DLIST__H */
