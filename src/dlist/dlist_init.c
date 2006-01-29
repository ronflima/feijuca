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
 $Author: harq_al_ada $
 $Id: dlist_init.c,v 1.5 2006-01-29 19:24:13 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "dlist.h"
#include "dlist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_init.c,v 1.5 2006-01-29 19:24:13 harq_al_ada Exp $";

int
dlist_init (dlist_t * list, deallocator_t * dealloc)
{
  int rc = 0x0;

  /* Assertives for debugging purposes */
  assert (list != NULL);
  assert (dealloc != NULL);

  if (list == NULL || dealloc == NULL)
    {
      rc = EGAINVAL;
    }
  else
    {
      if ((*list = (dlist_t) malloc (sizeof (struct dlist_t))) == NULL)
        {
          rc = EGANOMEM;
        }
      else
        {
          /* Initializes each data member of the list descriptor */
          (*list)->size_ = 0x0;
          (*list)->head_ = (dlist_element_t *) NULL;
          (*list)->tail_ = (dlist_element_t *) NULL;
          (*list)->curr_ = (dlist_element_t *) NULL;
          (*list)->deallocator_ = dealloc;
          (*list)->signature_ = GA_DLIST_SIGNATURE;
        }
    }
      
  return rc;
}
