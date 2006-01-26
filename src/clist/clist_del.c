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

 Description: Deletes the next element pointed by element

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_del.c,v 1.11 2006-01-26 10:18:13 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"
#include "gainternal_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_del.c,v 1.11 2006-01-26 10:18:13 harq_al_ada Exp $";

int
clist_del (clist_t * clist, void **data)
{
  assert (clist != NULL);
  CHECK_SIGNATURE (clist, GA_CLIST_SIGNATURE);

  /* Check if we are deleting the head of the list */
  if (!clist->list_.curr_ || clist->list_.curr_ == clist->list_.head_)
    {
      /* Adjusts the tail to point to the next item pass the head */
      clist->list_.tail_->next_ = clist->list_.head_->next_;
    }
  /* Check if we are currently in the tail of the list */
  if (clist->list_.curr_ == clist->list_.tail_)
    {
      /* Adjusts the head, since the tail has as its next the head of
       * the list */
      clist->list_.head_ = clist->list_.head_->next_;
    }

  return list_del (&clist->list_, data);
}
