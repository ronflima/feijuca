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

 Description: Deletes an element given a position

 CVS Information
 $Author: harq_al_ada $
 $Id: dclist_del.c,v 1.7 2006-01-29 19:24:13 harq_al_ada Exp $
*/
#include <assert.h>
#include "dclist.h"
#include "dclist_.h"
#include "dlist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_del.c,v 1.7 2006-01-29 19:24:13 harq_al_ada Exp $";

int
dclist_del (dclist_t dclist, void **data, position_t whence)
{
  int rc = 0x0;
  assert (dclist != NULL);

  if (dclist == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (dclist, GA_DCLIST_SIGNATURE);

  if (dclist->list_->size_ > 0x0)
    {
      dclist->list_->head_->prev_ = NULL;
      dclist->list_->tail_->next_ = NULL;
    }
  if ((rc = dlist_del (dclist->list_, data, whence)) == 0x0)
    {
      dclist_make_circular_ (dclist);
    }

  return rc;
}
