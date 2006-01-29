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
 $Id: dlist_.h,v 1.1 2006-01-29 19:24:13 harq_al_ada Exp $
*/

#ifndef DLIST__H
#define DLIST__H

#include <stddef.h>
#include "gacommon.h"
#include "gainternal_.h"

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
struct dlist_t
{
  size_t size_;                 /* List size */
  dlist_element_t *curr_;       /* Current navigation point */
  dlist_element_t *head_;       /* List head */
  dlist_element_t *tail_;       /* List tail */
  deallocator_t *deallocator_;  /* Deallocator routine for elements */
  ga_magic_t signature_;        /* Descriptor signature */
};

GAENDDECLS
#endif /* DLIST__H */
