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

 Description: Determines the size of a double linked-list

 CVS Information
 $Author: harq_al_ada $
 $Id: dclist_size.c,v 1.3 2006-01-29 19:24:13 harq_al_ada Exp $
*/
#include <stddef.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "dclist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_size.c,v 1.3 2006-01-29 19:24:13 harq_al_ada Exp $";

int
dclist_size (dclist_t dclist, size_t * size)
{
  assert (dclist != NULL);
  assert (size != NULL);
  if (dclist == NULL || size == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (dclist, GA_DCLIST_SIGNATURE);
  *size = dlist_size (dclist->list_);
  return EGAOK;
}
