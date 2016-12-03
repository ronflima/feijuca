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

#ifndef FJC_LIST__H
#define FJC_LIST__H

#include <stddef.h>
#include "fjc_common.h"
#include "fjc_list.h"

FJC_BEGINDECLS

/*
 * Datatypes
 */
/* Abstraction for a single list element */
struct fjc_list_element_t
{
  struct fjc_list_element_t *next_; /* Pointer to the next element of the list */
  const void *data_;                /* Encapsulated data inside the list element */
};
typedef struct fjc_list_element_t * fjc_list_element_t;

/* Abstraction for the list descriptor */
struct fjc_list_t
{
  size_t size_;                     /* List size */
  fjc_list_element_t curr_;         /* Current navigation point */
  fjc_list_element_t head_;         /* List head */
  fjc_list_element_t tail_;         /* List tail */
  fjc_deallocator_t  *deallocator_; /* Deallocator function */
};

FJC_ENDDECLS
#endif /* FJC_LIST_H */
