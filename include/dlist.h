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

 CVS Information
 $Author: harq_al_ada $
 $Id: dlist.h,v 1.20 2006-01-11 10:07:30 harq_al_ada Exp $
*/

#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>
#include "gacommon.h"

GABEGINDECLS
/*
 * Constants
 */
enum 
{
  GA_DLIST_SIGNATURE = (ga_magic_t)0xFADEBAD2u
};

/*
 * Datatypes
 */
/* Abstraction for a single list element */
typedef struct dlist_element_t
{
  void *data_;
  struct dlist_element_t *next_;
  struct dlist_element_t *prev_;
}
dlist_element_t;

/* Abstraction for the list descriptor */
typedef struct dlist_t
{
  size_t size_;                 /* List size */
  dlist_element_t *curr_;       /* Current navigation point */
  dlist_element_t *head_;       /* List head */
  dlist_element_t *tail_;       /* List tail */
  deallocator_t *deallocator_;  /* Deallocator routine for elements */
  ga_magic_t signature_;        /* Descriptor signature */
}
dlist_t;

/*
 * Prototypes
 */
int (dlist_init) __P ((dlist_t *, deallocator_t *));
int (dlist_destroy) __P ((dlist_t *));
int (dlist_get) __P ((dlist_t *, void **, position_t));
int (dlist_insert) __P ((dlist_t *, const void *, position_t));
int (dlist_move) __P ((dlist_t *, position_t));
int (dlist_del) __P ((dlist_t *, void **, position_t));
int (dlist_size) __P((dlist_t *, size_t *));

GAENDDECLS
#endif /* LIST_H */
