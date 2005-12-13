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

 Description: Allocates and initializes the list

 CVS Information
 $Author: ron_lima $
 $Id: dlist_init.c,v 1.3 2005-12-13 10:18:52 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_init.c,v 1.3 2005-12-13 10:18:52 ron_lima Exp $";

int
dlist_init (dlist_t * list, deallocator_t * dealloc)
{
  /* Assertives for debugging purposes */
  assert (list != NULL);
  assert (dealloc != NULL);

  /* The deallocator must be always provided */
  if (!dealloc)
    {
      return EGAINVAL;
    }
  
  /* Initializes each data member of the list descriptor */
  list->size_ = 0x0;
  list->head_ = (dlist_element_t *) NULL;
  list->tail_ = (dlist_element_t *) NULL;
  list->curr_ = (dlist_element_t *) NULL;
  list->deallocator_ = dealloc;
  list->signature_ = GA_DLIST_SIGNATURE;
  
  return 0x0;
}
