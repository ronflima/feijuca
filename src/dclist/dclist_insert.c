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

 Description: Inserts a new element in the dclist given a position

 CVS Information
 $Author: harq_al_ada $
 $Id: dclist_insert.c,v 1.6 2006-01-26 10:18:13 harq_al_ada Exp $
*/
#include <assert.h>
#include "dclist.h"
#include "dclist_.h"
#include "gacommon.h"
#include "gainternal_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_insert.c,v 1.6 2006-01-26 10:18:13 harq_al_ada Exp $";

int
dclist_insert (dclist_t * dclist, const void *data, position_t whence)
{
  int rc = 0x0;

  assert (dclist != NULL);
  if (dclist == NULL)
    {
      return EGAINVAL;
    }

  CHECK_SIGNATURE (dclist, GA_DCLIST_SIGNATURE);

  if ((rc = dlist_insert (&dclist->list_, data, whence)) == 0x0)
    {
      /* Makes list circular again, since dlist_insert will ignore
       * this fact when operation on the head or tail. */
      dclist_make_circular_ (dclist);
    }
  return rc;
}
