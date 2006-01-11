/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This is contributed code by Daniel Costa Soares
 <daniel_csoares@yahoo.com.br>

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

 Description: Allocates and initializes the dclist (Double-linked
 circular list)

 CVS Information
 $Author: harq_al_ada $
 $Id: dclist_init.c,v 1.4 2006-01-11 10:17:54 harq_al_ada Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dclist.h"
#include "dlist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_init.c,v 1.4 2006-01-11 10:17:54 harq_al_ada Exp $";

int
dclist_init (dclist_t * dclist, deallocator_t * dealloc)
{
  /* Assertives for debugging purposes */
  assert (dclist != NULL);
  assert (dealloc != NULL);
  if (dclist == NULL || dealloc == NULL)
    {
      return EGAINVAL;
    }
  dclist->signature_ = GA_DCLIST_SIGNATURE;
  return dlist_init (&dclist->list_, dealloc);
}
