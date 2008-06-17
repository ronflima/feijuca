/* -*-c-*-
 Feijuca Library - A generic algorithms and data structures library Copyright
 (C) 2005 - Ronaldo Faria Lima

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

 System: Feijuca Library

 Description: Internal header file for lists implementation. This
 header file is internal and used only for the compilation of the
 library.
*/

#ifndef LIST__H
#define LIST__H

#include <stddef.h>
#include "gacommon.h"
#include "list.h"

GABEGINDECLS

/*
 * Datatypes
 */
/* Abstraction for a single list element */
struct list_element_t
{
  struct list_element_t *next_; /* Pointer to the next element of the list */
  const void *data_;            /* Encapsulated data inside the list element */
};
typedef struct list_element_t * list_element_t;

/* Abstraction for the list descriptor */
struct list_t
{
  size_t size_;                 /* List size */
  list_element_t curr_;         /* Current navigation point */
  list_element_t head_;         /* List head */
  list_element_t tail_;         /* List tail */
  deallocator_t  *deallocator_; /* Deallocator function */
};

GAENDDECLS
#endif /* LIST__H */
