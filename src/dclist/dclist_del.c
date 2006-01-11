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
 $Id: dclist_del.c,v 1.4 2006-01-11 10:16:26 harq_al_ada Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_del.c,v 1.4 2006-01-11 10:16:26 harq_al_ada Exp $";

int
dclist_del (dclist_t * dclist, void **data, position_t whence)
{
  int rc;
  assert (dclist != NULL);

  if (dclist == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (dclist, GA_DCLIST_SIGNATURE);
  if (dclist->list_.size_ == (size_t) 0x1)
    {
      /* Make list linear for deletion */
      dclist->list_.head_->prev_ = NULL;
      dclist->list_.tail_->next_ = NULL;
    }

  if ((rc = dlist_del (&dclist->list_, data, whence)) != 0x0)
    {
      return rc;
    }

  /* Make circular if deleted element is the head or tail */
  if ((dclist->list_.head_ != NULL) && (dclist->list_.head_->prev_ == NULL))
    {
      dclist->list_.head_->prev_ = dclist->list_.tail_;
    }
  if ((dclist->list_.tail_ != NULL) && (dclist->list_.tail_->next_ == NULL))
    {
      dclist->list_.tail_->next_ = dclist->list_.head_;
    }

  return 0x0;
}
