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
*/
#include <assert.h>
#include <stdlib.h>
#include "dlist.h"
#include "dlist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id$";

dlist_t
dlist_init (deallocator_t * dealloc)
{
  dlist_t list = NULL;

  /* Assertives for debugging purposes */
  assert (dealloc != NULL);

  if ((list = (dlist_t) malloc (sizeof (struct dlist_t))) == NULL)
    {
      list = NULL;
    }
  else
    {
      /* Initializes each data member of the list descriptor */
      list->size_ = 0x0;
      list->head_ = (dlist_element_t) NULL;
      list->tail_ = (dlist_element_t) NULL;
      list->curr_ = (dlist_element_t) NULL;
      list->deallocator_ = dealloc;
    }

  return list;
}
