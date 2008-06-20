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
 $Id: dclist_init.c,v 1.6 2006-01-29 19:24:13 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "dlist.h"
#include "dclist.h"
#include "dclist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_init.c,v 1.6 2006-01-29 19:24:13 harq_al_ada Exp $";

int
dclist_init (dclist_t * dclist, deallocator_t * dealloc)
{
  int rc = 0x0;

  assert (dclist != NULL);
  assert (dealloc != NULL);
  if (dclist == NULL || dealloc == NULL)
    {
      rc = EGAINVAL;
    }
  else
    {
      if ((*dclist = (dclist_t) malloc (sizeof (struct dclist_t))) == NULL)
        {
          rc = EGANOMEM;
        }
      else
        {
          if (((*dclist)->list_ = dlist_init (dealloc)) == NULL)
            {
              free (*dclist);
            }
          else
            {
              (*dclist)->signature_ = GA_DCLIST_SIGNATURE;
            }
        }
    }
  return rc;
}
