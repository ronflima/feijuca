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

 Description: Internal header file for lists implementation. This
 header file is internal and used only for the compilation of the
 library.

 CVS Information
 $Author: harq_al_ada $
 $Id: list_.h,v 1.4 2006-02-21 01:10:31 harq_al_ada Exp $
*/

#ifndef LIST__H
#define LIST__H

#include <stddef.h>
#include "gacommon.h"
#include "gainternal_.h"

GABEGINDECLS
/*
 * Constants
 */
enum
{
  GA_LIST_SIGNATURE=(ga_magic_t)0xFADEBAD1u
};

/*
 * Datatypes
 */
/* Abstraction for a single list element */
typedef struct list_element_t
{
  void *data_;
  struct list_element_t *next_;
}
list_element_t;

/* Abstraction for the list descriptor */
struct list_t
{
  size_t size_;                 /* List size */
  list_element_t *curr_;        /* Current navigation point */
  list_element_t *head_;        /* List head */
  list_element_t *tail_;        /* List tail */
  deallocator_t  *deallocator_; /* Deallocator function */
  ga_magic_t signature_;        /* Structure signature */
};

/*
 * Prototypes
 */
int (list_element_get_data_) __P((list_element_t *, void **));
int (list_element_set_data_) __P((list_element_t *, void * data));
int (list_element_get_next_) __P((list_element_t *, list_element_t **));
int (list_element_set_next_) __P((list_element_t *, list_element_t *));

GAENDDECLS
#endif /* LIST__H */
