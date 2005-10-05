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
 $Author: daniel_csoares $
 $Id: dclist_del.c,v 1.1 2005-10-05 12:19:19 daniel_csoares Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_del.c,v 1.1 2005-10-05 12:19:19 daniel_csoares Exp $";

int
dclist_del (dclist_t * list, void **data, position_t whence)
{
  int rc;
  assert (list != NULL);

  if (list->size_ == (size_t) 0x1)
    {
      /* Make list linear for deletion */
      list->head_->prev_ = NULL;
      list->tail_->next_ = NULL;
    }

  /* Delete element at a given position */
  rc = dlist_del ((dlist_t *) list, data, whence);
  if (rc)
    {
      return rc;
    }

  /* Make circular if deleted element is the head or tail */
  if ((list->head_ != NULL) && (list->head_->prev_ == NULL))
    {
      list->head_->prev_ = list->tail_;
    }
  if ((list->tail_ != NULL) && (list->tail_->next_ == NULL))
    {
      list->tail_->next_ = list->head_;
    }

  return 0x0;
}
