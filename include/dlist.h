/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Interfaces and datatypes for double-linked lists. Even
 being a specialization of single lists, the double-linked lists are
 being implemented as a brand new different kind of list.

 CVS Information
 $Author: ron_lima $
 $Id: dlist.h,v 1.12 2004-10-13 10:51:04 ron_lima Exp $
*/

#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include "gacommon.h"

GABEGINDECLS
/*
 * Datatypes
 */
/* Abstraction for a single list element */
typedef struct dlist_element_t_
{
  void *                    data_;
  struct dlist_element_t_ * next_;
  struct dlist_element_t_ * prev_;
} dlist_element_t;

/* Abstraction for the list descriptor */
typedef struct dlist_t
{
  size_t            size_;
  dlist_element_t * curr_;
  dlist_element_t * head_;
  dlist_element_t * tail_;
  deallocator_t *   deallocator_;
} dlist_t;

/*
 * Prototypes
 */
int (dlist_alloc) __P((dlist_t **, deallocator_t *));
int (dlist_free) __P((dlist_t **));
int (dlist_get) __P((dlist_t *, void **, position_t));
int (dlist_insert) __P((dlist_t *, const void *, position_t));
int (dlist_move) __P((dlist_t *, position_t));
int (dlist_del) __P((dlist_t *, void **, position_t));

GAENDDECLS

#endif				/* LIST_H */
