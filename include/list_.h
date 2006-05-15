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
 $Id: list_.h,v 1.8 2006-05-15 10:54:12 harq_al_ada Exp $
*/

#ifndef LIST__H
#define LIST__H

#include <stddef.h>
#include "gacommon.h"
#include "gainternal_.h"
#include "list.h"

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
struct list_element_t
{
  const void *data_;            /* Encapsulated data inside the list element */
  struct list_element_t *next_; /* Pointer to the next element of the list */
  deallocator_t *deallocator_;  /* Deallocator used to free the data member */
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
  ga_magic_t signature_;        /* Structure signature */
};

/*
 * Prototypes
 */
/* Element handling */
GAERROR (list_element_destroy_)  __P((list_element_t, deallocator_t *));
GAERROR (list_element_get_data_) __P((list_element_t, void **));
GAERROR (list_element_get_next_) __P((list_element_t, list_element_t *));
GAERROR (list_element_init_)     __P((list_element_t *, const void *));
GAERROR (list_element_set_data_) __P((list_element_t, void * data));
GAERROR (list_element_set_next_) __P((list_element_t, list_element_t));
/* List descriptor handling */
GAERROR (list_get_curr_) __P((list_t, list_element_t *));
GAERROR (list_get_deallocator_) __P((list_t, deallocator_t **));
GAERROR (list_get_head_) __P((list_t, list_element_t *));
GAERROR (list_get_tail_) __P((list_t, list_element_t *));
GAERROR (list_set_curr_) __P((list_t, list_element_t));
GAERROR (list_set_deallocator_) __P((list_t, deallocator_t));
GAERROR (list_set_head_) __P((list_t, list_element_t));
GAERROR (list_set_signature_) __P((list_t));
GAERROR (list_set_tail_) __P((list_t, list_element_t));
int (list_is_valid_) __P((list_t));

GAENDDECLS
#endif /* LIST__H */
