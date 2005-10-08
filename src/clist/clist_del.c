/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Deletes the next element pointed by element

 CVS Information
 $Author: ron_lima $
 $Id: clist_del.c,v 1.9 2005-10-08 20:25:00 ron_lima Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_del.c,v 1.9 2005-10-08 20:25:00 ron_lima Exp $";

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
