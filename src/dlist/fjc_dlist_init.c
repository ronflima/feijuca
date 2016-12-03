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
#include "fjc_dlist.h"
#include "fjc_dlist_.h"

fjc_dlist_t
fjc_dlist_init (fjc_deallocator_t * dealloc)
{
  fjc_dlist_t list = NULL;
  assert (dealloc != NULL);
  if ((list = (fjc_dlist_t) malloc (sizeof (struct fjc_dlist_t))) == NULL)
    {
      list = NULL;
    }
  else
    {
      /* Initializes each data member of the list descriptor */
      list->size_ = 0x0;
      list->head_ = (fjc_dlist_element_t) NULL;
      list->tail_ = (fjc_dlist_element_t) NULL;
      list->curr_ = (fjc_dlist_element_t) NULL;
      list->deallocator_ = dealloc;
    }
  return list;
}
