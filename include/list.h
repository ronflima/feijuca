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

 Description: Interfaces and datatypes for single linked lists

 CVS Information
 $Author: ron_lima $
 $Id: list.h,v 1.3 2004-03-07 20:56:15 ron_lima Exp $
*/
 
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "gacommon.h"

/*
 * Datatypes
 */
/* Abstraction for a single list element */
typedef struct list_element_t
{
  void                  * data_;
  struct list_element_t * next_;
} LIST_ELEMENT;

/* Abstraction for the list descriptor */
typedef struct list_t
{
  size_t         size_;
  LIST_ELEMENT * curr_;
  LIST_ELEMENT * head_;
  LIST_ELEMENT * tail_;
  deallocator_t  deallocator_;
} LIST;

/* 
 * Prototypes 
 */
extern int
list_alloc (LIST ** list, deallocator_t dealloc);

extern int
list_free (LIST ** list);

extern int 
list_get (LIST * list, void **data, LIST_POSITION whence);

extern int 
list_insert (LIST * list, const void *data);

extern int
list_move (LIST * list, LIST_POSITION whence);

extern int
list_del (LIST * list, void **data);

#endif /* LIST_H */
