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

 Description: Deletes an element given a position

 CVS Information
 $Author: ron_lima $
 $Id: dclist_del.c,v 1.2 2005-10-08 20:25:00 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_del.c,v 1.2 2005-10-08 20:25:00 ron_lima Exp $";

int
dclist_del (dclist_t * dclist, void **data, position_t whence)
{
  int rc;
  assert (dclist != NULL);

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
