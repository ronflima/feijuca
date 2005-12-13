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

 Description: Interfaces and datatypes for single linked lists

 CVS Information
 $Author: ron_lima $
 $Id: list.h,v 1.21 2005-12-13 10:18:50 ron_lima Exp $
*/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "gacommon.h"

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
typedef struct list_t
{
  size_t size_;                 /* List size */
  list_element_t *curr_;        /* Current navigation point */
  list_element_t *head_;        /* List head */
  list_element_t *tail_;        /* List tail */
  deallocator_t  *deallocator_; /* Deallocator function */
  ga_magic_t signature_;        /* Structure signature */
}
list_t;

/*
 * Prototypes
 */
int (list_init) __P ((list_t *, deallocator_t *));
int (list_destroy) __P ((list_t *));
int (list_get) __P ((list_t *, void **, position_t));
int (list_insert) __P ((list_t *, const void *, position_t));
int (list_move) __P ((list_t *, position_t));
int (list_del) __P ((list_t *, void **));
int (list_reverse) __P((list_t *));

GAENDDECLS
#endif /* LIST_H */
